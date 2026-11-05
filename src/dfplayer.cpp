#include "DFPlayer.h"
#include "Otto.h"
#include "MatrizLed.h"

void verificarDFPlayer(){
  if(myDFPlayer.available()){
    if (myDFPlayer.readType() == DFPlayerError){
      otto.DfPlayer = 23;
      mostrar(DFPlayer_Erro);
    }
  }  
}

void tocarAudio(int audio){
  if (digitalRead(PIN_DFPlayer_BUSY) == HIGH){
    Serial.println(F("Tocando audio"));
    myDFPlayer.play(audio);
  }
}