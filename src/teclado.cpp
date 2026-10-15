#include "Teclado.h"
#include "Otto.h"

Keypad tecladoPersonalizado = Keypad(makeKeymap(TECLAS_MATRIZ), PINOS_LINHAS, PINOS_COLUNAS, LINHAS, COLUNAS); 

void leituraTecladoNumerico(){
    char teclaPressionada = tecladoPersonalizado.getKey();
    if(teclaPressionada){
        switch(teclaPressionada){
            case '0': tocarAudio(97); break;
            case '1': tocarAudio(98); break;
            case '2': tocarAudio(99); break;
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
