// Procedimentos utilizadas no equilibrio do robô
void Curva(int curva) {
  if(Bracos_Inicio == 1) {
    posBracoE = ServosBracoE_Meio + curva;
  } else {
    posOmbroE = ServosOmbroE_Meio-curva;
    posCotoveloE = ServosCotoveloE_Meio-(ServosOmbroE_Meio-posOmbroE)-curva;
  }
  
  /*Serial.print("OmbroE: ");
  Serial.print(posOmbroE);
  Serial.print(" | CotoveloE: ");
  Serial.println(posCotoveloE);*/
  
  Mexer_Bracos();
}

void Acelerometro() {
  // read raw accel/gyro measurements from device

  if(MPUok) {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
    EixoGX = gx/328;
    EixoGY = gy/328;
    EixoGZ = gz/328;
    EixoAX = ax/183 - 90 + EixoAX_Desvio;
    EixoAY = ay/183 - 90 + EixoAY_Desvio;
    EixoAZ = az/183 - 90 + EixoAZ_Desvio;
    // these methods (and a few others) are also available
    //accelgyro.getAcceleration(&ax, &ay, &az);
    //accelgyro.getRotation(&gx, &gy, &gz);
    // display tab-separated accel/gyro x/y/z values

    if(LogAcelerometro) {
      Serial.print(F("a/g:\t"));
      Serial.print(EixoAX); Serial.print(F("\t"));
      Serial.print(EixoAY); Serial.print(F("\t"));
      Serial.print(EixoAZ); Serial.print(F("\t"));
      Serial.print(EixoGX); Serial.print(F("\t"));
      Serial.print(EixoGY); Serial.print(F("\t"));
      Serial.println(EixoGZ);
    }
  } else {
    EixoGX = 0;
    EixoGY = 0;
    EixoGZ = 0;
    EixoAX = 0;
    EixoAY = 0;
    EixoAZ = 0;
  }
}

void Equilibrio() {
  Acelerometro();
  
  if((EixoGY < Zona_Morta_G) && (EixoGY > -Zona_Morta_G)) {
    if((EixoGY%Zona_Morta_A) == 0) {
      Curva(EixoAY);
    }
  }
}
