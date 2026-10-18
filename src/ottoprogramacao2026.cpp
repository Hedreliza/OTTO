#include "Otto.h"
#include "MatrizLed.h"
#include "DFPlayer.h"
#include "Ir.h"
#include "RFID.h"
#include "Teclado.h"
#include <Arduino.h>
#include "Servos.h"
#include "Movimentos.h"

void setup(){
  
  Serial.begin(9600);
  Serial1.begin(9600); 

    // Manda o DFPlayer usar a Serial1
    if(myDFPlayer.begin(Serial1) == false){
        otto.DfPlayer = 23;
        Serial.println(F("DFPlayer falhou!"));
    } else {       
      myDFPlayer.setTimeOut(500);  
      myDFPlayer.volume(20);       
      myDFPlayer.EQ(0);
      otto.DfPlayer = 20;
      Serial.println(F("DFPlayer OK!"));
    }
  
  configurarRFID();
  //configurarIr();
  //configurarMatrizLed();
  //configurarServos();
  bracoDireito.iniciar();
  bracoEsquerdo.iniciar();
  peDireito.iniciar();
  peEsquerdo.iniciar();
   
}

void loop(){
  verificarDFPlayer();
  verificarRFID();

  bracoDireito.atualizar();
  bracoEsquerdo.atualizar();
  peDireito.atualizar();
  peEsquerdo.atualizar();
  
  gerenciarAceno();
  gerenciarAlegria();
  gerenciarDesanimo();
  gerenciarRaiva();
   
  // --- RFID ---
  // Se a função disser que o RFID, DFPlayer, Servos está OK, tenta ler o cartão
  if (statusLeituraCartaoRFIDLiberado() == true) {
      LeituraCartaoRFID();
  }

  // --- TECLADO ---
  // Se a função disser que o teclado esta liberado e o DFPlayer está OK, lê a tecla
  if (statusLeituraTecladoNumericoLiberado() == true){
    leituraTecladoNumerico();
  }

  // --- CONTROLE REMOTO ---
  // Sempre roda para dectar se uma tecla foi acionada
  leituraControleRemoto();
  
}