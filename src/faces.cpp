#include "Faces.h"

LedControl ledControl = LedControl(PIN_MATRIZLED_DIN, PIN_MATRIZLED_CLK, PIN_MATRIZLED_CS, NBR_MTX);

void configurarMatrizLed(){
    ledControl.shutdown(0, false); // 0 indica qual matriz eu quero controlar, e a contagem começa sempre em 0. Logo, é a primeira matriz que eu quero controlar
    ledControl.setIntensity(0, 20);    
}

void mostrar(const byte* Face){
  for (int i = 0; i < 8; i++) {              
    byte faceAMostrar = pgm_read_byte(&Face[i]);  
    ledControl.setRow(0, i, faceAMostrar);  
  }  
}



