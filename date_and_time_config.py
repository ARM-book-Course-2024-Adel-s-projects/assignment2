import serial
import time
import datetime

ser = serial.Serial('/dev/ttyACM0', 115200)
time.sleep(2)

print("Configuring date and time using python script...")

current_date_time = datetime.datetime.now()

year = current_date_time.year
month = current_date_time.month
day = current_date_time.day
hour = current_date_time.hour
minute = current_date_time.minute
second = current_date_time.second

ser.write("2".encode())
time.sleep(0.5)
ser.write(str(year).encode())
time.sleep(0.5)
ser.write(str(month).encode())
time.sleep(0.5)
ser.write(str(day).encode())
time.sleep(0.5)
ser.write(str(hour).encode())
time.sleep(0.5)
ser.write(str(minute).encode())
time.sleep(0.5)
ser.write(str(second).encode())
time.sleep(0.5)

ser.flush()
print("Serial flushed...")
time.sleep(2)

while ser.is_open:
    ser.close()
    print("Serial closed...")

print("Date and time were configured...")