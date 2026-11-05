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

  configurarRFID();
  configurarIr();
  configurarMatrizLed();

  bracoDireito.iniciar();

  bracoEsquerdo.iniciar();

  peDireito.iniciar();
 
  peEsquerdo.iniciar();

  Serial1.begin(9600); 

  Serial.println(F("Inicializando DFPlayer!"));  
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

}

void loop(){
  
  //verificarDFPlayer();
  //verificarRFID();

  //=========================================//
  //        FUNCIONALIDADES
  //=========================================//
  LeituraCartaoRFID();

  leituraControleRemoto();

  leituraTecladoNumerico();
  

  //=========================================//
  //         SERVOS 
  //=========================================//
  
  if (CoreografiaAtiva != NULL) {
    if (gerenciarCoreografia(CoreografiaAtiva, totalPassosAtivo)) {
        CoreografiaAtiva = NULL;
    }
  } 
   
  bracoDireito.atualizarUmPasso();
  bracoEsquerdo.atualizarUmPasso();
  peDireito.atualizarUmPasso();
  peEsquerdo.atualizarUmPasso();

  
  
}

