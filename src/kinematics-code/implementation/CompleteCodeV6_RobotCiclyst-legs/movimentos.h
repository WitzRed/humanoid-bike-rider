// Procedimentos de movimentação
int posJoelhoCompensado(int posCoxa, int posCoxa_Meio, int posJoelho, int modo){
  switch(modo) {
    case 0:
      return posJoelho -= (posCoxa+posCoxa_Meio);
      break;
      
    case 1:
      return posJoelho -= (posCoxa-posCoxa_Meio);
      break;
  }
}

// Procedimento para compensar a coxa e o joelho
int posTornozeloCompensado(int posCoxa, int posCoxa_Meio, int posJoelho, int posJoelho_Meio, int posTornozelo, int modo){
  switch(modo) {
    case 0:
      return posTornozelo += ((posCoxa-posCoxa_Meio) - (posJoelho-posJoelho_Meio));
      break;
      
    case 1:
      return posTornozelo += ((posCoxa+posCoxa_Meio) - (posJoelho+posJoelho_Meio));
      break;
  }
}

void Mexer_Pernas(int tipo) {
  
  if(PernaE == 1) {
    if((posCoxaE >= Servos_Pos_Min) && (posCoxaE <= Servos_Pos_Max)) {
      servoCoxaE.write(posCoxaE);
    } else {
      /*Serial.print("Servo da coxa esquerda fora da margem! Valor: ");
      Serial.println(posCoxaE);*/
          
      if(posCoxaE < Servos_Pos_Min) {
        servoCoxaE.write(Servos_Pos_Min);
      } else if(posCoxaE > Servos_Pos_Max) {
        servoCoxaE.write(Servos_Pos_Max);
      }
    }
  } else {
    if((Parada_CoxaE >= Servos_Pos_Min) && (Parada_CoxaE <= Servos_Pos_Max)) {
      servoCoxaE.write(Parada_CoxaE);
    } else {
      /*Serial.print("Servo do coxa esquerdo fora da margem! Valor: ");
      Serial.println(Parada_CoxaE);*/
          
      if(Parada_CoxaE < Servos_Pos_Min) {
        servoCoxaE.write(Servos_Pos_Min);
      } else if(Parada_CoxaE > Servos_Pos_Max) {
        servoCoxaE.write(Servos_Pos_Max);
      }
    }
    
    if((Parada_JoelhoE >= Servos_Pos_Min) && (Parada_JoelhoE <= Servos_Pos_Max)) {
      servoJoelhoE.write(Parada_JoelhoE);
    } else {
      /*Serial.print("Servo do joelho esquerdo fora da margem! Valor: ");
      Serial.println(Parada_JoelhoE);*/
          
      if(Parada_JoelhoE < Servos_Pos_Min) {
        servoJoelhoE.write(Servos_Pos_Min);
      } else if(Parada_JoelhoE > Servos_Pos_Max) {
        servoJoelhoE.write(Servos_Pos_Max);
      }
    }
    
    if((Parada_TornozeloE >= Servos_Pos_Min) && (Parada_TornozeloE <= Servos_Pos_Max)) {
      servoTornozeloE.write(Parada_TornozeloE);
    } else {
      /*Serial.print("Servo do tornozelo esquerdo fora da margem! Valor: ");
      Serial.println(Parada_TornozeloE);*/
          
      if(Parada_TornozeloE < Servos_Pos_Min) {
        servoTornozeloE.write(Servos_Pos_Min);
      } else if(Parada_TornozeloE > Servos_Pos_Max) {
        servoTornozeloE.write(Servos_Pos_Max);
      }
    }
  }
  
  if(PernaD == 1) {
    if((posCoxaD >= Servos_Pos_Min) && (posCoxaD <= Servos_Pos_Max)) {
      servoCoxaD.write(posCoxaD);
    } else {
      /*Serial.print("Servo da coxa direita fora da margem! Valor: ");
      Serial.println(posCoxaD);*/
      
      if(posCoxaD < Servos_Pos_Min) {
        servoCoxaD.write(Servos_Pos_Min);
      } else if(posCoxaD > Servos_Pos_Max) {
        servoCoxaD.write(Servos_Pos_Max);
      }
    }
  } else {
    if((Parada_CoxaD >= Servos_Pos_Min) && (Parada_CoxaD <= Servos_Pos_Max)) {
      servoCoxaD.write(Parada_CoxaD);
    } else {
      /*Serial.print("Servo do coxa direito fora da margem! Valor: ");
      Serial.println(Parada_CoxaD);*/
          
      if(Parada_CoxaD < Servos_Pos_Min) {
        servoCoxaD.write(Servos_Pos_Min);
      } else if(Parada_CoxaD > Servos_Pos_Max) {
        servoCoxaD.write(Servos_Pos_Max);
      }
    }
    
    if((Parada_JoelhoD >= Servos_Pos_Min) && (Parada_JoelhoD <= Servos_Pos_Max)) {
      servoJoelhoD.write(Parada_JoelhoD);
    } else {
      /*Serial.print("Servo do joelho direito fora da margem! Valor: ");
      Serial.println(Parada_JoelhoD);*/
          
      if(Parada_JoelhoD < Servos_Pos_Min) {
        servoJoelhoD.write(Servos_Pos_Min);
      } else if(Parada_JoelhoD > Servos_Pos_Max) {
        servoJoelhoD.write(Servos_Pos_Max);
      }
    }
    
    if((Parada_TornozeloD >= Servos_Pos_Min) && (Parada_TornozeloD <= Servos_Pos_Max)) {
      servoTornozeloD.write(Parada_TornozeloD);
    } else {
      /*Serial.print("Servo do tornozelo direito fora da margem! Valor: ");
      Serial.println(Parada_TornozeloD);*/
          
      if(Parada_TornozeloD < Servos_Pos_Min) {
        servoTornozeloD.write(Servos_Pos_Min);
      } else if(Parada_TornozeloD > Servos_Pos_Max) {
        servoTornozeloD.write(Servos_Pos_Max);
      }
    }
  }
  
  switch(tipo) {
    case 0:
      if(PernaE == 1) {
        if((posJoelhoE >= Servos_Pos_Min) && (posJoelhoE <= Servos_Pos_Max)) {
          servoJoelhoE.write(posJoelhoE);
        } else {
          /*Serial.print("Servo do joelho esquerdo fora da margem! Valor: ");
          Serial.println(posJoelhoE);*/
          
          if(posJoelhoE < Servos_Pos_Min) {
            servoJoelhoE.write(Servos_Pos_Min);
          } else if(posJoelhoE > Servos_Pos_Max) {
            servoJoelhoE.write(Servos_Pos_Max);
          }
        }
        
        if((posTornozeloE >= Servos_Pos_Min) && (posTornozeloE <= Servos_Pos_Max)) {
          servoTornozeloE.write(posTornozeloE);
        } else {
          /*Serial.print("Servo do tornozelo esquerdo fora da margem! Valor: ");
          Serial.println(posTornozeloE);*/
          
          if(posTornozeloE < Servos_Pos_Min) {
            servoTornozeloE.write(Servos_Pos_Min);
          } else if(posTornozeloE > Servos_Pos_Max) {
            servoTornozeloE.write(Servos_Pos_Max);
          }
        }
      }
      
      if(PernaD == 1) {
        if((posJoelhoD >= Servos_Pos_Min) && (posJoelhoD <= Servos_Pos_Max)) {
          servoJoelhoD.write(posJoelhoD);
        } else {
          /*Serial.print("Servo do joelho direito fora da margem! Valor: ");
          Serial.println(posJoelhoD);*/
          
          if(posJoelhoD < Servos_Pos_Min) {
            servoJoelhoD.write(Servos_Pos_Min);
          } else if(posJoelhoD > Servos_Pos_Max) {
            servoJoelhoD.write(Servos_Pos_Max);
          }
        }
        
        if((posTornozeloD >= Servos_Pos_Min) && (posTornozeloD <= Servos_Pos_Max)) {
          servoTornozeloD.write(posTornozeloD);
        } else {
          /*Serial.print("Servo do tornozelo direito fora da margem! Valor: ");
          Serial.println(posTornozeloD);*/
          
          if(posTornozeloD < Servos_Pos_Min) {
            servoTornozeloD.write(Servos_Pos_Min);
          } else if(posTornozeloD > Servos_Pos_Max) {
            servoTornozeloD.write(Servos_Pos_Max);
          }
        }
      }
      break;
    
    case 1:
      if(PernaE == 1) {
        if((posJoelhoCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, 0) >= Servos_Pos_Min) && (posJoelhoCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, 0) <= Servos_Pos_Max)) {
          servoJoelhoE.write(posJoelhoCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, 0));
        } else {
          /*Serial.print("Servo do joelho esquerdo compensado fora da margem! Valor: ");
          Serial.println(posJoelhoCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, 0));*/
          
          if(posJoelhoCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, 0) < Servos_Pos_Min) {
            servoJoelhoE.write(Servos_Pos_Min);
          } else if(posJoelhoCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, 0) > Servos_Pos_Max) {
            servoJoelhoE.write(Servos_Pos_Max);
          }
        }
        
        if((posTornozeloCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, ServoJoelhoE_Meio, posTornozeloE, 0) >= Servos_Pos_Min) && (posTornozeloCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, ServoJoelhoE_Meio, posTornozeloE, 0) <= Servos_Pos_Max)) {
          servoTornozeloE.write(posTornozeloCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, ServoJoelhoE_Meio, posTornozeloE, 0));
        } else {
          /*Serial.print("Servo do tornozelo esquerdo compensado fora da margem! Valor: ");
          Serial.println(posTornozeloCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, ServoJoelhoE_Meio, posTornozeloE, 0));*/
          
          if(posTornozeloCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, ServoJoelhoE_Meio, posTornozeloE, 0) < Servos_Pos_Min) {
            servoTornozeloD.write(Servos_Pos_Min);
          } else if(posTornozeloCompensado(posCoxaE, ServoCoxaE_Meio, posJoelhoE, ServoJoelhoE_Meio, posTornozeloE, 0) > Servos_Pos_Max) {
            servoTornozeloD.write(Servos_Pos_Max);
          }
        }
      }
      
      if(PernaD == 1) {
        if((posJoelhoCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, 1) >= Servos_Pos_Min) && (posJoelhoCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, 1) <= Servos_Pos_Max)) {
          servoJoelhoD.write(posJoelhoCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, 1));
        } else {
          /*Serial.print("Servo do joelho direito compensado fora da margem! Valor: ");
          Serial.println(posJoelhoCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, 1));*/
          
          if(posJoelhoCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, 1) < Servos_Pos_Min) {
            servoJoelhoD.write(Servos_Pos_Min);
          } else if(posJoelhoCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, 1) > Servos_Pos_Max) {
            servoJoelhoD.write(Servos_Pos_Max);
          }
        }
        
        if((posTornozeloCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, ServoJoelhoD_Meio, posTornozeloD, 1) >= Servos_Pos_Min) && (posTornozeloCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, ServoJoelhoD_Meio, posTornozeloD, 1) <= Servos_Pos_Max)) {
          servoTornozeloD.write(posTornozeloCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, ServoJoelhoD_Meio, posTornozeloD, 1));
        } else {
          /*Serial.print("Servo do tornozelo direito compensado fora da margem! Valor: ");
          Serial.println(posTornozeloCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, ServoJoelhoD_Meio, posTornozeloD, 1));*/
          
          if(posTornozeloCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, ServoJoelhoD_Meio, posTornozeloD, 1) < Servos_Pos_Min) {
            servoTornozeloD.write(Servos_Pos_Min);
          } else if(posTornozeloCompensado(posCoxaD, ServoCoxaD_Meio, posJoelhoD, ServoJoelhoD_Meio, posTornozeloD, 1) > Servos_Pos_Max) {
            servoTornozeloD.write(Servos_Pos_Max);
          }
        }
        
      }
      break;
  }
}

void Mexer_Quadril() {
  if(PernaE == 1) {
    if((posQuadrilE >= ServoQuadrilE_Pos_Min) && (posQuadrilE <= ServoQuadrilE_Pos_Max)) {
      servoQuadrilE.write(posQuadrilE);
    } else {
      /*Serial.print("Servo do quadril esquerdo fora da margem! Valor: ");
      Serial.println(posQuadrilE);*/
      
      if(posQuadrilE < ServoQuadrilE_Pos_Min) {
        servoQuadrilE.write(ServoQuadrilE_Pos_Min);
      } else if(posQuadrilE > ServoQuadrilE_Pos_Max) {
        servoQuadrilE.write(ServoQuadrilE_Pos_Max);
      }
    }
  } else {
    if((Parada_QuadrilE >= ServoQuadrilE_Pos_Min) && (Parada_QuadrilE <= ServoQuadrilE_Pos_Max)) {
      servoQuadrilE.write(Parada_QuadrilE);
    } else {
      /*Serial.print("Servo do quadril esquerdo fora da margem! Valor: ");
      Serial.println(Parada_QuadrilE);*/
      
      if(Parada_QuadrilE < ServoQuadrilE_Pos_Min) {
        servoQuadrilE.write(ServoQuadrilE_Pos_Min);
      } else if(Parada_QuadrilE > ServoQuadrilE_Pos_Max) {
        servoQuadrilE.write(ServoQuadrilE_Pos_Max);
      }
    }
  }
  
  if(PernaD == 1) {
    if((posQuadrilD >= ServoQuadrilD_Pos_Min) && (posQuadrilD <= ServoQuadrilD_Pos_Max)) {
      servoQuadrilD.write(posQuadrilD);
    } else {
      /*Serial.print("Servo do quadril direito fora da margem! Valor: ");
      Serial.println(posQuadrilD);*/
      
      if(posQuadrilD < ServoQuadrilD_Pos_Min) {
        servoQuadrilD.write(ServoQuadrilD_Pos_Min);
      } else if(posQuadrilD > ServoQuadrilD_Pos_Max) {
        servoQuadrilD.write(ServoQuadrilD_Pos_Max);
      }
    }
  }  else {
    if((Parada_QuadrilD >= ServoQuadrilD_Pos_Min) && (Parada_QuadrilD <= ServoQuadrilD_Pos_Max)) {
      servoQuadrilD.write(Parada_QuadrilD);
    } else {
      /*Serial.print("Servo do quadril esquerdo fora da margem! Valor: ");
      Serial.println(Parada_QuadrilD);*/
      
      if(Parada_QuadrilD < ServoQuadrilD_Pos_Min) {
        servoQuadrilD.write(ServoQuadrilD_Pos_Min);
      } else if(Parada_QuadrilD > ServoQuadrilD_Pos_Max) {
        servoQuadrilD.write(ServoQuadrilD_Pos_Max);
      }
    }
  }
}
