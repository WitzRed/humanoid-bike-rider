// Algorítimo principal
#include<avr/wdt.h>
#include<I2Cdev.h>
#include<Wire.h>
#include<Servo.h>
#include "config.h"
#include "variaveis.h"
#include "movimentos.h"
#include "parada.h"
#include "pedalada.h"

void setup() {
  // put your setup code here, to run once:
  Wire.begin(1);
  Wire.onReceive(SinalRecebido); // register event
  Serial.begin(9600);
  
  wdt_enable(WDTO_4S);
  
  servoQuadrilE.attach(ServoQuadrilE_Porta);
  servoCoxaE.attach(ServoCoxaE_Porta);
  servoJoelhoE.attach(ServoJoelhoE_Porta);
  servoTornozeloE.attach(ServoTornozeloE_Porta);
  servoQuadrilD.attach(ServoQuadrilD_Porta);
  servoCoxaD.attach(ServoCoxaD_Porta);
  servoJoelhoD.attach(ServoJoelhoD_Porta);
  servoTornozeloD.attach(ServoTornozeloD_Porta);
  pinMode(LED_Porta, OUTPUT);
  pinMode(Reset_Porta, OUTPUT);
  
  
  digitalWrite(Reset_Porta, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(iniciando != -1) {
    digitalWrite(Reset_Porta, HIGH);
    switch(estado) {
      case 1: // Pedalar
        digitalWrite(LED_Porta, HIGH);
        if(ciclo == -1) {
          Inicializar();
          Ajuste_Pernas(1);
          
          if(Tipo_Pedalada == 1) {
            PernaE = PernaE_Habilitada;
            PernaD = 0;
            Mexer_Pernas(1);
            
            delay(Delay_Quadril);
            Mexer_Quadril();
          } else {
            PernaE = 0;
            PernaD = PernaD_Habilitada;
            Mexer_Pernas(1);
            
            delay(Delay_Quadril);
            Mexer_Quadril();
          }
          
          delay(Delay_Ajuste);
          Ajuste_Pernas(0);
        }
        ciclo++;
        
        if((ciclo%Delay_Servos) == 0) {
          if(Pedalar_Ligado == 1) {
            if(iniciando == 1) {
              if(Tipo_Pedalada == 1) {
                PernaE = 0;
                if(sentidoCoxas == 1) {
                  posCoxaD += (InicioPedalada_CoxaD);
                  posJoelhoD -= (InicioPedalada_JoelhoD);
                  posTornozeloD -= (InicioPedalada_TornozeloD);
                  
                  PernaE = PernaE_Habilitada;
                  PernaD = PernaD_Habilitada;
                  Mexer_Pernas(1);
                  
                  posCoxaD -= (InicioPedalada_CoxaD);
                  posJoelhoD += (InicioPedalada_JoelhoD);
                  posTornozeloD += (InicioPedalada_TornozeloD);
                  
                  Mexer_Quadril();
                  
                  iniciando = 0;
                }
                
              } else {
                PernaD = 0;
                if(sentidoCoxas == 0) {
                  posCoxaE -= (InicioPedalada_CoxaE);
                  posJoelhoE += (InicioPedalada_JoelhoE);
                  posTornozeloE += (InicioPedalada_TornozeloE);
                  
                  PernaE = PernaE_Habilitada;
                  PernaD = PernaD_Habilitada;
                  Mexer_Pernas(1);
                  
                  posCoxaE += (InicioPedalada_CoxaE);
                  posJoelhoE -= (InicioPedalada_JoelhoE);
                  posTornozeloE -= (InicioPedalada_TornozeloE);
                  
                  Mexer_Quadril();
                  
                  iniciando = 0;
                }
              }
            }
            Pedalar();
            if(Delay_Servos > Delay_Servos_Min) {
              Delay_Servos -= Delay_Servos_Taxa;
              Ciclos_Ref = Delay_Servos*Taxa_Ref;
            }
          }
          
          Mexer_Pernas(1);
        
        }
        break;
      
      case 3: // Parada de Emergencia
        Parada_Emergencia();
        break;
      
      default: // Parar
        digitalWrite(LED_Porta, LOW);
        if(x == 200)
          iniciando = -1;
    
        if(Delay_Servos < Delay_Servos_Max) {
          ciclo++;
          
          if((ciclo%Delay_Servos) == 0) {
            if(Pedalar_Ligado == 1) {
              Pedalar();
              Delay_Servos += Delay_Servos_Taxa*2;
              Ciclos_Ref = Delay_Servos*Taxa_Ref;
              ciclo = 1;
              
              if(posJoelhoE < ServoJoelhoE_Meio) {
                Tipo_Pedalada = 1;
              } else {
                Tipo_Pedalada = 0;
              }
            }
            PernaE = PernaE_Habilitada;
            PernaD = PernaD_Habilitada;
            Mexer_Pernas(1);
          }
        } else if(ciclo != 0) {
          Delay_Servos = Delay_Servos_Max;
          
          if((posJoelhoE < ServoJoelhoE_Max) && (posJoelhoE > ServoJoelhoE_Min)){
            if(posJoelhoE < ServoJoelhoE_Meio) {
              Inicio_Pedalada();
              PernaE = 0;
              PernaD = PernaD_Habilitada;
              Mexer_Quadril();
              Mexer_Pernas(1);
            } else {
              Inicio_Pedalada();
              PernaE = PernaE_Habilitada;
              PernaD = 0;
              Mexer_Quadril();
              Mexer_Pernas(1);
            }
            delay(Delay_Ajuste);
          }
          
          Ciclos_Ref = Delay_Servos*Taxa_Ref;
          Parar();
          
          PernaE = PernaE_Habilitada;
          PernaD = PernaD_Habilitada;
          Mexer_Quadril();
          delay(Delay_Quadril);
          Mexer_Pernas(0);
          ciclo = 0;
        }
        break;
    }
        
    if(ciclo >= Ciclos_Ref) {
      ciclo = 1;
    }
    
    if(Delay_Servos < Delay_Servos_Min) {
      Delay_Servos = Delay_Servos_Min;
    }
    
    if(Delay_Servos > Delay_Servos_Max) {
      Delay_Servos = Delay_Servos_Max;
    }
  }
  
  delay(1);
  
  wdt_reset();
}

void SinalRecebido(int Quanto) {
  if(iniciando != -1) {
    while(Wire.available()){
      receptor = Wire.read();
    }
      
    estado = receptor;
    
    if(estado >= 50 || estado < 0) {
      iniciando = -1;
      estado = 0;
    } else {
      Serial.print("Estado: ");
      Serial.println(estado);
    }
  } else {
    x = Wire.read();
    Serial.print("x = ");
    Serial.println(x);
    switch(x) {
      case 0:
        digitalWrite(Reset_Porta, HIGH);
        PernaE_Habilitada = Wire.read();
        Serial.println(PernaE_Habilitada);
        break;
      
      case 1:
        PernaD_Habilitada = Wire.read();
        Serial.println(PernaD_Habilitada);
        break;
      
      case 2:
        Pedalar_Ligado = Wire.read();
        Serial.println(Pedalar_Ligado);
        break;
      
      case 3:
        Tipo_Pedalada = Wire.read();
        Serial.println(Tipo_Pedalada);
        break;
      
      case 4:
        SentidoCoxas_Iguais = Wire.read();
        Serial.println(SentidoCoxas_Iguais);
        break;
      
      case 5:
        SentidoJoelhos_Iguais = Wire.read();
        Serial.println(SentidoJoelhos_Iguais);
        break;
      
      case 6:
        SentidoTornozelos_Iguais = Wire.read();
        Serial.println(SentidoTornozelos_Iguais);
        break;
      
      case 7:
        sinalX = Wire.read();
        QuadrilE_Desvio = Wire.read();
        
        if(sinalX == '-')
          QuadrilE_Desvio = QuadrilE_Desvio * (-1);
        
        Serial.println(QuadrilE_Desvio);
        break;
      
      case 8:
        sinalX = Wire.read();
        QuadrilD_Desvio = Wire.read();
        
        if(sinalX == '-')
          QuadrilD_Desvio = QuadrilD_Desvio * (-1);
        
        
        Serial.println(QuadrilD_Desvio);
        break;
      
      case 9:
        sinalX = Wire.read();
        CoxaE_Desvio = Wire.read();
        
        if(sinalX == '-')
          CoxaE_Desvio = CoxaE_Desvio * (-1);
        
        
        Serial.println(CoxaE_Desvio);
        break;
      
      case 10:
        sinalX = Wire.read();
        CoxaD_Desvio = Wire.read();
        
        if(sinalX == '-')
          CoxaD_Desvio = CoxaD_Desvio * (-1);
        
        
        Serial.println(CoxaD_Desvio);
        break;
      
      case 11:
        sinalX = Wire.read();
        JoelhoE_Desvio = Wire.read();
        
        if(sinalX == '-')
          JoelhoE_Desvio = JoelhoE_Desvio * (-1);
        
        
        Serial.println(JoelhoE_Desvio);
        break;
      
      case 12:
        sinalX = Wire.read();
        JoelhoD_Desvio = Wire.read();
        
        if(sinalX == '-')
          JoelhoD_Desvio = JoelhoD_Desvio * (-1);
        
        
        Serial.println(JoelhoD_Desvio);
        break;
      
      case 13:
        sinalX = Wire.read();
        TornozeloE_Desvio = Wire.read();
        
        if(sinalX == '-')
          TornozeloE_Desvio = TornozeloE_Desvio * (-1);
        
        
        Serial.println(TornozeloE_Desvio);
        break;
      
      case 14:
        sinalX = Wire.read();
        TornozeloD_Desvio = Wire.read();
        
        if(sinalX == '-')
          TornozeloD_Desvio = TornozeloD_Desvio * (-1);
        
        
        Serial.println(TornozeloD_Desvio);
        break;
      
      case 15:
        Altura_Ajuste = Wire.read();
        Serial.println(Altura_Ajuste);
        break;
      
      case 16:
        InicioPedalada_CoxaE = Wire.read();
        Serial.println(InicioPedalada_CoxaE);
        break;
      
      case 17:
        InicioPedalada_JoelhoE = Wire.read();
        Serial.println(InicioPedalada_JoelhoE);
        break;
      
      case 18:
        InicioPedalada_TornozeloE = Wire.read();
        Serial.println(InicioPedalada_TornozeloE);
        break;
      
      case 19:
        InicioPedalada_CoxaD = Wire.read();
        Serial.println(InicioPedalada_CoxaD);
        break;
      
      case 20:
        InicioPedalada_JoelhoD = Wire.read();
        Serial.println(InicioPedalada_JoelhoD);
        break;
      
      case 21:
        InicioPedalada_TornozeloD = Wire.read();
        Serial.println(InicioPedalada_TornozeloD);
        break;
      
      case 22:
        Delay_Servos_Max = Wire.read();
        Serial.println(Delay_Servos_Max);
        break;
      
      case 23:
        Delay_Servos_Min = Wire.read();
        Serial.println(Delay_Servos_Min);
        break;
      
      case 24:
        Delay_Servos = Wire.read();
        Serial.println(Delay_Servos);
        break;
      
      case 25:
        Delay_Servos_Taxa = Wire.read();
        Serial.println(Delay_Servos_Taxa);
        break;
      
      case 26:
        Delay_Pausa = Wire.read();
        Delay_Pausa = Delay_Pausa*10;
        Serial.println(Delay_Pausa);
        break;
      
      case 27:
        Delay_Quadril = Wire.read();
        Delay_Quadril = Delay_Quadril*10;
        Serial.println(Delay_Quadril);
        break;
      
      case 28:
        Delay_Ajuste = Wire.read();
        Serial.println(Delay_Ajuste);
        break;
      
      case 29:
        TaxaMax_Ref = Wire.read();
        Serial.println(TaxaMax_Ref);
        break;
      
      case 30:
        TaxaMin_Ref = Wire.read();
        Serial.println(TaxaMin_Ref);
        break;
      
      case 31:
        Taxa_Ref = Wire.read();
        Serial.println(Taxa_Ref);
        break;
      
      case 32:
        Parada_QuadrilE = Wire.read();
        Serial.println(Parada_QuadrilE);
        break;
      
      case 33:
        Parada_CoxaE = Wire.read();
        Serial.println(Parada_CoxaE);
        break;
      
      case 34:
        Parada_JoelhoE = Wire.read();
        Serial.println(Parada_JoelhoE);
        break;
      
      case 35:
        Parada_TornozeloE = Wire.read();
        Serial.println(Parada_TornozeloE);
        break;
      
      case 36:
        Parada_QuadrilD = Wire.read();
        Serial.println(Parada_QuadrilD);
        break;
      
      case 37:
        Parada_CoxaD = Wire.read();
        Serial.println(Parada_CoxaD);
        break;
      
      case 38:
        Parada_JoelhoD = Wire.read();
        Serial.println(Parada_JoelhoD);
        break;
      
      case 39:
        Parada_TornozeloD = Wire.read();
        Serial.println(Parada_TornozeloD);
        break;
      
      case 40:
        Servos_Pos_Max = Wire.read();
        Serial.println(Servos_Pos_Max);
        break;
      
      case 41:
        Servos_Pos_Min = Wire.read();
        Serial.println(Servos_Pos_Min);
        break;
      
      case 42:
        ServoQuadrilE_Pos_Max = Wire.read();
        Serial.println(ServoQuadrilE_Pos_Max);
        break;
      
      case 43:
        ServoQuadrilE_Pos_Min = Wire.read();
        Serial.println(ServoQuadrilE_Pos_Min);
        break;
      
      case 44:
        ServoQuadrilD_Pos_Max = Wire.read();
        Serial.println(ServoQuadrilD_Pos_Max);
        break;
      
      case 45:
        ServoQuadrilD_Pos_Min = Wire.read();
        Serial.println(ServoQuadrilD_Pos_Min);
        break;
      
      case 46:
        ServosQuadris_Raio = Wire.read();
        Serial.println(ServosQuadris_Raio);
        break;
      
      case 47:
        ServosCoxas_Raio = Wire.read();
        Serial.println(ServosCoxas_Raio);
        break;
      
      case 48:
        ServosJoelhos_Raio = Wire.read();
        Serial.println(ServosJoelhos_Raio);
        break;
      
      case 49:
        ServosTornozelos_Raio = Wire.read();
        Serial.println(ServosTornozelos_Raio);
        iniciando = -2;
        break;
      
      default:
        while(Wire.available())
          Wire.read();
    }
  
  }
  
  if(iniciando == -2) {
    Servos_Raio_Ref = (ServosCoxas_Raio + ServosJoelhos_Raio + ServosTornozelos_Raio) / 3;
    ServoQuadrilE_Meio = (90 + QuadrilE_Desvio - 30);
    ServoQuadrilD_Meio = (90 + QuadrilD_Desvio - 49);
    ServoCoxaE_Meio = (90 - CoxaE_Desvio - 19);
    ServoCoxaD_Meio = (90 + CoxaD_Desvio - 44);
    ServoJoelhoE_Meio = (90 + JoelhoE_Desvio + 128);
    ServoJoelhoD_Meio = (90 - JoelhoD_Desvio + 10);
    ServoTornozeloE_Meio = (90 - TornozeloE_Desvio - 20);
    ServoTornozeloD_Meio = (90 + TornozeloD_Desvio + 60);
    Serial.println(Servos_Raio_Ref);
    Serial.println(ServoQuadrilE_Meio);
    Serial.println(ServoQuadrilD_Meio);
    Serial.println(ServoCoxaE_Meio);
    Serial.println(ServoCoxaD_Meio);
    Serial.println(ServoJoelhoE_Meio);
    Serial.println(ServoJoelhoD_Meio);
    Serial.println(ServoTornozeloE_Meio);
    Serial.println(ServoTornozeloD_Meio);
    
    ServoQuadrilE_Max = (ServoQuadrilE_Meio+ServosQuadris_Raio);
    ServoQuadrilE_Min = (ServoQuadrilE_Meio-ServosQuadris_Raio);
    ServoQuadrilD_Max = (ServoQuadrilD_Meio+ServosQuadris_Raio);
    ServoQuadrilD_Min = (ServoQuadrilD_Meio-ServosQuadris_Raio);
    ServoCoxaE_Max = (ServoCoxaE_Meio+ServosCoxas_Raio);
    ServoCoxaE_Min = (ServoCoxaE_Meio-ServosCoxas_Raio);
    ServoCoxaD_Max = (ServoCoxaD_Meio+ServosCoxas_Raio);
    ServoCoxaD_Min = (ServoCoxaD_Meio-ServosCoxas_Raio);
    ServoJoelhoE_Max = (ServoJoelhoE_Meio+ServosJoelhos_Raio);
    ServoJoelhoE_Min = (ServoJoelhoE_Meio-ServosJoelhos_Raio);
    ServoJoelhoD_Max = (ServoJoelhoD_Meio+ServosJoelhos_Raio);
    ServoJoelhoD_Min = (ServoJoelhoD_Meio-ServosJoelhos_Raio);
    ServoTornozeloE_Max = (ServoTornozeloE_Meio+ServosTornozelos_Raio);
    ServoTornozeloE_Min = (ServoTornozeloE_Meio-ServosTornozelos_Raio);
    ServoTornozeloD_Max = (ServoTornozeloD_Meio+ServosTornozelos_Raio);
    ServoTornozeloD_Min = (ServoTornozeloD_Meio-ServosTornozelos_Raio);
    
    Serial.println(ServoQuadrilE_Max);
    Serial.println(ServoQuadrilE_Min);
    Serial.println(ServoQuadrilD_Max);
    Serial.println(ServoQuadrilD_Min);
    Serial.println(ServoCoxaE_Max);
    Serial.println(ServoCoxaE_Min);
    Serial.println(ServoCoxaD_Max);
    Serial.println(ServoCoxaD_Min);
    Serial.println(ServoJoelhoE_Max);
    Serial.println(ServoJoelhoE_Min);
    Serial.println(ServoJoelhoD_Max);
    Serial.println(ServoJoelhoD_Min);
    Serial.println(ServoTornozeloE_Max);
    Serial.println(ServoTornozeloE_Min);
    Serial.println(ServoTornozeloD_Max);
    Serial.println(ServoTornozeloD_Min);
  
    TaxaCoxas_Ref = ServosCoxas_Raio/Servos_Raio_Ref;
    TaxaJoelhos_Ref = ServosJoelhos_Raio/Servos_Raio_Ref;
    TaxaTornozelos_Ref = ServosTornozelos_Raio/Servos_Raio_Ref;
    
    Serial.print(ServosCoxas_Raio);
    Serial.print(" / ");
    Serial.println(Servos_Raio_Ref);
    Serial.println(TaxaCoxas_Ref);
    Serial.print(ServosJoelhos_Raio);
    Serial.print(" / ");
    Serial.println(Servos_Raio_Ref);
    Serial.println(TaxaJoelhos_Ref);
    Serial.print(ServosTornozelos_Raio);
    Serial.print(" / ");
    Serial.println(Servos_Raio_Ref);
    Serial.println(TaxaTornozelos_Ref);
    
    Inicializar();
  }
  
  wdt_reset();
}
