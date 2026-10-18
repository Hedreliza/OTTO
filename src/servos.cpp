#include "Servos.h"

ServoOtto::ServoOtto(int pinoServo, int anguloInicial) {
    pino           = pinoServo;
    posicaoInicial = anguloInicial; 
    anguloAtual    = anguloInicial;
    anguloDestino  = anguloInicial;
    intervaloPasso = 5;
    tempoUltimoPasso = 0;
    servoAtivo = false;
}

void ServoOtto::iniciar() {
    objetoServo.attach(pino);
    objetoServo.write(anguloAtual);
    delay(200);
    objetoServo.detach();
}

void ServoOtto::moverPara(int novoDestino, int novaVelocidade) {
    anguloDestino = novoDestino;
    intervaloPasso = novaVelocidade;
}

void ServoOtto::voltarParaOInicio(int novaVelocidade) {
    anguloDestino = posicaoInicial; 
    intervaloPasso = novaVelocidade;
}

bool ServoOtto::pronto() {
    return (anguloAtual == anguloDestino) && (!servoAtivo);
}

void ServoOtto::atualizar() {
    if (anguloAtual == anguloDestino) {
        if (servoAtivo) {
            objetoServo.detach(); 
            servoAtivo = false;
        }
        return;
    }

    if (!servoAtivo) {
        objetoServo.write(anguloAtual); 
        objetoServo.attach(pino);
        servoAtivo = true;
        tempoUltimoPasso = millis();
        return;
    }

    if (millis() - tempoUltimoPasso >= (unsigned long)intervaloPasso) {
        tempoUltimoPasso = millis();

        if (anguloAtual < anguloDestino) {
            anguloAtual++;
        } else {
            anguloAtual--;
        }
        objetoServo.write(anguloAtual);
    }
}

void ServoOtto::desligar() {
    anguloDestino = anguloAtual; 
    if (servoAtivo) {
        objetoServo.detach();
        servoAtivo = false;
    }
}

// --- Criação única dos objetos ---
ServoOtto peEsquerdo(PIN_FOOT_LEFT, 90);
ServoOtto peDireito(PIN_FOOT_RIGHT, 90);
ServoOtto bracoEsquerdo(PIN_ARM_LEFT, 45);
ServoOtto bracoDireito(PIN_ARM_RIGHT, 135);