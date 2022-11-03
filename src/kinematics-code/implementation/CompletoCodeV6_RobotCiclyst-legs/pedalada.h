// Procedimentos de pedalada
void Inicio_Pedalada() {
  switch(Tipo_Pedalada) {
    case 0:
      sentidoCoxas = 1;
      sentidoJoelhos = 1;
      sentidoTornozelos = 1;
      
      posCoxaE = ServoCoxaE_Meio;
      posJoelhoE = ServoJoelhoE_Max;
      posTornozeloE = ServoTornozeloE_Meio;
      posCoxaD = ServoCoxaD_Meio;
      posJoelhoD = ServoJoelhoD_Max;
      posTornozeloD = ServoTornozeloD_Meio;
      break;
      
    case 1:
      sentidoCoxas = 0;
      sentidoJoelhos = 0;
      sentidoTornozelos = 0;
      
      posCoxaE = ServoCoxaE_Meio;
      posJoelhoE = ServoJoelhoE_Min;
      posTornozeloE = ServoTornozeloE_Meio;
      posCoxaD = ServoCoxaD_Meio;
      posJoelhoD = ServoJoelhoD_Min;
      posTornozeloD = ServoTornozeloD_Meio;
      break;
  }
}

void Inicializar() {
  if(ciclo == -2) {
    Parar();
    PernaE = PernaE_Habilitada;
    PernaD = PernaD_Habilitada;
    Mexer_Quadril();
    Mexer_Pernas(0);
    
  } else {
    posQuadrilE = ServoQuadrilE_Max;
    posQuadrilD = ServoQuadrilD_Max;
    Inicio_Pedalada();
    
    if(posCoxaE == ServoCoxaE_Meio) {
      taxaCoxas = TaxaMax_Ref;
    } else {
      taxaCoxas = TaxaMin_Ref;
    }
    
    if(posJoelhoE == ServoJoelhoE_Meio) {
      taxaJoelhos = TaxaMax_Ref;
    } else {
      taxaJoelhos = TaxaMin_Ref;
    }
    
    if(posJoelhoE == ServoJoelhoE_Meio) {
      taxaTornozelos = TaxaMax_Ref;
    } else {
      taxaTornozelos = TaxaMin_Ref;
    }
  }
  iniciando = 1;
  ciclo = 1;
}

void Ajuste_Pernas(int modo) {
  switch(modo) {
    case 0:      
      if(posJoelhoE < ServoJoelhoE_Meio) {
        posCoxaE = posCoxaE + Altura_Ajuste;
      } else {
        posCoxaD = posCoxaD - Altura_Ajuste;
      }
      break;
    
    case 1:
      if(posJoelhoE < ServoJoelhoE_Meio) {
        posCoxaE = posCoxaE - Altura_Ajuste;
      } else {
        posCoxaD = posCoxaD + Altura_Ajuste;
      }
      break;
  }
}

void Pedalar() {
  
  switch(sentidoCoxas) {
    case 0:
      posCoxaE += taxaCoxas;
      if(SentidoCoxas_Iguais == 1) {
        posCoxaD += taxaCoxas;
      } else {
        posCoxaD -= taxaCoxas;
      }
      
      if(posCoxaE <= ServoCoxaE_Meio) {
        if(taxaCoxas < TaxaMax_Ref) {
          taxaCoxas += Taxa_Ref;
        }
        
      } else if((posCoxaE > ServoCoxaE_Meio) && (posCoxaE < ServoCoxaE_Max)) {
        if (taxaCoxas > TaxaMin_Ref) {
          taxaCoxas -= Taxa_Ref;
        }
      }
      
      if(posCoxaE >= ServoCoxaE_Max) {
        posCoxaE = ServoCoxaE_Max;
        sentidoCoxas = 1;
      } break;
        
    case 1:
      posCoxaE -= taxaCoxas;
      if(SentidoCoxas_Iguais == 1) {
        posCoxaD -= taxaCoxas;
      } else {
        posCoxaD += taxaCoxas;
      }
      
      if(posCoxaE >= ServoCoxaE_Meio) {
        if(taxaCoxas < TaxaMax_Ref) {
          taxaCoxas += Taxa_Ref;
        }
      
      } else if((posCoxaE < ServoCoxaE_Meio) && (posCoxaE > ServoCoxaE_Min)) {
        if (taxaCoxas > TaxaMin_Ref) {
          taxaCoxas -= Taxa_Ref;
        }
      }
      
      if(posCoxaE <= ServoCoxaE_Min) {
        posCoxaE = ServoCoxaE_Min;
        sentidoCoxas = 0;
      } break;
  }
  
  switch(sentidoJoelhos) {
    case 0:
      posJoelhoE += taxaJoelhos;
      if(SentidoJoelhos_Iguais == 1) {
        posJoelhoD += taxaJoelhos;
      } else {
        posJoelhoD -= taxaJoelhos;
      }
      
      if(posJoelhoE <= ServoJoelhoE_Meio) {
        if(taxaJoelhos < TaxaMax_Ref) {
          taxaJoelhos += Taxa_Ref;
        }
        
      } else if((posJoelhoE > ServoJoelhoE_Meio) && (posJoelhoE < ServoJoelhoE_Max)) {
        if (taxaJoelhos > TaxaMin_Ref) {
          taxaJoelhos -= Taxa_Ref;
        }
      }
      
      if(posJoelhoE >= ServoJoelhoE_Max) {
        posJoelhoE = ServoJoelhoE_Max;
        sentidoJoelhos = 1;
      } break;
        
    case 1:
      posJoelhoE -= taxaJoelhos;
      if(SentidoJoelhos_Iguais == 1) {
        posJoelhoD -= taxaJoelhos;
      } else {
        posJoelhoD += taxaJoelhos;
      }
      
      if(posJoelhoE >= ServoJoelhoE_Meio) {
        if(taxaJoelhos < TaxaMax_Ref) {
          taxaJoelhos += Taxa_Ref;
        }
      
      } else if((posJoelhoE < ServoJoelhoE_Meio) && (posJoelhoE > ServoJoelhoE_Min)) {
        if (taxaJoelhos > TaxaMin_Ref) {
          taxaJoelhos -= Taxa_Ref;
        }
      }
      
      if(posJoelhoE <= ServoJoelhoE_Min) {
        posJoelhoE = ServoJoelhoE_Min;
        sentidoJoelhos = 0;
      } break;
  }
  
  switch(sentidoTornozelos) {
    case 0:
      posTornozeloE += taxaTornozelos;
      if(SentidoTornozelos_Iguais == 1) {
        posTornozeloD += taxaTornozelos;
      } else {
        posTornozeloD -= taxaTornozelos;
      }
      
      if(posTornozeloE <= ServoTornozeloE_Meio) {
        if(taxaTornozelos < TaxaMax_Ref) {
          taxaTornozelos += Taxa_Ref;
        }
        
      } else if((posTornozeloE > ServoTornozeloE_Meio) && (posTornozeloE < ServoTornozeloE_Max)) {
        if (taxaTornozelos > TaxaMin_Ref) {
          taxaTornozelos -= Taxa_Ref;
        }
      }
      
      if(posTornozeloE >= ServoTornozeloE_Max) {
        posTornozeloE = ServoTornozeloE_Max;
        sentidoTornozelos = 1;
      } break;
        
    case 1:
      posTornozeloE -= taxaTornozelos;
      if(SentidoTornozelos_Iguais == 1) {
        posTornozeloD -= taxaTornozelos;
      } else {
        posTornozeloD += taxaTornozelos;
      }
      
      if(posTornozeloE >= ServoTornozeloE_Meio) {
        if(taxaTornozelos < TaxaMax_Ref) {
          taxaTornozelos += Taxa_Ref;
        }
      
      } else if((posTornozeloE < ServoTornozeloE_Meio) && (posTornozeloE > ServoTornozeloE_Min)) {
        if (taxaTornozelos > TaxaMin_Ref) {
          taxaTornozelos -= Taxa_Ref;
        }
      }
      
      if(posTornozeloE <= ServoTornozeloE_Min) {
        posTornozeloE = ServoTornozeloE_Min;
        sentidoTornozelos = 0;
      } break;
  }
}
