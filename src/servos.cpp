#include "Servos.h"

ServoOtto::ServoOtto(int pinoServo, int anguloInicial) {
    pino           = pinoServo;
    posicaoInicial = anguloInicial; 
    anguloAtual    = anguloInicial;
    anguloDestino  = anguloInicial;
    miliSegundosPorGrau = 5; 
    tempoAnterior = 0;
    servoAtivo = false;
}

ServoOtto peEsquerdo(PIN_PE_ESQUERDO,90);
ServoOtto peDireito(PIN_PE_DIREITO,90);
ServoOtto bracoEsquerdo(PIN_BRACO_ESQUERDO,135);
ServoOtto bracoDireito(PIN_BRACO_DIREITO,45);

void ServoOtto::iniciar(){
    anguloAtual   = posicaoInicial;
    anguloDestino = posicaoInicial;
    servoAtivo    = false;

    objetoServo.attach(pino);
    objetoServo.write(posicaoInicial);
    delay(500);
    objetoServo.detach();
}

bool ServoOtto::isAtivo(){
    return servoAtivo;
}

void ServoOtto::moverPara(int novoDestino, int novaVelocidade) {
    if(!objetoServo.attached()){
        objetoServo.attach(pino); 
    }

    anguloDestino = novoDestino;
    miliSegundosPorGrau = novaVelocidade;
    tempoAnterior = millis();
}

void ServoOtto::voltarParaOInicio(int novaVelocidade) {
    anguloDestino = posicaoInicial; 
    miliSegundosPorGrau = novaVelocidade;
}

bool ServoOtto::pronto() {
    return (anguloAtual == anguloDestino) && (!servoAtivo);
}

void ServoOtto::desanexar() {
    objetoServo.detach();
    servoAtivo = false;
}

void ServoOtto::atualizarUmPasso(){

    static unsigned long ultimoLog = 0;
    if (millis() - ultimoLog >= 500) {
        ultimoLog = millis();
        Serial.print(F("=============")); 
        Serial.print(F("   SERVOS  "));
        Serial.print(F("=============")); 
        Serial.print(F("atual: atual=")); Serial.print(anguloAtual);
        Serial.print(F(" destino="));     Serial.print(anguloDestino);
        Serial.print(F(" ativo="));       Serial.print(servoAtivo);
        Serial.print(F(" attachd="));     Serial.println(objetoServo.attached());
    }

    if (anguloAtual == anguloDestino){  
       servoAtivo = false;
        return;  
    }

    if (!servoAtivo) { 
        if (!objetoServo.attached()) { 
            objetoServo.attach(pino);
        }
        objetoServo.write(anguloAtual); 
        servoAtivo = true;
        tempoAnterior = millis(); 
        return;
    }

    if (millis() - tempoAnterior >= (unsigned long)miliSegundosPorGrau) {
        tempoAnterior = millis(); 
        
        if (anguloAtual < anguloDestino){
            anguloAtual++;
        }else {
            anguloAtual--;
        }         

        objetoServo.write(anguloAtual);
    }   
}