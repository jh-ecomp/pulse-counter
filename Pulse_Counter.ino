#include "Pulse_Counter.h"


extern "C"{
#include "user_interface.h"
}

#define ATTACHED_PIN 5
#define TIME_IN_MILLIS 1000
#define DO_NOTHING 0
#define PRINT 1

Pulse pc;
os_timer_t mTimer;
volatile int state = DO_NOTHING;


void tCallback(void *tCall);
void usrInit(void);

void setup(){
	Serial.begin(115200);
	pc.begin(ATTACHED_PIN);
  usrInit();
}

void loop(){
  switch(state){
    case PRINT:
      Serial.println(pc.last_pulses());
      state = DO_NOTHING;
      break;
    default:
      break;
  }
	yield();
}

void tCallback(void *tCall){
  state = PRINT;
  pc.pulse_reset();
}

void usrInit(void){
  os_timer_setfn(&mTimer, tCallback, NULL);
  os_timer_arm(&mTimer, TIME_IN_MILLIS, true);
}
