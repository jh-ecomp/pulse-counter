#include "Pulse_Counter.h"

#if defined(ESP8266)
    #define INTERRUPT_ATTR ICACHE_RAM_ATTR
#elif defined(ESP32)
	#define INTERRUPT_ATTR IRAM_ATTR
#else
    #define INTERRUPT_ATTR
#endif

volatile int Pulse::last_pulses_count = 0;
volatile int Pulse::pulses_c = 0;
volatile int Pulse::pin_c = 0;

Pulse::Pulse(){
}

void Pulse::begin(int pin){
  pin_c = pin;
	pinMode(pin_c, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(pin_c), pulses_isr, FALLING);
  pulses_c = 0;
  last_pulses_count = 0;
}

int Pulse::pulses(){
	return pulses_c;
}

int Pulse::last_pulses(){
  return last_pulses_count;
}

void Pulse::pulse_reset(){
  last_pulses_count = pulses_c;
  pulses_c = 0;
}

INTERRUPT_ATTR void Pulse::pulses_isr(){
  pulses_c += 1;
}
