#include "Otto.h"

// ================== DEFINIÇÕES ÚNICAS DOS GLOBAIS ==================
OTTOStruct otto = {0, 0, 0, 0, 0, 0, 0};
DFRobotDFPlayerMini myDFPlayer;
LedControl ledControl(PIN_LED_DIN, PIN_LED_CLK, PIN_LED_CS, NBR_MTX);

// ================== FUNÇÕES ==================
bool statusDancaLiberado(){
    if(otto.DfPlayer      == 13) return false;
    if(otto.BracoDireito  == 33) return false;
    if(otto.BracoEsquerdo == 43) return false;
    if(otto.PernaDireita  == 53) return false;
    if(otto.PernaEsquerda == 63) return false;

    return true;
}

bool statusLeituraCartaoRFIDLiberado(){
    if(otto.DfPlayer      == 13) return false;
    if(otto.RFID          == 23) return false;
    if(otto.BracoDireito  == 33) return false;
    if(otto.BracoEsquerdo == 43) return false;
    if(otto.PernaDireita  == 53) return false;
    if(otto.PernaEsquerda == 63) return false;

    return true;
}

bool statusLeituraTecladoNumericoLiberado(){
    if(otto.DfPlayer == 13) return false;
    if(otto.Teclado  == 73) return false;
    
    return true;
}