# Pulse Counter for ESP8266/ESP32

Código base para leituras de pulsos em um intervalo de tempo conhecido.

Use pulses() para obter a quantidade de pulsos desde o inicio do ciclo ou last_pulses() para obter a quantidade de pulsos no último ciclo.

A função pulse_reset() deve ser chamada no acionador de final de ciclo.

No exemplo estaremos usando um os_timer configurado para contar ciclos de 1000 milisegundos.

Futuramente a ideia é integrar o timer por software no código de contador de pulsos para generalizar o tempo de leitura e desenvolver lógica para frequêmcia.
Também é preciso adicionar componentes de descretização com intuito de medir rpm e/ou velocidade.
