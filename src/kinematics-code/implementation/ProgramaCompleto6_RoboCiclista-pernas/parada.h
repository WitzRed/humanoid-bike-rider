// Procedimentos de parada
void Parar() {
  iniciando = 0;
  
  posQuadrilE = Parada_QuadrilE;
  posQuadrilD = Parada_QuadrilD;
  
  posCoxaE = Parada_CoxaE;
  posJoelhoE = Parada_JoelhoE;
  posTornozeloE = Parada_TornozeloE;
  
  posCoxaD = Parada_CoxaD;
  posJoelhoD = Parada_JoelhoD;
  posTornozeloD = Parada_TornozeloD;
}

void Parada_Emergencia() {
  if(posJoelhoE < ServoJoelhoE_Meio) {
    Tipo_Pedalada = 1;
  } else {
    Tipo_Pedalada = 0;
  }
  
  Parar();
  
  PernaE = PernaE_Habilitada;
  PernaD = PernaD_Habilitada;
  Mexer_Quadril();
  delay(Delay_Quadril);
  Mexer_Pernas(0);
  
  estado = 0;
  ciclo = 0;
  Delay_Servos = Delay_Servos_Max;
  Ciclos_Ref = Delay_Servos*Taxa_Ref;
}
