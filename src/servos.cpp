#include "Otto.h"

// ← DEFINIÇÕES ÚNICAS DOS SERVOS
Servo bracoDireito;
Servo bracoEsquerdo;
Servo peEsquerdo;
Servo peDireito;

#define PE_DIREITO_POSICAOINICIAL      90
#define PE_ESQUERDO_POSICAOINICIAL     90
#define BRACO_DIREITO_POSICAOINICIAL   135
#define BRACO_ESQUERDO_POSICAOINICIAL  45

unsigned long SERVOS_INTERVALOTEMPO       = 10;
unsigned long SERVOS_CONTADORTEMPOPASSADO = 0;

int SERVO_PEDIREITO_POSICAOATUAL     = 0;
int SERVO_PEESQUERDOO_POSICAOATUAL   = 0;
int SERVO_BRACODIREITO_POSICAOATUAL  = 0;
int SERVO_BRACOESQUERDO_POSICAOATUAL = 0;

void configurarServos(){
    bracoDireito.attach(PIN_ARM_RIGHT);
    bracoDireito.write(BRACO_DIREITO_POSICAOINICIAL);

    bracoEsquerdo.attach(PIN_ARM_LEFT);
    bracoEsquerdo.write(BRACO_ESQUERDO_POSICAOINICIAL);

    peDireito.attach(PIN_FOOT_RIGHT);
    peDireito.write(PE_DIREITO_POSICAOINICIAL);

    peEsquerdo.attach(PIN_FOOT_LEFT);
    peEsquerdo.write(PE_ESQUERDO_POSICAOINICIAL);
}

void desconectarPinoDeTodosServos(){
    bracoDireito.write(BRACO_DIREITO_POSICAOINICIAL);
    bracoDireito.detach();

    bracoEsquerdo.write(BRACO_ESQUERDO_POSICAOINICIAL);
    bracoEsquerdo.detach();

    peEsquerdo.write(PE_ESQUERDO_POSICAOINICIAL);
    peEsquerdo.detach();

    peDireito.write(PE_DIREITO_POSICAOINICIAL);
    peDireito.detach();
}

bool moverPeDireito(int posicaoFinal, int passo){
    desconectarPinoDeTodosServos();
    peDireito.attach(PIN_FOOT_RIGHT);
    unsigned long tAtual = millis();

    if (tAtual - SERVOS_CONTADORTEMPOPASSADO >= SERVOS_INTERVALOTEMPO) {
        if (SERVO_PEDIREITO_POSICAOATUAL == posicaoFinal) return true;

        if (SERVO_PEDIREITO_POSICAOATUAL < posicaoFinal) {
            SERVO_PEDIREITO_POSICAOATUAL += passo;
            if (SERVO_PEDIREITO_POSICAOATUAL > posicaoFinal) SERVO_PEDIREITO_POSICAOATUAL = posicaoFinal;
        }
        if (SERVO_PEDIREITO_POSICAOATUAL > posicaoFinal) {
            SERVO_PEDIREITO_POSICAOATUAL -= passo;
            if (SERVO_PEDIREITO_POSICAOATUAL < posicaoFinal) SERVO_PEDIREITO_POSICAOATUAL = posicaoFinal;
        }
        peDireito.write(SERVO_PEDIREITO_POSICAOATUAL);
        SERVOS_CONTADORTEMPOPASSADO = tAtual;
    }
    return (SERVO_PEDIREITO_POSICAOATUAL == posicaoFinal);
}

bool moverPeEsquerdo(int posicaoFinal, int passo){
    desconectarPinoDeTodosServos();
    peEsquerdo.attach(PIN_FOOT_LEFT);
    unsigned long tAtual = millis();

    if (tAtual - SERVOS_CONTADORTEMPOPASSADO >= SERVOS_INTERVALOTEMPO) {
        if (SERVO_PEESQUERDOO_POSICAOATUAL == posicaoFinal) return true;

        if (SERVO_PEESQUERDOO_POSICAOATUAL < posicaoFinal) {
            SERVO_PEESQUERDOO_POSICAOATUAL += passo;
            if (SERVO_PEESQUERDOO_POSICAOATUAL > posicaoFinal) SERVO_PEESQUERDOO_POSICAOATUAL = posicaoFinal;
        }
        if (SERVO_PEESQUERDOO_POSICAOATUAL > posicaoFinal) {
            SERVO_PEESQUERDOO_POSICAOATUAL -= passo;
            if (SERVO_PEESQUERDOO_POSICAOATUAL < posicaoFinal) SERVO_PEESQUERDOO_POSICAOATUAL = posicaoFinal;
        }
        peEsquerdo.write(SERVO_PEESQUERDOO_POSICAOATUAL);
        SERVOS_CONTADORTEMPOPASSADO = tAtual;
    }
    return (SERVO_PEESQUERDOO_POSICAOATUAL == posicaoFinal);
}

bool moverBracoEsquerdo(int posicaoFinal, int passo){
    desconectarPinoDeTodosServos();
    bracoEsquerdo.attach(PIN_ARM_LEFT);
    unsigned long tAtual = millis();

    if (tAtual - SERVOS_CONTADORTEMPOPASSADO >= SERVOS_INTERVALOTEMPO) {
        if (SERVO_BRACOESQUERDO_POSICAOATUAL == posicaoFinal) return true;

        if (SERVO_BRACOESQUERDO_POSICAOATUAL < posicaoFinal) {
            SERVO_BRACOESQUERDO_POSICAOATUAL += passo;
            if (SERVO_BRACOESQUERDO_POSICAOATUAL > posicaoFinal) SERVO_BRACOESQUERDO_POSICAOATUAL = posicaoFinal;
        }
        if (SERVO_BRACOESQUERDO_POSICAOATUAL > posicaoFinal) {
            // BUG CORRIGIDO: era SERVO_PEESQUERDOO_POSICAOATUAL
            SERVO_BRACOESQUERDO_POSICAOATUAL -= passo;
            if (SERVO_BRACOESQUERDO_POSICAOATUAL < posicaoFinal) SERVO_BRACOESQUERDO_POSICAOATUAL = posicaoFinal;
        }
        bracoEsquerdo.write(SERVO_BRACOESQUERDO_POSICAOATUAL);
        SERVOS_CONTADORTEMPOPASSADO = tAtual;
    }
    return (SERVO_BRACOESQUERDO_POSICAOATUAL == posicaoFinal);
}

bool moverBracoDireito(int posicaoFinal, int passo){
    desconectarPinoDeTodosServos();
    bracoDireito.attach(PIN_ARM_RIGHT);
    unsigned long tAtual = millis();

    if (tAtual - SERVOS_CONTADORTEMPOPASSADO >= SERVOS_INTERVALOTEMPO) {
        if (SERVO_BRACODIREITO_POSICAOATUAL == posicaoFinal) return true;

        if (SERVO_BRACODIREITO_POSICAOATUAL < posicaoFinal) {
            SERVO_BRACODIREITO_POSICAOATUAL += passo;
            if (SERVO_BRACODIREITO_POSICAOATUAL > posicaoFinal) SERVO_BRACODIREITO_POSICAOATUAL = posicaoFinal;
        }
        if (SERVO_BRACODIREITO_POSICAOATUAL > posicaoFinal) {
            SERVO_BRACODIREITO_POSICAOATUAL -= passo;
            if (SERVO_BRACODIREITO_POSICAOATUAL < posicaoFinal) SERVO_BRACODIREITO_POSICAOATUAL = posicaoFinal;
        }
        bracoDireito.write(SERVO_BRACODIREITO_POSICAOATUAL);
        SERVOS_CONTADORTEMPOPASSADO = tAtual;
    }
    return (SERVO_BRACODIREITO_POSICAOATUAL == posicaoFinal);
}