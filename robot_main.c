#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int map(int a0, int a1, int b0, int b1, int a);

int main() {
  DDRB |= (1 << PB1);

	while(1) {
		PORTB |= (1 << PB1);
    _delay_ms(1);
    PORTB &= ~(1 << PB1);
    _delay_ms(19);

    _delay_ms(1000);

    PORTB |= (1 << PB1);
    _delay_ms(2);
    PORTB &= ~(1 << PB1);
    _delay_ms(18);

    _delay_ms(1000);
	}

  return 0;
}

int map(int a0, int a1, int b0, int b1, int a) {
  return b0 + (b1 - b0) * ((a - a0) / (a1 - a0));
}