#include "Otto.h"
#include "MatrizLed.h"
#include "DFPlayer.h"
#include "Ir.h"
#include "RFID.h"
#include "Teclado.h"
#include <Arduino.h>

void setup(){
  
  Serial.begin(9600);
  
  configurarRFID();
  //configurarIr();
  //configurarMatrizLed();
  //configurarServos();
   
   
}

void loop(){
  //verificarDFPlayer();
  verificarRFID();

  //if(statusLeituraCartaoRFIDLiberado() == true){
    LeituraCartaoRFID();
  //}

  
  /*
    if(statusDancaLiberado() == true){

    }

    if(statusLeituraTecladoNumericoLiberado() == true){
      leituraTecladoNumerico();
    }

    leituraControleRemoto();
  */
}