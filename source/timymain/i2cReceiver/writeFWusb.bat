avrdude -c usbasp -P USB -p attiny85 -U hfuse:w:0xDD:m -U lfuse:w:0x42:m
avrdude -c usbasp -P USB -p attiny85 -U flash:w:main.hex:i