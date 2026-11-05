#ifndef RFID_H
#define RFID_H

#include <Arduino.h>
#include "Otto.h"
#include "Movimentos.h"
#include "DFPlayer.h"
#include "MatrizLed.h"

const int tamanhoByteUIDCartao = 4;
const int faixaAnimacaoInicio = 83;
const int faixaAnimacaoFim = 92;

struct CARTAO_ANIMADO{
  int idAudio;
  const byte* face;
  const Coreografia* coreografia;
  int totalPassos;
};

extern const CARTAO_ANIMADO CATALOGO_CARTAO_ANIMADO[];

struct CARTAO {
    byte uid[4];
    uint16_t numeroAudio;
};



void configurarRFID();
void verificarRFID();
void LeituraCartaoRFID();
int  buscarAudioCartao();
void executarLeituraCartaoAnimado(int numeroAudio);

#endif