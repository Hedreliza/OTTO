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
#define PIN_BRACO_ESQUERDO         23
#define PIN_PE_ESQUERDO       29
#define PIN_BRACO_DIREITO       24
#define PIN_PE_DIREITO       26

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
#define PIN_LED_CS           47
#define PIN_LED_CLK          48
#define NBR_MTX              1

// ================== ÁUDIOS ==================
#define AUDIO_SAUDACAO    1
#define AUDIO_DESPEDIDA   2
#define AUDIO_APLAUSO     3
#define AUDIO_ERROU       4
#define AUDIO_DANCA       5

// ================== CONTROLE REMOTO ==================
#define CONTROLEREMOTO_BOTAOPOWER  0xBA45FF00
#define CONTROLEREMOTO_BOTAO1      0xF30CFF00  // Positivo
#define CONTROLEREMOTO_BOTAO3      0xA15EFF00  // Negativo
#define CONTROLEREMOTO_BOTAO5      0xE31CFF00  // Dança
#define CONTROLEREMOTO_BOTAOVERDE  0xB847FF00   // Desativa e Ativa o Teclado Numérico

// ================== CODIGOS DE STATUS ==================
#define RFID_OK                 10
#define RFID_ERRO               11
#define DFPLAYER_ERRO           23
#define TECLADO_HABILITADO      30
#define TECLADO_DESABILITADO    34
#define OTTO_LIGADO             70

// ================== ESTRUTURA OTTO ==================
struct OTTOStruct {
    int DfPlayer;
    int RFID;
    int BracoDireito;
    int BracoEsquerdo;
    int PernaDireita;
    int PernaEsquerda;
    int Teclado; 
    int dancando;
    int ligado;
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


bool statusDancaLiberado();
bool statusLeituraCartaoRFIDLiberado();
bool statusLeituraTecladoNumericoLiberado();

int buscarAudioCartao();

#endif