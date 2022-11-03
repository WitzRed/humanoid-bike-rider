// Variáveis de refênrência para as procedimentos de movimentação
int ServoQuadrilE_Max, ServoCoxaE_Max, ServoJoelhoE_Max, ServoTornozeloE_Max;
int ServoQuadrilE_Min, ServoCoxaE_Min, ServoJoelhoE_Min, ServoTornozeloE_Min;
int ServoQuadrilD_Max, ServoCoxaD_Max, ServoJoelhoD_Max, ServoTornozeloD_Max;
int ServoQuadrilD_Min, ServoCoxaD_Min, ServoJoelhoD_Min, ServoTornozeloD_Min;
float taxaCoxas, taxaJoelhos, taxaTornozelos;

Servo servoQuadrilE, servoCoxaE, servoJoelhoE, servoTornozeloE, servoQuadrilD, servoCoxaD, servoJoelhoD, servoTornozeloD; // Variáveis que fazem referência aos servo motores

int posQuadrilE, posCoxaE, posJoelhoE, posTornozeloE, posQuadrilD, posCoxaD, posJoelhoD, posTornozeloD; 
int estado = 0, ciclo = -2, Ciclos_Ref = (Delay_Servos*Taxa_Ref), iniciando = -1;
int sentidoCoxas, sentidoJoelhos, sentidoTornozelos, PernaE = PernaE_Habilitada, PernaD = PernaD_Habilitada;

int x = 200;

char sinalX, receptor;
