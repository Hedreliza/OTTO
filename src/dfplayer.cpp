#include "DFPlayer.h"
#include "Otto.h"

void configurarDFPlayer(){

}

void verificarDFPlayer(){
    if(myDFPlayer.available()){
      if (myDFPlayer.readType() == DFPlayerError){
        otto.DfPlayer = 23;
      }
    } 
    
}

void tocarAudio(int audio){
  if (digitalRead(PIN_DFPlayer_BUSY) == HIGH) {
      myDFPlayer.play(audio);
      delay(200);
  }
}