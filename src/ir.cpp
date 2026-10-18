#include "Ir.h"
#include "Otto.h"
#include "DFPlayer.h"
#include <IRremote.hpp>   
#include "MatrizLed.h"
#include "Servos.h"
#include "Movimentos.h"

void configurarIr(){
  IrReceiver.begin(PIN_IR_SIGNAL, ENABLE_LED_FEEDBACK);
}

void leituraControleRemoto(){
    if (IrReceiver.decode()){
        uint32_t codigoHexBotao = IrReceiver.decodedIRData.decodedRawData;

        switch(codigoHexBotao){
            case CONTROLEREMOTO_BOTAOPOWER:
                myDFPlayer.stop();
                tocarAudio(AUDIO_DESLIGA);
                iniciarAceno();
                peDireito.desligar();
                peEsquerdo.desligar();
                bracoDireito.desligar();
                bracoEsquerdo.desligar();
                
            break;
            case CONTROLEREMOTO_BOTAO1:
                mostrar(Face_Sorriso);
                tocarAudio(AUDIO_APLAUSO);
                iniciarAlegria();  

            break;
            case CONTROLEREMOTO_BOTAO3:
                mostrar(Face_Triste);
                tocarAudio(AUDIO_ERROU);
                iniciarDesanimo();   

            break;
            case CONTROLEREMOTO_BOTAO5:
                tocarAudio(AUDIO_DANCA);
                /*movimento dança*/

            break;
            case CONTROLEREMOTO_BOTAOVERDE:
                otto.Teclado = (otto.Teclado == 30) ? 34 : 30;

            break;
        }

        IrReceiver.resume();
    }
}