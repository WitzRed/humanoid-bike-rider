#define Reset_Porta 1 // 0 = Leitura Analógica / 1 = Porta Reset

// Parâmetros de habilitação/desabilitação e ajustes de membros e procedimentos
int PernaE_Habilitada = -1;
int PernaD_Habilitada = -1;
int Pedalar_Ligado = -1;

// Parâmetros de configuração de servos e funções
int Tipo_Pedalada = -1;
int SentidoCoxas_Iguais = -1;
int SentidoJoelhos_Iguais = -1;
int SentidoTornozelos_Iguais = -1;

// Regulagem do desvio dos servos das pernas para ajustes finos rápidos
int QuadrilE_Desvio = -1;
int QuadrilD_Desvio = -1;
int CoxaE_Desvio = -1;
int CoxaD_Desvio = -1;
int JoelhoE_Desvio = -1;
int JoelhoD_Desvio = -1;
int TornozeloE_Desvio = -1;
int TornozeloD_Desvio = -1;

// Ajustes de Movimento
int Altura_Ajuste = -1;
int InicioPedalada_CoxaE = -1;
int InicioPedalada_JoelhoE = -1;
int InicioPedalada_TornozeloE = -1;
int InicioPedalada_CoxaD = -1;
int InicioPedalada_JoelhoD = -1;
int InicioPedalada_TornozeloD = -1;

// Referências de funções, para os motores conseguirem efetuar o movimento esperado
int Delay_Servos_Max = -1;
int Delay_Servos_Min = -1;
int Delay_Servos = -1;
int Delay_Servos_Taxa = -1;
int Delay_Pausa = -1;
int Delay_Quadril = -1;
int Delay_Ajuste = -1;
int TaxaMax_Ref = -1;
int TaxaMin_Ref = -1;
int Taxa_Ref = -1;

// Constantes de ângulos cujo o robô vá para a posição de parado
int Parada_QuadrilE = -1;
int Parada_CoxaE = -1;
int Parada_JoelhoE = -1;
int Parada_TornozeloE = -1;
int Parada_QuadrilD = -1;
int Parada_CoxaD = -1;
int Parada_JoelhoD = -1;
int Parada_TornozeloD = -1;

// Atribuição de portas digitais aos dispositivos
#define ServoQuadrilE_Porta        3
#define ServoCoxaE_Porta           4
#define ServoJoelhoE_Porta         5
#define ServoTornozeloE_Porta      6
#define ServoQuadrilD_Porta        7
#define ServoCoxaD_Porta           8
#define ServoJoelhoD_Porta         9
#define ServoTornozeloD_Porta      10
#define Reset_Porta                12
#define LED_Porta                  13

// Parâmetros de limites dos servos motores com angulação total disponível
int Servos_Pos_Max = -1;
int Servos_Pos_Min = -1;

// Parâmetros de limites dos servos motores com angulação limitada por peças e/ou espaço
int ServoQuadrilE_Pos_Max = -1;
int ServoQuadrilE_Pos_Min = -1;
int ServoQuadrilD_Pos_Max = -1;
int ServoQuadrilD_Pos_Min = -1;

// Parâmetros literais de desvio dos servos das pernas
int Servos_Raio_Ref = -1;
int ServosQuadris_Raio = -1;
int ServoQuadrilE_Meio = -1;
int ServoQuadrilD_Meio = -1;
int ServosCoxas_Raio = -1;
int ServoCoxaE_Meio = -1;
int ServoCoxaD_Meio = -1;
float TaxaCoxas_Ref = 0;
int ServosJoelhos_Raio = -1;
int ServoJoelhoE_Meio = -1;
int ServoJoelhoD_Meio = -1;
float TaxaJoelhos_Ref = 0;
int ServosTornozelos_Raio = -1;
int ServoTornozeloE_Meio = -1;
int ServoTornozeloD_Meio = -1;
float TaxaTornozelos_Ref = 0;

//#define LED_OnBoard 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;
