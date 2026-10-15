#include <Keypad.h>

#define PIN_TECLADO_LINHA1  30
#define PIN_TECLADO_LINHA2  31
#define PIN_TECLADO_COLUNA1 25
#define PIN_TECLADO_COLUNA2 26
#define PIN_TECLADO_COLUNA3 27
#define PIN_TECLADO_COLUNA4 28
#define PIN_TECLADO_COLUNA5 29

//------------------------------------PARAMETROS AJUSTAVEIS------------------------------------
#define TECLADONUMERICO_LINHAS    2  // Número de linhas do teclado
#define TECLADONUMERICO_COLUNAS   5  // Número de colunas do teclado

const byte LINHAS   = TECLADONUMERICO_LINHAS;    
const byte COLUNAS  = TECLADONUMERICO_COLUNAS;  

byte PINOS_LINHAS[LINHAS] = {PIN_TECLADO_LINHA1, PIN_TECLADO_LINHA2};  
byte PINOS_COLUNAS[COLUNAS] = {PIN_TECLADO_COLUNA1, PIN_TECLADO_COLUNA2, PIN_TECLADO_COLUNA3, PIN_TECLADO_COLUNA4, PIN_TECLADO_COLUNA5}; 
char TECLAS_MATRIZ[LINHAS][COLUNAS] = {  
  { '0', '1', '2', '3', '4' },
  { '5', '6', '7', '8', '9' }
};

void leituraTecladoNumerico();
