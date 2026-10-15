#include "Ir.h"
#include "Otto.h"

const byte RECV_PIN = PIN_IR_SIGNAL;    

void configurarIr(){
   IrReceiver.begin(PIN_IR_SIGNAL, ENABLE_LED_FEEDBACK);
}

void leituraControleRemoto(){
  
  if (IrReceiver.decode()){   
    uint16_t codigoHexBotao = IrReceiver.decodedIRData.command;
    //Serial.println(IrReceiver.decodedIRData.command, HEX);

    switch(codigoHexBotao){
      case CONTROLEREMOTO_BOTAOPOWER:       
        /*desliga o OTTO*/
        /*tchau do otto*/
        /*posição de descanso*/
        /*myDFPlayer.play(AUDIO_DESLIGA)*/

      break;
      case CONTROLEREMOTO_BOTAO1:
        tocarAudio(AUDIO_APLAUSO);
       
      break;
      case CONTROLEREMOTO_BOTAO3:
        tocarAudio(AUDIO_ERROU);
           
      break;
      case CONTROLEREMOTO_BOTAO5:
        tocarAudio(AUDIO_DANCA);
      
      break;
      case CONTROLEREMOTO_BOTAOVERDE:

        otto.Teclado = (otto.Teclado == 30)? 34:30;
        
      break;
    }

    IrReceiver.resume(); 
  }
}


