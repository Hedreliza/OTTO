#include "Otto.h"

// ================== DEFINIÇÕES ÚNICAS DOS GLOBAIS ==================
OTTOStruct otto = {0, 0, 0, 0, 0, 0, 0};
SoftwareSerial dfPlayerSerial(PIN_DFPLAYER_RX, PIN_DFPLAYER_TX);
DFRobotDFPlayerMini myDFPlayer;
LedControl ledControl(PIN_LED_DIN, PIN_LED_CLK, PIN_LED_CS, NBR_MTX);

// ================== FUNÇÕES ==================
bool statusDancaLiberado(){
    if(otto.DfPlayer      == 23) return false;
    if(otto.BracoDireito  == 63) return false;
    if(otto.BracoEsquerdo == 73) return false;
    if(otto.PernaDireita  == 83) return false;
    if(otto.PernaEsquerda == 93) return false;
    return true;
}

bool statusLeituraCartaoRFIDLiberado(){
    if(otto.DfPlayer      == 23) return false;
    if(otto.BracoDireito  == 63) return false;
    if(otto.BracoEsquerdo == 73) return false;
    if(otto.PernaDireita  == 83) return false;
    if(otto.PernaEsquerda == 93) return false;
    return true;
}

bool statusLeituraTecladoNumericoLiberado(){
    if(otto.Teclado  == 34) return false;
    if(otto.DfPlayer == 23) return false;
    return true;
}