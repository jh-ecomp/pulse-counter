#include "Pulse_Counter.h"


extern "C"{
#include "user_interface.h"
}

#define ATTACHED_PIN 5
#define TIME_IN_MILLIS 1000

Pulse pc;
os_timer_t mTimer;


void tCallback(void *tCall);
void usrInit(void);

void setup(){
	Serial.begin(115200);
	pc.begin(ATTACHED_PIN);
}

void loop(){
	Serial.println(pc.pulses());
 //Serial.println(pc.last_pulses());
	yield();
}

void tCallback(void *tCall){
    pc.pulse_reset();
}

void usrInit(void){
    os_timer_setfn(&mTimer, tCallback, NULL);
    os_timer_arm(&mTimer, TIME_IN_MILLIS, true);
}
