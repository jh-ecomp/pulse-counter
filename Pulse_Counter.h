#ifndef PULSECOUNTER

#define PULSECOUNTER


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class Pulse{
public:
  Pulse();
  void begin(int pin);
  int pulses();
  int last_pulses();
  void pulse_reset();
  
private:
	static volatile int pulses_c;
	static volatile int last_pulses_count;
  static volatile int pin_c;
	static void pulses_isr();
};

#endif
