#include "Teclado.h"
#include "Otto.h"
#include "DFPlayer.h"
#include <Keypad.h>

const byte LINHAS  = TECLADONUMERICO_LINHAS;
const byte COLUNAS = TECLADONUMERICO_COLUNAS;

byte PINOS_LINHAS[LINHAS]   = {PIN_TECLADO_LINHA1, PIN_TECLADO_LINHA2};
byte PINOS_COLUNAS[COLUNAS] = {PIN_TECLADO_COLUNA1, PIN_TECLADO_COLUNA2, PIN_TECLADO_COLUNA3, PIN_TECLADO_COLUNA4, PIN_TECLADO_COLUNA5};

char TECLAS_MATRIZ[LINHAS][COLUNAS] = {
  { '0', '1', '2', '3', '4' },
  { '5', '6', '7', '8', '9' }
};

Keypad tecladoPersonalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS);

void leituraTecladoNumerico(){
    
    if(otto.Teclado == TECLADO_DESABILITADO) return;

    char teclaPressionada = tecladoPersonalizado.getKey();

    if(teclaPressionada){
        switch(teclaPressionada){
            case '0': tocarAudio(97);  break;
            case '1': tocarAudio(98);  break;
            case '2': tocarAudio(99);  break;
            case '3': tocarAudio(100); break;
            case '4': tocarAudio(101); break;
            case '5': tocarAudio(102); break;
            case '6': tocarAudio(103); break;
            case '7': tocarAudio(104); break;
            case '8': tocarAudio(105); break;
            case '9': tocarAudio(106); break;
            default: break;
        }
    }
}