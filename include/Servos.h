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
    int intervaloPasso;
    unsigned long tempoUltimoPasso;
    bool servoAtivo;

  public:
   
    ServoOtto(int pinoServo, int anguloInicial);
    void iniciar();
    void moverPara(int novoDestino, int novaVelocidade);
    void voltarParaOInicio(int novaVelocidade);
    bool pronto();
    void atualizar();
    void desligar();
};

extern ServoOtto peEsquerdo;
extern ServoOtto peDireito;
extern ServoOtto bracoEsquerdo;
extern ServoOtto bracoDireito;

#endif