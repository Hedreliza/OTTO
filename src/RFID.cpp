#include "Otto.h"
#include "RFID.h"
#include "DFPlayer.h"

MFRC522 mfrc522(PIN_RFID_SS, PIN_RFID_RST);  

const CARTAO listaCartao[] PROGMEM = {
    {{0x36, 0xE7, 0xE6, 0x1F}, 0 },
};

const int TOTAL_CARTOES = sizeof(listaCartao) / sizeof(CARTAO);

void configurarRFID(){
    SPI.begin();
    mfrc522.PCD_Init();
}

void verificarRFID(){
    byte status = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
    if(status == 0x00 || status == 0xFF){
        otto.RFID = 11;
    } else {
        otto.RFID = 10;
    }
}

int buscarAudioCartao(){
    for(int i = 0; i < TOTAL_CARTOES; i++){
        if(memcmp_P(listaCartao[i].uid, mfrc522.uid.uidByte, mfrc522.uid.size) == 0){
            return (int)pgm_read_word(&listaCartao[i].numeroAudio);
        }
    }
    return -1;
}

void LeituraCartaoRFID(){
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()){
        Serial.println(F(">>> CARTAO DETECTADO"));
        int audio = buscarAudioCartao();
        if(audio != -1){
            //Serial.print(F("Tocando audio "));
            //Serial.println(audio);
            tocarAudio(audio);
        }
        mfrc522.PICC_HaltA();
        mfrc522.PCD_StopCrypto1();
    }
}