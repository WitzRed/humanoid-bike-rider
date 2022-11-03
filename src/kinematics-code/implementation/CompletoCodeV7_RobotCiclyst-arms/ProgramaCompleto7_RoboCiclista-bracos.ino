// Algorítimo principal
#include<avr/wdt.h>
#include <SPI.h>
#include "RF24.h"
#include<I2Cdev.h>
#include "MPU6050.h"
#include<Wire.h>
#include<Servo.h>
#include "config.h"
#include "variaveis.h"
#include "movimentos.h"
#include "parada.h"

MPU6050 accelgyro;
RF24 moduloRF(9, 10);

const uint64_t tubo = 0x034f30aaf8LL;

void setup() {
  // put your setup code here, to run once:
  
  Wire.begin();
  
  Serial.begin(9600);
  

  moduloRF.begin();                 //Inicialidando o MÓDULO para comunicação.
  
  moduloRF.setChannel(68);          //Configurando para trabalhar no canal de número 68, 
                                    //ou seja, canal de número 64 em hexadecimal.
  
  moduloRF.startListening();        //Inicializando o MÓDULO para "ouvir" as requisições.
 
  // Mensagem Instrutiva
  Serial.println("Digite A para andar, P para parar e T para acenar");
  Serial.println(" ");
  Serial.println("Log:");
  Serial.println(" ");

  // Inicializando dispositivos
  Serial.println(F("Inicializando dispositivos I2C..."));
  accelgyro.initialize();

  // Testando conexoes
  Serial.println(F("Testando conexoes do dispositivo..."));
  MPUok = accelgyro.testConnection();
  Serial.println(MPUok ? F("MPU6050 conectado com sucesso!") : F("Falha ao conectar com MPU6050"));

  Serial.println("Atualizando deslocamento interno do sensor...");
  // -76	-2359	1688	0	0	0
  /*Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
  Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
  Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
  Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
  Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
  Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
  Serial.print("\n");*/
  accelgyro.setXAccelOffset(-3274);
  accelgyro.setYAccelOffset(2404);
  accelgyro.setZAccelOffset(3148);
  accelgyro.setXGyroOffset(77);
  accelgyro.setYGyroOffset(-29);
  accelgyro.setZGyroOffset(29);
  /*Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
  Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
  Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
  Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
  Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
  Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
  Serial.print("\n");*/
  
  wdt_enable(WDTO_4S);
  
  servosOmbroE.attach(ServosOmbroE_Porta);
  servosBracoE.attach(ServosBracoE_Porta);
  servosCotoveloE.attach(ServosCotoveloE_Porta);
  servosOmbroD.attach(ServosOmbroD_Porta);
  servosBracoD.attach(ServosBracoD_Porta);
  servosCotoveloD.attach(ServosCotoveloD_Porta);
  //pinMode(LED_Porta, OUTPUT);
}

#include "equilibrio.h"
#include "transmissao.h"

void loop() {
  // put your main code here, to run repeatedly:
  
  if((millis()%Delay_LeituraAnalogica) == 0) {
    if(Escravo_Ligado == 1)
      leitura_analogica = analogRead(Reset_Porta);
    else
      leitura_analogica = 1024;
    //Serial.println(leitura_analogica);
    
    if(Botoes_Ligado == 1) {
      if(analogRead(BTN1_Porta) < NivelBaixo) {
        switch(comando) {
          case 0:
            comando = 1;
            break;
            
          case 1:
            comando = 0;
            break;
            
          case 2:
            comando = 1;
            break;
            
          default:
            comando = 0;
        }
      } else if(analogRead(BTN2_Porta) < NivelBaixo) {
        switch(comando) {
          case 2:
            comando = 0;
            break;
            
          default:
            comando = 2;
        }
      }
        
    }
  }
  
  if(Remoto_Habilitado == 1) {
    Rx();
  
    if(segundos%Delay_Retransmissao == 0 && segundos != segundoTentativa && statusTranceiver > -1 && statusTranceiver <= Tentativas) {
      if(statusTranceiver < Tentativas)
        Tx();
      else {
        comando = 0;
        statusTranceiver++;
      }
      
      segundoTentativa = segundos;
    }
  }
  
  if(iniciando == -1 || leitura_analogica < NivelBaixo) {
    if(y == 100){
      iniciando = -1;
      sinal = -1;
      estado = 0;
      y = 200;
      segundos = 0;
      segundoTentativa = -1;
      autoPedalar = 0;
      autoParar = 0;
    }
    iniciando = configPernas(y);
    
    if(y == 200)
      y = 0;
    else if(y < 50)
      y++;
    else
      y = 100;
    
  } else if(estado != sinal) {
    Wire.beginTransmission(1); // transmit to device #1
      Wire.write(estado);
    Wire.endTransmission();
    
    statusTranceiver = -1;
    
    Serial.print("Estado: ");
    Serial.println(estado);
    Serial.print("Comando: ");
    Serial.print(comando);
    
    if(Remoto_Habilitado == 1) {
      Serial.print(" - Status: ");
      Tx();
    } else
      Serial.println();
    
    sinal = estado;
  } else {
    Modo();
    
    switch(estado) {
      case 0:
        //digitalWrite(LED_Porta, LOW);
        if((millis()%Delay_Acelerometro) == 0) {
          Equilibrio();
        
        } else if((leitura_serial == 'T') || (leitura_serial == 't')) {
          estado = 2;
        }
        
        if(autoPedalar == 1) {
          if(segundos >= Timer_ON) {
            ciclo = -1;
            estado = 1;
            autoPedalar = 0;
            segundos = 0;
          }
        }
        break;
    
      case 1:
        //digitalWrite(LED_Porta, HIGH);
        if((millis()%Delay_Acelerometro) == 0) {
          Equilibrio();
        }
          
        ciclo++;
        
        if(autoParar == 1) {
          if(segundos >= Timer_OFF) {
            estado = 0;
            autoParar = 0;
          }
        }
        break;
      
      case 2:
        if((millis()%Delay_Acelerometro) == 0) Acelerometro();
        
        if(ciclo == 0) {
          posOmbroE = ServosOmbroE_Meio;
          posBracoE = ServosBracoE_Meio;
          posCotoveloE = ServosCotoveloE_Meio;
          posOmbroD = ServosOmbroD_Meio;
          posBracoD = ServosBracoD_Meio;
          posCotoveloD = ServosCotoveloD_Meio;
          Mexer_Bracos();
        }
        
        ciclo++;
        
        if((Delay_Tchau%ciclo) == 0) {
          Tchau();
          Mexer_Bracos();
        } break;
      
      case 3:
        Parada_Emergencia();
        break;
      
      default:
        estado = 0;
    }
    
    segundos = millis()/1000;
    
    if(segundos >= 86400) {
      segundos = 0;
    }
        
    if(ciclo >= Ciclos_Ref) {
      ciclo = 1;
    }
    
    delay(1);
  }
  
  wdt_reset();
}
