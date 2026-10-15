#ifndef RFID_h
#define RFID_h

#include "Otto.h"

#define PIN_RFID_RST        48 
#define PIN_RFID_SS         53 

extern MFRC522 mfrc522; 

typedef struct {
    byte uid[7]; 
    int numeroAudio;
} CARTAO;


inline const CARTAO listaCartao[] PROGMEM = {
    {"", }, 
    
};
          
const int TOTAL_CARTOES = sizeof(listaCartao) / sizeof(CARTAO);

void configurarRFID();
void LeituraCartaoRFID();
int  buscarAudioCartao();
void verificarRFID();

#endif
