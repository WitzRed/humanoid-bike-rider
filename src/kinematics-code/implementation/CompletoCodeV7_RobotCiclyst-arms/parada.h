// Procedimentos de parada
void Parar() {
  posOmbroE = ServosOmbroE_Meio;
  posOmbroD = ServosOmbroD_Meio;
  posCotoveloE = ServosCotoveloE_Meio;
  posCotoveloD = ServosCotoveloD_Meio;
  
  if(Bracos_Inicio == 0) {
    posBracoE = ServosBracoE_Max;
    posBracoD = ServosBracoE_Max;
  } else {
    posBracoE = ServosBracoE_Meio;
    posBracoD = ServosBracoE_Max;
  }
}

void Parada_Emergencia() {
  Parar();
  posOmbroE = ServosOmbroE_Meio;
  posOmbroD = ServosOmbroD_Meio;
  posBracoE = ServosBracoE_Meio;
  posBracoD = ServosBracoD_Meio;
  posCotoveloE = ServosCotoveloE_Meio;
  posCotoveloD = ServosCotoveloD_Meio;
  
  Mexer_Bracos();
  
  estado = 0;
  ciclo = 0;
  segundos = 0;
}

void Inicializar() {
  if(ciclo == -2) {
    posOmbroE = ServosOmbroE_Meio;
    posOmbroD = ServosOmbroD_Meio;
    posBracoE = ServosBracoE_Meio;
    posBracoD = ServosBracoD_Meio;
    posCotoveloE = ServosCotoveloE_Meio;
    posCotoveloD = ServosCotoveloD_Meio;
    
    Parar();
    Mexer_Bracos();
  }
  iniciando = 1;
  ciclo = 1;
}
