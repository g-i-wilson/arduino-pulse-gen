import sys
import serial

print("------------------------------")
print(" Arduino 500ns PRF Generator")
print("------------------------------")
print()

io = serial.Serial(port=sys.argv[1], baudrate=115200)

while True:
	io.write( bytearray(input("Enter PRF [ms]: "),'utf-8') )
	io.flush()
	print( io.readline().decode('utf-8') )
