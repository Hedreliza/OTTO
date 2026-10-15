#include "rfid.h"
#include "Otto.h" 

MFRC522 mfrc522(PIN_RFID_SS, PIN_RFID_RST); 

void configurarRFID(){                     
    SPI.begin();                
    mfrc522.PCD_Init();   
}

void verificarRFID(){
    // Lê o registrador de versão do chip MFRC522 físico
    byte status = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);

    // Se retornar 0x00 ou 0xFF, significa que o leitor está desconectado ou com fios invertidos
    if(status == 0x00 || status == 0xFF){
        otto.RFID = 11; // Erro de comunicação (Módulo Inoperante)
    } else {
        otto.RFID = 10; // RFID pronto para uso!
    }
}

int buscarAudioCartao(){ 
    for(int i = 0; i < TOTAL_CARTOES; i++){      
        // memcmp_P compara o UID lido com o que está salvo no PROGMEM
        if(memcmp_P(listaCartao[i].uid, mfrc522.uid.uidByte, mfrc522.uid.size) == 0){
            return (int)pgm_read_word(&listaCartao[i].numeroAudio);          
        }       
    }
    return -1; // Retorna -1 se o cartão não estiver cadastrado
}


void LeituraCartaoRFID(){
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()){
        int audio = buscarAudioCartao();

        if(audio != -1){
            tocarAudio(audio); 
        } 

        mfrc522.PICC_HaltA();         
        mfrc522.PCD_StopCrypto1();
    }
}
