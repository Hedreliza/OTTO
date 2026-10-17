#include "Ir.h"
#include "Otto.h"
#include "DFPlayer.h"
#include <IRremote.hpp>     // ← v4 usa .hpp

void configurarIr(){
  IrReceiver.begin(PIN_IR_SIGNAL, ENABLE_LED_FEEDBACK);
  
}

void leituraControleRemoto(){
    if (IrReceiver.decode()){
        uint32_t codigoHexBotao = IrReceiver.decodedIRData.decodedRawData;

        switch(codigoHexBotao){
            case CONTROLEREMOTO_BOTAOPOWER:
                // desliga o OTTO
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
                otto.Teclado = (otto.Teclado == 30) ? 34 : 30;
            break;
        }

        IrReceiver.resume();
    }
}