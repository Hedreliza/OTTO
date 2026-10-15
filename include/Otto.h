#ifndef OTTO_h
#define OTTO_h

#include "Faces.h"
#include "RFID.h"
#include "DFPlayer.h"
#include "Ir.h"
#include "Teclado.h"
#include "Servos.h"
#include <MFRC522.h> 
#include <Arduino.h>
#include <SPI.h>
#include <Servo.h>

typedef struct{
    int RFID;
    int DfPlayer;
    int Teclado;
    int IR;
    int PernaEsquerda;
    int PernaDireita;
    int BracoEsquerdo;
    int BracoDireito;
}OTTO;

extern OTTO otto;

bool statusLeituraTecladoNumericoLiberado();
bool statusLeituraCartaoRFIDLiberado();
bool statusDancaLiberado();


#endif