// Variáveis de refênrência para as procedimentos de movimentação
int ServosOmbroE_Max = (ServosOmbroE_Meio+ServosOmbros_Raio), ServosBracoE_Max = (ServosBracoE_Meio+ServosBracos_Raio), ServosCotoveloE_Max = (ServosCotoveloE_Meio+ServosCotovelos_Raio);
int ServosOmbroE_Min = (ServosOmbroE_Meio-ServosOmbros_Raio), ServosBracoE_Min = (ServosBracoE_Meio-ServosBracos_Raio), ServosCotoveloE_Min = (ServosCotoveloE_Meio-ServosCotovelos_Raio);
int ServosOmbroD_Max = (ServosOmbroD_Meio+ServosOmbros_Raio), ServosBracoD_Max = (ServosBracoD_Meio+ServosBracos_Raio), ServosCotoveloD_Max = (ServosCotoveloD_Meio+ServosCotovelos_Raio);
int ServosOmbroD_Min = (ServosOmbroD_Meio-ServosOmbros_Raio), ServosBracoD_Min = (ServosBracoD_Meio-ServosBracos_Raio), ServosCotoveloD_Min = (ServosCotoveloD_Meio-ServosCotovelos_Raio);

Servo servosOmbroE, servosBracoE, servosCotoveloE, servosOmbroD, servosBracoD, servosCotoveloD; // Variáveis que fazem referência aos servo motores

int posOmbroE, posBracoE, posCotoveloE, posOmbroD, posBracoD, posCotoveloD; 
int estado = 0, ciclo = -2, Ciclos_Ref = Delay_Pausa, autoPedalar = Auto_Pedalar, autoParar = Auto_Parar, iniciando = -1;
boolean MPUok;

int16_t ax, ay, az;
int EixoAX,  EixoAY, EixoAZ;
int16_t gx, gy, gz;
int EixoGX,  EixoGY, EixoGZ;

char leitura_serial;

int segundos = 0, segundoTentativa = -1, sinal = -1, comando = 0, statusTranceiver = -1;

int y = 200, leitura_analogica = 1024, sentidoTchau = 0;
