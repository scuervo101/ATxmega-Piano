# ATxmega-Piano
Synthesizer Piano Player made using the ATxMega128A1u

*Lab8_5 has the piano, all other lab folders were a part of an assignment*

XMega communicates through UART to a serial console on your PC. The console then takes keys (w e r t y u i and 3 4 6 7 8) to emulate a 
piano.

Each key will change the rate at which the DMA transfer a sine wave to the DAC. The DAC then sends the analog data to a speaker built on a analog backpack for the ATxmega.

The ability to change to a triangle wave ia also present. This option interrupts the DMA and changes the location where the DMA is reading data to another location that has the triangle wave.

# PuTTY settings: 
Serial, 128000 baud rate, 8 data bits, 1 stop bit, even parity, no flow control
