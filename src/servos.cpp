#include "Otto.h"

Servo bracoDireito;
Servo bracoEsquerdo;
Servo peEsquerdo;
Servo peDireito;

#define PE_DIREITO_POSICAOINICIAL      0
#define PE_ESQUERDO_POSICAOINICIAL     0
#define BRACO_DIREITO_POSICAOINICIAL   0
#define BRACO_ESQUERDO_POSICAOINICIAL  0

void configurarServos(){
    bracoDireito.attach(PIN_ARM_RIGHT);
    bracoDireito.write(PE_DIREITO_POSICAOINICIAL);

    bracoEsquerdo.attach(PIN_ARM_LEFT);
    bracoEsquerdo.write(PE_ESQUERDO_POSICAOINICIAL);

    peDireito.attach(PIN_FOOT_RIGHT);
    peDireito.write(PE_DIREITO_POSICAOINICIAL);

    peEsquerdo.attach(PIN_FOOT_LEFT);
    peDireito.write(PE_ESQUERDO_POSICAOINICIAL);

}

void desconectarPinoDeTodosServos(){
    bracoDireito.write(BRACO_DIREITO_POSICAOINICIAL);
    bracoDireito.detach();

    bracoEsquerdo.write(BRACO_ESQUERDO_POSICAOINICIAL);
    bracoEsquerdo.detach();

    peEsquerdo.write(BRACO_ESQUERDO_POSICAOINICIAL);
    peEsquerdo.detach();

    peDireito.write(BRACO_ESQUERDO_POSICAOINICIAL);
    peDireito.detach();

}

void moverPeDireito(int posicaoInical, int posicaoFinal, int passo){
    
    desconectarPinoDeTodosServos();
    peDireito.attach(PIN_FOOT_RIGHT);

    if(posicaoInical< posicaoFinal){
        while(posicaoInical < posicaoFinal){
            peDireito.write(posicaoInical);
            posicaoInical+=passo;
        }
    } else {
        while(posicaoInical < posicaoFinal){
            peDireito.write(posicaoInical);
            posicaoInical-=passo;
        }
    }
    
}

void moverPeEsquerdo(int posicaoInical, int posicaoFinal, int passo){
    
    desconectarPinoDeTodosServos();
    peEsquerdo.attach(PIN_FOOT_LEFT);

    if(posicaoInical< posicaoFinal){
        while(posicaoInical < posicaoFinal){
            peEsquerdo.write(posicaoInical);
            posicaoInical+=passo;
        }
    } else {
        while(posicaoInical >= posicaoFinal){
            peEsquerdo.write(posicaoInical);
            posicaoInical-=passo;
        }
    }
    
}


