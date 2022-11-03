//Função responsável por configurar o módulo em modo Tx (transmissor).
void Tx() {
  /* Criando uma variável chamada "sucesso" que será setada caso os dados
     sejam enviados com sucesso, isto comprovará o estabelecimento da 
     comunicação entre transmissor e receptor. 
  */
  
  boolean sucesso = moduloRF.write(&comando, sizeof(comando));
  
  if(sucesso) {
      Serial.println("Sucesso na comunicacao!");
      statusTranceiver = -1;
  } else{
      Serial.println("Falha na comunicacao!");
      statusTranceiver++;
  }
    
  moduloRF.startListening(); // iniciando a permissão para receber "ouvir" 
                             // novas requisições.
}

//Função responsável por configurar o módulo em modo Rx (receptor).
void Rx() {
  moduloRF.openReadingPipe(1, tubo); // abrindo o meio de comunicação, com o mesmo
                                     // endeço definido no ínicio do programa, que
                                     // também é o mesmo endereço definido para o
                                     // transmissor, estabelecendo assim um "Tubo"
                                     // para comunição.
                                     
  //verificando se há quaisquer dados enviados pelo tranmissor.
  if(moduloRF.available()) {
    /* Criando uma variável chamada "concluido" que será setada caso os dados
       sejam integralmente recebidos com sucesso. 
    */  
    boolean concluido = false; // Armazenar o payloads até chegar tudo
    
    /* Enquanto os dados não forem integralmente recebidos, ou seja, o 
       CRC (Cyclic Redundancy Check - Verificação de Redundância Cíclica)
       não acusar um "verdadeiro" o programa permanecerá no laço de repetição
       até armazenar toda informação que está sendo enviada pela transmissor.
    */
    while (!concluido) { 
        concluido = moduloRF.read(&comando, sizeof(comando));
    }
    
    if(comando >= 0)
      Serial.println(comando);
    /* Ao receber todos os dados do transmissor verificar se a informação é:
       HIGH (botão pressionado) - se for acender o LED conectado na 
       porta digital D6 do Arduino Receptor. Ou
       LOW (botão não pressionado) - se for apagar o LED conectado na
       na porta digital D6 do Arduino Receptor.
    */
  }                       //aguardando um tempo em milissegundos.
}
