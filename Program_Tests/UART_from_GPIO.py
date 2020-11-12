# This is used to test Raspberry Pi's Serial Port.
# GPIO BCM14 and BCM15 are shorted to test
# the TX and RX

# Disable serial interface for OS.
# sudo raspi-config
# Interfacing options
# Serial
# Disable for OS, Enable for ports.


# Short TX and RX, BCM14 and BCM15 to test if
# it can send and receive from one pin to another.

# Import modules.
import serial
import time

# Create a serial object.
ser = serial.Serial(
        port="/dev/ttyS0", #Replace ttyS0 with ttyAM0 for Pi1,Pi2,Pi0
        baudrate = 9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
)

try:
    
    # Infinite loop.
    while 1:

        # Ask the user to enter a string.
        toSend=input("Enter a string: ")

        # Send that string to serial port (TX) by encoding
        # it as utf-8 (standard)
        ser.write(toSend.encode())

        # Listen to the receiver (RX)
        # and read the buffer until /n is received
        incoming=ser.readline()

        # Decode the received string using the same
        # encoding used.
        incoming=incoming.decode()

        if incoming:
            print(incoming)

            # Test the string received, type rom in the input to see
            # if rom is received.
            if(incoming=="rom"):
                print("rom received")

except Exception as exp:
    print(str(exp))

print("Program stopped.")
ser.close()

# If the above program worked you can
# connect the TX and RX of pin to other modules
# as long as the their is a common ground.


