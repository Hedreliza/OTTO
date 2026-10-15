#ifndef SERVOS_h
#define SERVOS_h

#define PIN_FOOT_LEFT       18 
#define PIN_FOOT_RIGHT      19 
#define PIN_ARM_LEFT        20 
#define PIN_ARM_RIGHT       21


void moverPeEsquerdo(int de, int para, int passo);
void moverPeDireito(int de, int para, int passo);
void moverBracoDireito(int de, int para, int passo);
void moverBracoEsquerdo(int de, int para, int passo);

void danca();



#endif