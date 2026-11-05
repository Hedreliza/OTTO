#include "Movimentos.h"

int passoAtual = 0;
unsigned long tempoAnteriorPasso = 0; 
bool enviouComandoMovimento = false;
const Coreografia* CoreografiaAtiva = NULL;
int totalPassosAtivo = 0;

void solicitarCoreografia(const Coreografia* coreografia, int total) {
  passoAtual             = 0;         
  enviouComandoMovimento = false;
  tempoAnteriorPasso     = 0;
  CoreografiaAtiva       = coreografia;
  totalPassosAtivo       = total;
}

const Coreografia danca[] PROGMEM = {
/*| BD  |  BE  |  PE  |  PD |*/
  {45 ,0, 135,0, 140,6, 90,6,0},
  {45 ,0, 135,0,  90,6, 40,6,0},
  {45 ,0, 135,0, 140,6, 90,6,0},
  {45 ,0, 135,0,  90,6, 40,6,0},
  {45 ,0, 135,0, 140,6, 90,6,0},
  {45 ,0, 135,0,  90,6, 40,6,0},
  {45 ,0, 135,0, 140,6, 90,6,0},
  {45 ,0, 135,0,  90,6, 40,6,0},
  {45 ,0, 135,0, 140,6, 90,6,0},
  {45 ,0, 135,0,  90,6, 40,6,0},
  {45 ,0, 135,0, 140,6, 90,6,0},
  {45 ,0, 135,0,  90,6, 40,6,0},
  {45 ,0, 135,0, 170,8, 90,8,0},
  {45 ,0, 135,0,  90,8, 90,8,0},
  {45 ,0, 135,0,  90,8, 20,8,0},
  {45 ,0, 135,0,  90,8, 90,8,0},
  {45 ,0, 135,0, 170,8, 90,8,0},
  {45 ,0, 135,0,  90,8, 90,8,0},
  {45 ,0, 135,0,  90,8, 20,8,0},
  {45 ,0, 135,0,  90,8, 90,8,0},
  {45 ,0, 135,0, 170,8, 90,8,0},
  {45 ,0, 135,0,  90,8, 90,8,0},
  {45 ,0, 135,0,  90,8, 20,8,0},
  {45 ,0, 135,0,  90,8, 90,8,0},
  {180,3, 135,0,  90,5, 90,0,0},
  {180,3, 135,0, 140,5, 90,0,0},
  {180,3, 135,0,  90,5, 90,0,0},
  {180,3, 135,0, 140,5, 90,0,0},
  {180,3, 135,0,  90,5, 90,0,0},
  {45 ,3, 135,3,  90,0, 90,0,0},
  {0  ,3,   0,3,  90,0, 90,0,0},
  {180,3, 180,3,  90,0, 90,0,0},
  {0  ,3,   0,3,  90,0, 90,0,0},
  {180,3, 180,3,  90,0, 90,0,0},
  {0  ,3,   0,3,  90,0, 90,0,0},
  {180,3, 180,3,  90,0, 90,0,0},
};
constexpr int tamanhoMovimentoDanca = sizeof(danca)/sizeof(danca[0]);

const Coreografia aceno[] PROGMEM = {
/*| BD  |  BE  |  PE  |  PD |*/
  {180,6, 135,0, 90,0, 90,0,0},
  {100,6, 135,0, 90,0, 90,0,0},
  {180,6, 135,0, 90,0, 90,0,0},
  {100,6, 135,0, 90,0, 90,0,0},
  {180,6, 135,0, 90,0, 90,0,0},
  {100,6, 135,0, 90,0, 90,0,0},
  {45 ,6, 135,0, 90,0, 90,0,0},
};
constexpr int tamanhoMovimentoAceno = sizeof(aceno)/sizeof(aceno[0]);

const Coreografia alegria[] PROGMEM = {
/*| BD  |  BE  |  PE  |  PD |*/
  {179,3,   0,3, 90,0, 90,0,0},
  {0  ,3, 179,3, 90,0, 90,0,0},
  {0  ,3, 179,3, 90,0, 90,0,0},
  {45 ,5, 135,5, 90,0, 90,0,0},
};
constexpr int tamanhoMovimentoAlegria = sizeof(alegria)/sizeof(alegria[0]);

const Coreografia raiva[] PROGMEM = {
/*| BD  |  BE  |  PE  |  PD |*/
  {0  ,3,   0,3, 90,0, 90,0,0},
  {100,3,   0,3, 90,0, 90,0,0},
  {0  ,3,   0,3, 90,0, 90,0,0},
  {45 ,5, 135,5, 90,0, 90,0,0},
};
constexpr int tamanhoMovimentoRaiva = sizeof(raiva)/sizeof(raiva[0]);

const Coreografia desanimo[] PROGMEM = {
/*| BD  |  BE  |  PE  |  PD |*/
  {180,3,   0,3, 90,0, 90,0,0},
  {0  ,6, 180,6, 90,0, 90,0,0},
  {45 ,5, 135,5, 90,0, 90,0,0},
};
constexpr int tamanhoMovimentoDesanimo = sizeof(desanimo)/sizeof(desanimo);

const Coreografia testeBracoEsquerdo[] PROGMEM = {
/*| BD  |  BE  |  PE  |  PD |*/
  {45 ,0, 170,5, 90,0, 90,0,0},
  {45 ,0,  90,5, 90,0, 90,0,0},
  {45 ,0,   0,5, 90,0, 90,0,0},
  {45 ,0,  90,5, 90,0, 90,0,0},
  {45 ,0, 170,5, 90,0, 90,0,0},
  {45 ,0, 135,5, 90,0, 90,0,0},
};
constexpr int tamanhoMovimentoTesteBracoEsquerdo = sizeof(testeBracoEsquerdo)/sizeof(testeBracoEsquerdo[0]);


/*
 * Executa uma coreografia passo a passo, sem bloquear o loop.
 *
 * ─────────────────────────────────────────────────────────────────────
 * O QUE É UM "PASSO"?
 * ─────────────────────────────────────────────────────────────────────
 *   Pense numa aula de dança: o professor ensina a coreografia em
 *   pequenos trechos — "agora os dois braços para cima", depois
 *   "agora os braços para baixo", depois "agora um pé à frente"...
 *   Cada trecho desses é um PASSO da coreografia.
 *
 *   No Otto é igual: cada elemento do array Coreografia[] descreve UMA
 *   pose (ângulo do braço direito, braço esquerdo, pé esquerdo, pé direito
 *   + a velocidade de cada um). O robô vai para essa pose, espera TODOS
 *   os 4 servos chegarem, e só então avança para o próximo passo.
 *
 *   Uma coreografia como `danca[]` com 35 elementos = 35 poses
 *   encadeadas. O resultado final é o "número de dança" completo.
 *
 *   ┌──────────┐   ┌──────────┐   ┌──────────┐         ┌──────────┐
 *   │ passo 0  │ → │ passo 1  │ → │ passo 2  │ → ... → │ passo 34 │
 *   │ (pose A) │   │ (pose B) │   │ (pose C) │         │ (pose Z) │
 *   └──────────┘   └──────────┘   └──────────┘         └──────────┘
 *    "braços        "braços        "pés juntos"          "pose
 *     p/ cima"       p/ baixo"                            final"
 *
 * ─────────────────────────────────────────────────────────────────────
 * COMO O CÓDIGO EXECUTA UM PASSO (modelo de 2 fases)
 * ─────────────────────────────────────────────────────────────────────
 *
 *   Fase 1 — APLICAR ALVO (só quando não há comando pendente):
 *     Copia da PROGMEM o passo atual e chama moverPara() nos 4 servos.
 *     Isso apenas "seta o destino" — não move nada ainda.
 *     Depois marca enviouComandoMovimento = true, indicando:
 *     "já mandei os servos irem para esse passo, agora estou esperando eles chegarem".
 *
 *   Fase 2 — AGUARDAR CHEGADA (sempre que há comando pendente):
 *     Verifica se os 4 servos estão prontos() (anguloAtual == anguloDestino).
 *     Enquanto não estiverem, retorna false e o loop continua rodando —
 *     quem efetivamente move os servos é atualizarUmPasso(), chamado no loop.
 *     Quando TODOS chegam:
 *       - Se é o último passo → desanexa servos e retorna true (coreografia acabou).
 *       - Senão → passoAtual++ e libera enviouComandoMovimento, para que
 *         no próximo loop a Fase 1 rode de novo com o novo passo.
 *
 *   É como o professor de dança: ele mostra a pose (Fase 1), espera os
 *   alunos executarem (Fase 2), e só então mostra a próxima pose.
 *
 * ─────────────────────────────────────────────────────────────────────
 * POR QUE NÃO USA millis() AQUI
 * ─────────────────────────────────────────────────────────────────────
 *   O avanço é por CHEGADA (pronto()), não por tempo. Os alvos não mudam
 *   enquanto o passo não avança, então reaplicá-los a cada X ms seria
 *   desperdício. A flag enviouComandoMovimento já garante "aplica uma vez
 *   por passo".
 *
 * ─────────────────────────────────────────────────────────────────────
 * QUEM CONTROLA A VELOCIDADE
 * ─────────────────────────────────────────────────────────────────────
 *   O timing do movimento fica em ServoOtto::atualizarUmPasso(), que move
 *   1° a cada msPorGrau ms. Aqui só decidimos "para onde ir".
 *   (msPorGrau maior = movimento mais lento; menor = mais rápido.)
 *
 * ─────────────────────────────────────────────────────────────────────
 * NÃO BLOQUEIA
 * ─────────────────────────────────────────────────────────────────────
 *   Nenhum delay() nem while(). Cada chamada retorna rapidamente.
 *   Se o loop travar (ex: RFID demorando), os servos também travam —
 *   por isso a leitura do RFID deve ser feita com throttle (ex: 50ms).
 *
 * @param CoreografiaARealizar  Ponteiro para o array de passos em PROGMEM
 * @param totalPassos           Número REAL de elementos do array
 *                              (use sizeof(arr)/sizeof(Coreografia) para evitar
 *                              leitura além do fim do array)
 * @return true  → coreografia terminou (todos os passos executados)
 *         false → ainda em andamento (ou esperando servos chegarem)
 */

bool gerenciarCoreografia(const Coreografia* CoreografiaARealizar, int totalPassos){

  static unsigned long ultimoLog = 0;
  if (millis() - ultimoLog >= 500) {
    ultimoLog = millis();
    Serial.print(F("==========================")); 
    Serial.print(F("  EXECUTANDO COREOGRAFIA  ")); 
    Serial.print(F("==========================")); 
    Serial.print(F("Coreografia passo="));
    Serial.print(passoAtual);
    Serial.print(F(" total =")); Serial.print(totalPassos);
    Serial.print(F(" ptr ="));   Serial.println((uint16_t)CoreografiaARealizar, HEX);
  }

  if (enviouComandoMovimento &&
      bracoDireito.pronto() && bracoEsquerdo.pronto() &&
      peDireito.pronto()    && peEsquerdo.pronto())
  {
    enviouComandoMovimento = false;

    if(passoAtual == totalPassos - 1){
      passoAtual = 0;
      bracoDireito.desanexar();
      bracoEsquerdo.desanexar();
      peDireito.desanexar();
      peEsquerdo.desanexar();

      return true;

    } else {
      passoAtual++;
    }
  }

  if (!enviouComandoMovimento) {
    Coreografia movimentoAtual;
    memcpy_P(&movimentoAtual, &CoreografiaARealizar[passoAtual], sizeof(Coreografia));

    bracoDireito.moverPara(movimentoAtual.bracoDireito,  movimentoAtual.velocidadeBracoDireito);
    bracoEsquerdo.moverPara(movimentoAtual.bracoEsquerdo, movimentoAtual.velocidadeBracoEsquerdo);
    peEsquerdo.moverPara(movimentoAtual.peEsquerdo,       movimentoAtual.velocidadePeEsquerdo);
    peDireito.moverPara(movimentoAtual.peDireito,         movimentoAtual.velocidadePeDireito);

    enviouComandoMovimento = true;
  }

  return false;                
}



