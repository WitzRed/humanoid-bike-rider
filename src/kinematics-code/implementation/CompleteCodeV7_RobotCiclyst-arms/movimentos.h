// Procedimentos de movimentação
void Mexer_Bracos() {
  if(BracoE_Habilitados == 1) {
    if((posOmbroE >= Servos_Pos_Min) && (posOmbroE <= Servos_Pos_Max)) {
      servosOmbroE.write(posOmbroE);
    } else {
      Serial.print("Servo do ombro esquerdo fora da margem! Valor: ");
      Serial.println(posOmbroE);
          
      if(posOmbroE < Servos_Pos_Min) {
        servosOmbroE.write(Servos_Pos_Min);
      } else if(posOmbroE > Servos_Pos_Max) {
        servosOmbroE.write(Servos_Pos_Max);
      }
    }
    
    if((posBracoE >= Servos_Pos_Min) && (posBracoE <= Servos_Pos_Max)) {
      servosBracoE.write(posBracoE);
    } else {
      Serial.print("Servo dos braco esquerdo fora da margem! Valor: ");
      Serial.println(posBracoE);
          
      if(posBracoE < Servos_Pos_Min) {
        servosBracoE.write(Servos_Pos_Min);
      } else if(posBracoE > Servos_Pos_Max) {
        servosBracoE.write(Servos_Pos_Max);
      }
    }
    
    if((posCotoveloE >= Servos_Pos_Min) && (posCotoveloE <= Servos_Pos_Max)) {
      servosCotoveloE.write(posCotoveloE);
    } else {
      Serial.print("Servo do cotovelo esquerdo fora da margem! Valor: ");
      Serial.println(posCotoveloE);
          
      if(posCotoveloE < Servos_Pos_Min) {
        servosCotoveloE.write(Servos_Pos_Min);
      } else if(posCotoveloE > Servos_Pos_Max) {
        servosCotoveloE.write(Servos_Pos_Max);
      }
    }
  } else {
    if((ServosOmbroE_Meio >= Servos_Pos_Min) && (ServosOmbroE_Meio <= Servos_Pos_Max)) {
      servosOmbroE.write(ServosOmbroE_Meio);
    } else {
      Serial.print("Servo do ombro esquerdo fora da margem! Valor: ");
      Serial.println(ServosOmbroE_Meio);
          
      if(ServosOmbroE_Meio < Servos_Pos_Min) {
        servosOmbroE.write(Servos_Pos_Min);
      } else if(ServosOmbroE_Meio > Servos_Pos_Max) {
        servosOmbroE.write(Servos_Pos_Max);
      }
    }
    
    if((ServosBracoE_Meio >= Servos_Pos_Min) && (ServosBracoE_Meio <= Servos_Pos_Max)) {
      servosBracoE.write(ServosBracoE_Meio);
    } else {
      Serial.print("Servo do braco esquerdo fora da margem! Valor: ");
      Serial.println(ServosBracoE_Meio);
          
      if(ServosBracoE_Meio < Servos_Pos_Min) {
        servosBracoE.write(Servos_Pos_Min);
      } else if(ServosBracoE_Meio > Servos_Pos_Max) {
        servosBracoE.write(Servos_Pos_Max);
      }
    }
    
    if((ServosCotoveloE_Meio >= Servos_Pos_Min) && (ServosCotoveloE_Meio <= Servos_Pos_Max)) {
      servosCotoveloE.write(ServosCotoveloE_Meio);
    } else {
      Serial.print("Servo do cotovelo esquerdo fora da margem! Valor: ");
      Serial.println(ServosCotoveloE_Meio);
          
      if(ServosCotoveloE_Meio < Servos_Pos_Min) {
        servosCotoveloE.write(Servos_Pos_Min);
      } else if(ServosCotoveloE_Meio > Servos_Pos_Max) {
        servosCotoveloE.write(Servos_Pos_Max);
      }
    }
  }
  
  if(BracoD_Habilitados == 1) {
    if((posOmbroD >= Servos_Pos_Min) && (posOmbroD <= Servos_Pos_Max)) {
      servosOmbroD.write(posOmbroD);
    } else {
      Serial.print("Servo do ombro direito fora da margem! Valor: ");
      Serial.println(posOmbroD);
          
      if(posOmbroD < Servos_Pos_Min) {
        servosOmbroD.write(Servos_Pos_Min);
      } else if(posOmbroD > Servos_Pos_Max) {
        servosOmbroD.write(Servos_Pos_Max);
      }
    }
    
    if((posBracoD >= Servos_Pos_Min) && (posBracoD <= Servos_Pos_Max)) {
      servosBracoD.write(posBracoD);
    } else {
      Serial.print("Servo do braco direito fora da margem! Valor: ");
      Serial.println(posBracoD);
          
      if(posBracoD < Servos_Pos_Min) {
        servosBracoD.write(Servos_Pos_Min);
      } else if(posBracoD > Servos_Pos_Max) {
        servosBracoD.write(Servos_Pos_Max);
      }
    }
    
    if((posCotoveloD >= Servos_Pos_Min) && (posCotoveloD <= Servos_Pos_Max)) {
      servosCotoveloD.write(posCotoveloD);
    } else {
      Serial.print("Servo do cotovelo direito fora da margem! Valor: ");
      Serial.println(posCotoveloD);
          
      if(posCotoveloD < Servos_Pos_Min) {
        servosCotoveloD.write(Servos_Pos_Min);
      } else if(posCotoveloD > Servos_Pos_Max) {
        servosCotoveloD.write(Servos_Pos_Max);
      }
    }
  } else {
    if((ServosOmbroD_Meio >= Servos_Pos_Min) && (ServosOmbroD_Meio <= Servos_Pos_Max)) {
      servosOmbroD.write(ServosOmbroD_Meio);
    } else {
      Serial.print("Servo do ombro direito fora da margem! Valor: ");
      Serial.println(ServosOmbroD_Meio);
          
      if(ServosOmbroD_Meio < Servos_Pos_Min) {
        servosOmbroD.write(Servos_Pos_Min);
      } else if(ServosOmbroD_Meio > Servos_Pos_Max) {
        servosOmbroD.write(Servos_Pos_Max);
      }
    }
    
    if((ServosBracoD_Meio >= Servos_Pos_Min) && (ServosBracoD_Meio <= Servos_Pos_Max)) {
      servosBracoD.write(ServosBracoD_Meio);
    } else {
      Serial.print("Servo do braco direito fora da margem! Valor: ");
      Serial.println(ServosBracoD_Meio);
          
      if(ServosBracoD_Meio < Servos_Pos_Min) {
        servosBracoD.write(Servos_Pos_Min);
      } else if(ServosBracoD_Meio > Servos_Pos_Max) {
        servosBracoD.write(Servos_Pos_Max);
      }
    }
    
    if((ServosCotoveloD_Meio >= Servos_Pos_Min) && (ServosCotoveloD_Meio <= Servos_Pos_Max)) {
      servosCotoveloD.write(ServosCotoveloD_Meio);
    } else {
      Serial.print("Servo do cotovelo direito fora da margem! Valor: ");
      Serial.println(ServosCotoveloD_Meio);
          
      if(ServosCotoveloD_Meio < Servos_Pos_Min) {
        servosCotoveloD.write(Servos_Pos_Min);
      } else if(ServosCotoveloD_Meio > Servos_Pos_Max) {
        servosCotoveloD.write(Servos_Pos_Max);
      }
    }
  }
}

void Tchau() {
  posOmbroD = ServosOmbroD_Max;
  
  if(posBracoD <= (ServosBracoD_Max/4)) {
    sentidoTchau = 0;
    posBracoD = ServosBracoD_Max;
  } else if(posBracoD >= ServosBracoD_Max) {
    sentidoTchau = 1;
    posBracoD = (ServosBracoD_Max/4) * 3;
  } else {
    switch(sentidoTchau) {
      case 0:
        posBracoD += Taxa_Tchau;
        break;
      
      case 1:
        posBracoD -= Taxa_Tchau;
        break;
    }
  }
}

void Modo() {
  if(comando != sinal) {
    switch(comando) {
      case 0:
        leitura_serial = 'P';
        break;
      case 1:
        leitura_serial = 'A';
        break;
      case 2:
        leitura_serial = 'T';
        break;
    }
  }
  if(Serial.available() || comando != estado) {
  
    if(Serial.available()) // Aguardar serial receber algum sinal de escrita
      leitura_serial = Serial.read(); // Ler comando via serial
    
    if((leitura_serial == 'A') || (leitura_serial == 'a')) { // Verificando leitura da serial para definir a tag de estado. (1 para andar e 0 para parar)
      if(estado != 1) {
        comando = 1;
        estado = 1;
        ciclo = -1;
      }
    
    } else {
      comando = 0;
      estado = 0;
      
      if((leitura_serial == 'T') || (leitura_serial == 't'))
        comando = 2;
    }
    Serial.print("Leitura Serial: ");
    Serial.println(leitura_serial);
    
    autoParar = 0;
    autoPedalar = 0;
  }
}
