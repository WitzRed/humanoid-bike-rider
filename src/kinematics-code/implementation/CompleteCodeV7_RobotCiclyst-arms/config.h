// Parâmetros de habilitação/desabilitação e ajustes de membros e procedimentos
#define LogAcelerometro            1 // 0 = Desligado / 1 = Ligado *
#define PernaE_Habilitada          1 // 0 = Desligado / 1 = Ligado *
#define PernaD_Habilitada          1 // 0 = Desligado / 1 = Ligado *
#define BracoE_Habilitados         0 // 0 = Desligado / 1 = Ligado
#define BracoD_Habilitados         0 // 0 = Desligado / 1 = Ligado
#define Remoto_Habilitado          0 // 0 = Desligado / 1 = Ligado
#define Escravo_Ligado             0 // 0 = Falso / 1 = Verdadeiro
#define Botoes_Ligado              0 // 0 = Falso / 1 = Verdadeiro
#define Pedalar_Ligado             1 // 0 = Falso / 1 = Verdadeiro *
#define Auto_Pedalar               1 // 0 = Manual / 1 = Automático
#define Auto_Parar                 0 // 0 = Manual / 1 = Automático
#define Timer_OFF                  15 // Tempo em segundos que o robô irá pedalar contínuamente
#define Timer_ON                   10 // Tempo em segundos que o robô irá ficar parado até começar a pedalar automaticamente

// Parâmetros de configuração de servos e funções
int Tipo_Pedalada = 0; // 0 = Perna direita a frente / 1 = Perna esquerda a frente *
#define SentidoCoxas_Iguais        0 // 0 = Falso / 1 = Verdadeiro *
#define SentidoJoelhos_Iguais      1 // 0 = Falso / 1 = Verdadeiro *
#define SentidoTornozelos_Iguais   1 // 0 = Falso / 1 = Verdadeiro *
#define Bracos_Inicio              1 // 0 = Guidão / 1 = Abertos

// Regulagem do desvio dos servos das pernas para ajustes finos rápidos
#define QuadrilE_Desvio            0 // fora(-)(+)dentro *
#define QuadrilD_Desvio            0 // fora(-)(+)dentro *
#define CoxaE_Desvio               5 // baixo(-)(+)cima *
#define CoxaD_Desvio               33 // baixo(-)(+)cima *
#define JoelhoE_Desvio            -8 // frente(-)(+)traz *
#define JoelhoD_Desvio            -3 // frente(-)(+)traz *
#define TornozeloE_Desvio          0 // baixo(-)(+)cima *
#define TornozeloD_Desvio          0 // baixo(-)(+)cima *

// Ajustes de Movimento
#define Altura_Ajuste              25 // *
#define InicioPedalada_CoxaE       20 // baixo(-)(+)cima *
#define InicioPedalada_JoelhoE     20 // frente(-)(+)traz *
#define InicioPedalada_TornozeloE  20 // baixo(-)(+)cima *
#define InicioPedalada_CoxaD       20 // baixo(-)(+)cima *
#define InicioPedalada_JoelhoD     20 // frente(-)(+)traz *
#define InicioPedalada_TornozeloD  20 // baixo(-)(+)cima *

// Referências de funções, para os potores conseguirem efetuar o movimento esperado
#define Delay_Acelerometro         100
#define Delay_LeituraAnalogica     100
#define Delay_Retransmissao        2 // Tempo em segundos entre as tentativas de reenvio de comando em caso de falha
#define Tentativas                 3
#define Delay_Servos_Max           100 // *
#define Delay_Servos_Min           40 // *
int Delay_Servos = Delay_Servos_Max; // *
#define Delay_Servos_Taxa          1 // *
#define Delay_Pausa                1000 // *
#define Delay_Quadril              850 // *
#define Delay_Ajuste               200 // *
#define Delay_Tchau                500
#define TaxaMax_Ref                8 // *
#define TaxaMin_Ref                4 // *
#define Taxa_Ref                   1 // *
#define Taxa_Tchau                 1

// Constantes de ângulos cujo o robô vá para a posição de parado
#define Parada_QuadrilE            62 // *
#define Parada_CoxaE               130 // *
#define Parada_JoelhoE             15 // *
#define Parada_TornozeloE          155 // *
#define Parada_QuadrilD            45 // *
#define Parada_CoxaD               110 // *
#define Parada_JoelhoD             165 // *
#define Parada_TornozeloD          20 // *

// Regulagem dos desvios dos eixos do acelerômetro para definir o ângulo do robô em equilíbrio
#define EixoAX_Desvio              47
#define EixoAY_Desvio             -61
#define EixoAZ_Desvio             -47
#define Zona_Morta_A               5
#define Zona_Morta_G               5

// Atribuição de portas digitais aos dispositivos
#define ServosOmbroE_Porta         3
#define ServosBracoE_Porta         4
#define ServosCotoveloE_Porta      5
#define ServosOmbroD_Porta         6
#define ServosBracoD_Porta         7
#define ServosCotoveloD_Porta      8
//#define LED_Porta                  13
#define BTN1_Porta                 A0
#define BTN2_Porta                 A1
#define Reset_Porta                A7

// Parâmetros de níveis de leituras das portas analógicas
#define NivelAlto                  768
#define NivelBaixo                 256

// Parâmetros de limites dos servos motores com angulação total disponível
#define Servos_Pos_Max             180 // *
#define Servos_Pos_Min             0 // *

// Parâmetros de limites dos servos motores com angulação limitada por peças e/ou espaço
#define ServosCotovelos_Pos_Max    180
#define ServosCotovelos_Pos_Min    95
#define ServoQuadrilE_Pos_Max      92 // *
#define ServoQuadrilE_Pos_Min      62 // *
#define ServoQuadrilD_Pos_Max      75 // *
#define ServoQuadrilD_Pos_Min      45 // *

// Parâmetros literais de desvio dos servos dos braços
#define ServosOmbros_Raio          90
#define ServosOmbroE_Meio          55
#define ServosOmbroD_Meio          55
#define ServosBracos_Raio          80
#define ServosBracoE_Meio          95
#define ServosBracoD_Meio          95
#define ServosCotovelos_Raio       40
#define ServosCotoveloE_Meio       90
#define ServosCotoveloD_Meio       90

// Parâmetros literais de desvio dos servos das pernas
#define Servos_Raio_Ref            30
#define ServosQuadris_Raio         12 // *
//#define ServosCoxas_Raio           30 // *
int ServosCoxas_Raio = Servos_Raio_Ref; // *
//#define ServosJoelhos_Raio         30 // *
int ServosJoelhos_Raio = Servos_Raio_Ref; // *
//#define ServosTornozelos_Raio        30 // *
int ServosTornozelos_Raio = Servos_Raio_Ref; // *

// uncomment "OUTPUT_READABLE_ACCELGYRO" if you want to see a tab-separated
// list of the accel X/Y/Z and then gyro X/Y/Z values in decimal. Easy to read,
// not so easy to parse, and slow(er) over UART.
#define OUTPUT_READABLE_ACCELGYRO

//#define LED_OnBoard 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;

int configPernas(int x) {
  Wire.beginTransmission(1); // transmit to device #1
    Wire.write(x);
    switch(x) {
      case 0:
        Wire.write(PernaE_Habilitada);
        break;
      
      case 1:
        Wire.write(PernaD_Habilitada);
        break;
      
      case 2:
        Wire.write(Pedalar_Ligado);
        break;
      
      case 3:
        Wire.write(Tipo_Pedalada);
        break;
      
      case 4:
        Wire.write(SentidoCoxas_Iguais);
        break;
      
      case 5:
        Wire.write(SentidoJoelhos_Iguais);
        break;
      
      case 6:
        Wire.write(SentidoTornozelos_Iguais);
        break;
      
      case 7:
        if(QuadrilE_Desvio < 0) {
          Wire.write('-');
          Wire.write(-QuadrilE_Desvio);
        } else {
          Wire.write('+');
          Wire.write(QuadrilE_Desvio);
        }
        break;
      
      case 8:
        if(QuadrilE_Desvio < 0) {
          Wire.write('-');
          Wire.write(-QuadrilD_Desvio);
        } else {
          Wire.write('+');
          Wire.write(QuadrilD_Desvio);
        }
        break;
      
      case 9:
        if(CoxaE_Desvio < 0) {
          Wire.write('-');
          Wire.write(-CoxaE_Desvio);
        } else {
          Wire.write('+');
          Wire.write(CoxaE_Desvio);
        }
        break;
      
      case 10:
        if(CoxaD_Desvio < 0) {
          Wire.write('-');
          Wire.write(-CoxaD_Desvio);
        } else {
          Wire.write('+');
          Wire.write(CoxaD_Desvio);
        }
        break;
      
      case 11:
        if(JoelhoE_Desvio < 0) {
          Wire.write('-');
          Wire.write(-JoelhoE_Desvio);
        } else {
          Wire.write('+');
          Wire.write(JoelhoE_Desvio);
        }
        break;
      
      case 12:
        if(JoelhoD_Desvio < 0) {
          Wire.write('-');
          Wire.write(-JoelhoD_Desvio);
        } else {
          Wire.write('+');
          Wire.write(JoelhoD_Desvio);
        }
        break;
      
      case 13:
        if(TornozeloE_Desvio < 0) {
          Wire.write('-');
          Wire.write(-TornozeloE_Desvio);
        } else {
          Wire.write('+');
          Wire.write(TornozeloE_Desvio);
        }
        break;
      
      case 14:
        if(TornozeloD_Desvio < 0) {
          Wire.write('-');
          Wire.write(-TornozeloD_Desvio);
        } else {
          Wire.write('+');
          Wire.write(TornozeloD_Desvio);
        }
        break;
      
      case 15:
        Wire.write(Altura_Ajuste);
        break;
      
      case 16:
        Wire.write(InicioPedalada_CoxaE);
        break;
      
      case 17:
        Wire.write(InicioPedalada_JoelhoE);
        break;
      
      case 18:
        Wire.write(InicioPedalada_TornozeloE);
        break;
      
      case 19:
        Wire.write(InicioPedalada_CoxaD);
        break;
      
      case 20:
        Wire.write(InicioPedalada_JoelhoD);
        break;
      
      case 21:
        Wire.write(InicioPedalada_TornozeloD);
        break;
      
      case 22:
        Wire.write(Delay_Servos_Max);
        break;
      
      case 23:
        Wire.write(Delay_Servos_Min);
        break;
      
      case 24:
        Wire.write(Delay_Servos);
        break;
      
      case 25:
        Wire.write(Delay_Servos_Taxa);
        break;
      
      case 26:
        Wire.write(Delay_Pausa/10);
        break;
      
      case 27:
        Wire.write(Delay_Quadril/10);
        break;
      
      case 28:
        Wire.write(Delay_Ajuste);
        break;
      
      case 29:
        Wire.write(TaxaMax_Ref);
        break;
      
      case 30:
        Wire.write(TaxaMin_Ref);
        break;
      
      case 31:
        Wire.write(Taxa_Ref);
        break;
      
      case 32:
        Wire.write(Parada_QuadrilE);
        break;
      
      case 33:
        Wire.write(Parada_CoxaE);
        break;
      
      case 34:
        Wire.write(Parada_JoelhoE);
        break;
      
      case 35:
        Wire.write(Parada_TornozeloE);
        break;
      
      case 36:
        Wire.write(Parada_QuadrilD);
        break;
      
      case 37:
        Wire.write(Parada_CoxaD);
        break;
      
      case 38:
        Wire.write(Parada_JoelhoD);
        break;
      
      case 39:
        Wire.write(Parada_TornozeloD);
        break;
      
      case 40:
        Wire.write(Servos_Pos_Max);
        break;
      
      case 41:
        Wire.write(Servos_Pos_Min);
        break;
      
      case 42:
        Wire.write(ServoQuadrilE_Pos_Max);
        break;
      
      case 43:
        Wire.write(ServoQuadrilE_Pos_Min);
        break;
      
      case 44:
        Wire.write(ServoQuadrilD_Pos_Max);
        break;
      
      case 45:
        Wire.write(ServoQuadrilD_Pos_Min);
        break;
      
      case 46:
        Wire.write(ServosQuadris_Raio);
        break;
      
      case 47:
        Wire.write(ServosCoxas_Raio);
        break;
      
      case 48:
        Wire.write(ServosJoelhos_Raio);
        break;
      
      case 49:
        Wire.write(ServosTornozelos_Raio);
        x = 100;
        break;
    }
  Wire.endTransmission();    // stop transmitting
  
  if(x == 100)
    return 0;
  else
    return -1;
}
