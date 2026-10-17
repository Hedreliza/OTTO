#ifndef MATRIZLED_H
#define MATRIZLED_H

#include <Arduino.h>

extern const byte Face_Sorriso[]     PROGMEM;
extern const byte Face_Triste[]      PROGMEM;
extern const byte Face_Vergonha[]    PROGMEM;
extern const byte Face_Surpreso[]    PROGMEM;
extern const byte Face_Cansado[]     PROGMEM;
extern const byte Face_Sono0[]       PROGMEM;
extern const byte Face_Sono1[]       PROGMEM;
extern const byte Face_Sono2[]       PROGMEM;
extern const byte Face_Neutro[]      PROGMEM;
extern const byte Face_Vazio[]       PROGMEM;
extern const byte Face_BocaAbre1[]   PROGMEM;
extern const byte Face_BocaAbre2[]   PROGMEM;
extern const byte Face_Medo[]        PROGMEM;
extern const byte Face_Raiva[]       PROGMEM;
extern const byte Face_Barulho[]     PROGMEM;
extern const byte Face_Enjoado[]     PROGMEM;
extern const byte Face_Heart[]       PROGMEM;
extern const byte Face_Erro[]        PROGMEM;

void configurarMatrizLed();
void mostrar(const byte* Face);

#endif