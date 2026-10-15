#include "Otto.h"

void configurarDFPlayer(){
    if(myDFPlayer.begin(Serial1) == false){
        //Serial.println(F("DFPlayer não inicializado:"));
        otto.DfPlayer = 23;

    } else {       
        pinMode(DFPlayer_BUSY,INPUT);
        myDFPlayer.setTimeOut(500);  
        myDFPlayer.volume(20);       
        myDFPlayer.EQ(0);
        otto.DfPlayer = 20;
       // Serial.println(F("Modulo DFPlayer Mini inicializado!"));
       
    }
}

void verificarDFPlayer(){
    if(myDFPlayer.available()){
      if (myDFPlayer.readType() == DFPlayerError){
        otto.DfPlayer = 23;
      }
    } 
    
}

void tocarAudio(int audio){
    if (digitalRead(DFPlayer_BUSY) == HIGH) { 
        myDFPlayer.play(audio); 
        delay(200);
    }
}



