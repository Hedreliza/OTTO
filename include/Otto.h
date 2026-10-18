#ifndef OTTO_H
#define OTTO_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
#include <LedControl.h>
#include <MFRC522.h>
#include <SPI.h>
#include <Servo.h>
#include <Keypad.h>

// ==================== PINO DO IR ==================
#define PIN_IR_SIGNAL        22
// ==================== PINOS DOS SERVOS ==================
#define PIN_ARM_RIGHT        24
#define PIN_ARM_LEFT         25
#define PIN_FOOT_RIGHT       26
#define PIN_FOOT_LEFT        27

// ====================== PINOS DO RFID ==================
#define PIN_RFID_SS          53
#define PIN_RFID_RST         49

// ===================== PINOS DO DFPlayer ==================
#define PIN_DFPlayer_BUSY    2
#define PIN_DFPLAYER_RX      19
#define PIN_DFPLAYER_TX      18

// ==================== PINOS DO TECLADO ==================
#define PIN_TECLADO_LINHA1   38
#define PIN_TECLADO_LINHA2   39
#define PIN_TECLADO_COLUNA1  40
#define PIN_TECLADO_COLUNA2  41
#define PIN_TECLADO_COLUNA3  42
#define PIN_TECLADO_COLUNA4  43
#define PIN_TECLADO_COLUNA5  44

// ================== PINOS Da MATRIZ DE LED ==================
#define PIN_LED_DIN          46
#define PIN_LED_CLK          47
#define PIN_LED_CS           48
#define NBR_MTX              1

// ================== ÁUDIOS ==================
#define AUDIO_APLAUSO   1
#define AUDIO_ERROU     2
#define AUDIO_DANCA     3
#define AUDIO_DESLIGA   4

// ================== CONTROLE REMOTO ==================
#define CONTROLEREMOTO_BOTAOPOWER  0xA32AB931
#define CONTROLEREMOTO_BOTAO1      0x371A3C86  // Positivo
#define CONTROLEREMOTO_BOTAO3      0x143226DB  // Negativo
#define CONTROLEREMOTO_BOTAO5      0xE0984BB6  // Dança
#define CONTROLEREMOTO_BOTAOVERDE  0xFFE21D    // Desativa e Ativa o Teclado Numérico

// ================== ESTRUTURA OTTO ==================
struct OTTOStruct {
    int DfPlayer;
    int RFID;
    int BracoDireito;
    int BracoEsquerdo;
    int PernaDireita;
    int PernaEsquerda;
    int Teclado;
    
};

// ================== GLOBAIS (SÓ DECLARAÇÃO) ==================
extern OTTOStruct otto;
extern DFRobotDFPlayerMini myDFPlayer;
extern LedControl ledControl;
extern MFRC522 mfrc522;

// ================== PROTÓTIPOS ==================
void configurarServos();
void configurarIr();
void configurarDFPlayer();
void configurarMatrizLed();
void configurarRFID();

void verificarDFPlayer();
void verificarRFID();
void tocarAudio(int audio);
void mostrar(const byte* Face);
void leituraControleRemoto();
void leituraTecladoNumerico();
void LeituraCartaoRFID();

bool moverPeDireito(int posicaoFinal, int passo);
bool moverPeEsquerdo(int posicaoFinal, int passo);
bool moverBracoEsquerdo(int posicaoFinal, int passo);
bool moverBracoDireito(int posicaoFinal, int passo);
void desconectarPinoDeTodosServos();

bool statusDancaLiberado();
bool statusLeituraCartaoRFIDLiberado();
bool statusLeituraTecladoNumericoLiberado();

int buscarAudioCartao();

#endif