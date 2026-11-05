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
        IrReceiver.resume();

        if((otto.ligado == OTTO_LIGADO) && (codigoHexBotao == CONTROLEREMOTO_BOTAOPOWER)){
            myDFPlayer.stop();
            myDFPlayer.play(AUDIO_DESPEDIDA);
            //solicitarCoreografia(aceno,7);
            /*processso de desligar o otto*/
            return;
        }
        
        switch(codigoHexBotao){
            case CONTROLEREMOTO_BOTAOPOWER:
            Serial.println("===== Botão Desligar | Power =====");
                mostrar(Face_Heart);
                myDFPlayer.stop();
                myDFPlayer.play(AUDIO_SAUDACAO);
                solicitarCoreografia(aceno,tamanhoMovimentoAceno);
                
            break;
            case CONTROLEREMOTO_BOTAO1:
            Serial.println("===== Botão 1 | Acenar =====");
                mostrar(Face_Sorriso);
                tocarAudio(AUDIO_APLAUSO);
                solicitarCoreografia(testeBracoEsquerdo,tamanhoMovimentoTesteBracoEsquerdo);

            break;
            case CONTROLEREMOTO_BOTAO3:
                Serial.println("===== Botão 3  =====");
                mostrar(Face_Triste);
                tocarAudio(4);

            break;
            case CONTROLEREMOTO_BOTAO5:
                Serial.println("===== Botão 5 | Dança =====");
                mostrar(Face_Sorriso);
                tocarAudio(AUDIO_DANCA);
                solicitarCoreografia(danca,tamanhoMovimentoDanca);
                
                              
            break;
            case CONTROLEREMOTO_BOTAOVERDE:
                otto.Teclado = (otto.Teclado == 30) ? 34 : 30;

            break;
            default: break;
        }
    
        
    }
     
}