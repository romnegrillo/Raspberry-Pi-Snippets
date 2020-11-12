# Pin out for external module

# Raspberry Pi -> Module
# BCM14 (TX) -> RX
# BCM15 (RX) -> TX
# 3.3V -> Vcc (If the module is powered from RPi, else skip this.)
# GND -> GND

# If USB port, just replace the port name with
# the name of the USB port.


import serial
import time

# Create a serial object.
ser = serial.Serial(
        port="/dev/ttyS0", 
        baudrate = 9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
)

# Infinite loop.

try:
    while 1:

        # Listen to the receiver (RX)
        # and read the buffer until /n is received.
        incoming=ser.readline()
        incoming=incoming.decode()

        if incoming:
            print("Received from serial: " +incoming)
except Exception as exp:
    print(str(exp))

print("Program stopped.")
ser.close()
