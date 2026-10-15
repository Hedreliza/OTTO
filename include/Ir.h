#include <IRremote.hpp>

#define CONTROLEREMOTO_BOTAOPOWER  0xA32AB931
#define CONTROLEREMOTO_BOTAO1      0x371A3C86  // Positivo
#define CONTROLEREMOTO_BOTAO3      0x143226DB  // Negativo
#define CONTROLEREMOTO_BOTAO5      0xE0984BB6  // Dança
#define CONTROLEREMOTO_BOTAOVERDE  0xFFE21D    // Desativa e Ativa o Teclado Numérico

#define PIN_IR_SIGNAL  47


void configurarIr();
void leituraControleRemoto();
