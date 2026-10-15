
#include "Otto.h"
      
void setup(){

  Serial1.begin(9600); 
  Serial.begin(9600); 

  configurarIr();
  configurarDFPlayer();
  configurarMatrizLed();
  configurarRFID();    
  
  /*saudação do OTTO aqui*/
}

void loop (){

  verificarDFPlayer();
  verificarRFID();

  if(statusLeituraCartaoRFIDLiberado() == true){
    LeituraCartaoRFID();
  }
  
  if(statusDancaLiberado() == true){

  }

  if(statusLeituraTecladoNumericoLiberado() == true){
    leituraTecladoNumerico();
  }

  leituraControleRemoto();


}



