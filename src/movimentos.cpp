#include "Movimentos.h"
#include "Servos.h"
#include "Otto.h"

int passoAceno = 0; 
int passoAlegria = 0;
int passoDesanimo = 0;
int passoRaiva = 0;

unsigned long tempoDesanimo = 0;

void iniciarAceno() {
  if (passoAceno == 0) passoAceno = 1;
}

void gerenciarAceno() {
  if (passoAceno == 0) return;
  switch (passoAceno) {
    case 1: bracoDireito.moverPara(180, 8); passoAceno = 2; break;
    case 2: if (bracoDireito.pronto()) { bracoDireito.moverPara(45, 8); passoAceno = 3; } break;
    case 3: if (bracoDireito.pronto()) { bracoDireito.moverPara(180, 8); passoAceno = 4; } break;
    case 4: if (bracoDireito.pronto()) { bracoDireito.moverPara(45, 8); passoAceno = 5; } break;
    case 5: if (bracoDireito.pronto()) { bracoDireito.voltarParaOInicio(10); passoAceno = 6; } break;
    case 6: if (bracoDireito.pronto()) { passoAceno = 0; } break;
  }
}


// ==========================================
void iniciarAlegria() {
  if (passoAlegria == 0) passoAlegria = 1; 
}

void gerenciarAlegria() {
  if (passoAlegria == 0) return;
  switch (passoAlegria) {
    case 1:
      bracoDireito.moverPara(180, 5);
      bracoEsquerdo.moverPara(0, 5);
      passoAlegria = 2;
    break;
    case 2:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        bracoDireito.moverPara(120, 5);
        bracoEsquerdo.moverPara(60, 5);
        passoAlegria = 3;
      }
    break;
    case 3:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        bracoDireito.moverPara(180, 5);
        bracoEsquerdo.moverPara(0, 5);
        passoAlegria = 4;
      }
    break;
    case 4:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        bracoDireito.voltarParaOInicio(5);
        bracoEsquerdo.voltarParaOInicio(5);
        passoAlegria = 5;
      }
    break;
    case 5:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        passoAlegria = 0;
      }
    break;
  }
}

// ==========================================
// MACRO: DESÂNIMO
// ==========================================
void iniciarDesanimo() {
  if (passoDesanimo == 0) passoDesanimo = 1; // CORRIGIDO: era passoAceno
}

void gerenciarDesanimo() {
  if (passoDesanimo == 0) return;
  switch (passoDesanimo) {
    case 1:
      bracoDireito.moverPara(90, 5); 
      bracoEsquerdo.moverPara(90, 5);
      passoDesanimo = 2;
    break;
    case 2:
      if (bracoDireito.pronto() && bracoEsquerdo.pronto()) {
        tempoDesanimo = millis();
        passoDesanimo = 3;
      }
    break;
    case 3:
      if (millis() - tempoDesanimo >= 1000) {
        bracoDireito.voltarParaOInicio(10);
        bracoEsquerdo.voltarParaOInicio(10);
        passoDesanimo = 4;
      }
    break;
    case 4:
      if (bracoDireito.pronto() && bracoEsquerdo.pronto()) {
        passoDesanimo = 0; 
      }
    break;
  }
}

// ==========================================
// MACRO: RAIVA
// ==========================================
void iniciarRaiva() {
  if (passoRaiva == 0) passoRaiva = 1; 
}

void gerenciarRaiva() {
  if (passoRaiva == 0) return;
  switch (passoRaiva){ 
    case 1:
      bracoDireito.moverPara(0, 5); 
      bracoEsquerdo.moverPara(180, 5);
      passoRaiva = 2; 
    break;
    case 2:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        bracoDireito.moverPara(90, 5);
        bracoEsquerdo.moverPara(90, 5);
        passoRaiva = 3; 
      }
    break;
    case 3:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        bracoDireito.moverPara(0, 5);
        bracoEsquerdo.moverPara(180, 5);
        passoRaiva = 4; 
      }
    break;
    case 4:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        bracoDireito.voltarParaOInicio(10);
        bracoEsquerdo.voltarParaOInicio(10);
        passoRaiva = 5; 
      }
    break;
    case 5:
      if(bracoDireito.pronto() && bracoEsquerdo.pronto()){
        passoRaiva = 0; 
      }
    break;
  }
}