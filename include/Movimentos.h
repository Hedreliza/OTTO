#ifndef MOVIMENTOS_H
#define MOVIMENTOS_H

#include "Servos.h"
#include "Otto.h"
#include <avr/pgmspace.h>

struct Coreografia{
    int bracoDireito;    int velocidadeBracoDireito;
    int bracoEsquerdo;   int velocidadeBracoEsquerdo;
    int peEsquerdo;      int velocidadePeEsquerdo;
    int peDireito;       int velocidadePeDireito;
    int tempoEspera;     
};

extern const Coreografia danca[] PROGMEM;
extern const Coreografia aceno[] PROGMEM;
extern const Coreografia testeBracoEsquerdo[] PROGMEM;

extern const int tamanhoMovimentoDanca;
extern const int tamanhoMovimentoAceno;
extern const int tamanhoMovimentoDesanimo;
extern const int tamanhoMovimentoAlegria;
extern const int tamanhoMovimentoRaiva;
extern const int tamanhoMovimentoTesteBracoEsquerdo;


extern const Coreografia* CoreografiaAtiva;
extern int totalPassosAtivo;

bool gerenciarCoreografia(const Coreografia* CoreografiaARealizar, int totalPassos);
void solicitarCoreografia(const Coreografia* coreo, int total) ;

void iniciarAceno();
void gerenciarAceno();

void iniciarAlegria();
void gerenciarAlegria();

void iniciarDesanimo();
void gerenciarDesanimo();

void iniciarRaiva();
void gerenciarRaiva();

void iniciarDanca();
void gerenciarDanca();

#endif