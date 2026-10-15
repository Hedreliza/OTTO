#include <DFRobotDFPlayerMini.h>

#define AUDIO_LIGA 1
#define AUDIO_DESLIGA 2
#define AUDIO_APLAUSO 3
#define AUDIO_ERROU 4
#define AUDIO_DANCA 5

#define PIN_DFPlayer_RX     45 
#define PIN_DFPlayer_TX     49
#define DFPlayer_BUSY       4

extern DFRobotDFPlayerMini myDFPlayer;

void configurarDFPlayer();
void tocarAudio(int audio);
void verificarDFPlayer();