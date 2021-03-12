hex:
	avr-gcc -Os -DF_CPU=16000000 -mmcu=atmega328p -c robot_main.c
	avr-gcc -DF_CPU=16000000 -mmcu=atmega328p -o robot_main.elf robot_main.o -L. -llcd
	avr-objcopy -O ihex robot_main.elf robot_main.hex
	rm robot_main.o
	rm robot_main.elf

flash:
	avrdude -c arduino -p m328p -P /dev/ttyACM0 -U flash:w:robot_main.hex

clear:
	rm robot_main.hex