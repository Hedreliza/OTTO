#ifndef RFID_H
#define RFID_H

#include <Arduino.h>

struct CARTAO {
    byte uid[4];
    uint16_t numeroAudio;
};

void configurarRFID();
void verificarRFID();
void LeituraCartaoRFID();
int  buscarAudioCartao();

#endif