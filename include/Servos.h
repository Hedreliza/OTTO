#ifndef SERVOS_h
#define SERVOS_h
#include <Servo.h> 
#define PIN_FOOT_LEFT       18 
#define PIN_FOOT_RIGHT      19 
#define PIN_ARM_LEFT        20 
#define PIN_ARM_RIGHT       21

extern Servo bracoDireito;
extern Servo bracoEsquerdo;
extern Servo peEsquerdo;
extern Servo peDireito;

void desconectarPinoDeTodosServos();
void configurarServos();
bool moverPeEsquerdo(int posicaoFinal, int passo);
bool moverPeDireito(int posicaoFinal, int passo);
bool moverBracoDireito(int posicaoFinal, int passo);
bool moverBracoEsquerdo(int posicaoFinal, int passo);

#endif