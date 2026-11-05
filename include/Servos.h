#ifndef SERVOS_H
#define SERVOS_H

#include <Arduino.h>
#include <Servo.h>
#include "Otto.h"

class ServoOtto {
  private:
    Servo objetoServo;
    int pino;
    int anguloAtual;
    int anguloDestino;
    int posicaoInicial; 
    int miliSegundosPorGrau;
    unsigned long tempoAnterior; 
    bool servoAtivo;

  public:
    ServoOtto(int pinoServo, int anguloInicial);
    void iniciar();
    bool isAtivo();
    void moverPara(int novoDestino, int novaVelocidade);
    void voltarParaOInicio(int novaVelocidade);
    void desanexar();
    bool pronto();
    void atualizarUmPasso();
};

extern ServoOtto peEsquerdo;
extern ServoOtto peDireito;
extern ServoOtto bracoEsquerdo;
extern ServoOtto bracoDireito;

#endif