import serial
import time
import datetime
import select

def send_and_receive(command, timeout=10):
    # Envía el comando
    ser.write(command.encode('utf-8'))
    print(f"Sent: {command}")

    # Espera una respuesta
    start_time = time.time()
    response = ""
    while time.time() - start_time < timeout:
        # Usa select para verificar si hay datos disponibles para leer
        rlist, _, _ = select.select([ser], [], [], 0.1)
        if rlist:
            response += ser.read(ser.in_waiting).decode('utf-8')
            if response.endswith('\n'):  # Asume que la respuesta termina con un salto de línea
                break
        time.sleep(0.1)

    if response:
        print(f"Received: {response.strip()}")
    else:
        print("No response received within the timeout period.")


ser = serial.Serial('/dev/ttyACM0', 115200, timeout=0)
time.sleep(2)

print("Configuring date and time using python script...")

current_date_time = datetime.datetime.now()

year = current_date_time.year
month = current_date_time.month
day = current_date_time.day
hour = current_date_time.hour
minute = current_date_time.minute
second = current_date_time.second

print(
    f"Year: {str(year).zfill(2)}, Month: {str(month).zfill(2)}, Day: {str(day).zfill(2)}, Hour: {str(hour).zfill(2)}, minute: {str(minute).zfill(2)}, second: {str(second).zfill(2)}"
)

# ser.write("2".encode())
# time.sleep(2)
# line = ser.readline().decode('utf-8').rstrip()
# print(f"Received: {line}")
# time.sleep(2)

send_and_receive("2")
send_and_receive(str(year))
send_and_receive(str(month).zfill(2))
send_and_receive(str(day).zfill(2))
send_and_receive(str(hour).zfill(2))
send_and_receive(str(minute).zfill(2))
send_and_receive(str(second).zfill(2))
send_and_receive("3")
time.sleep(2)

ser.flush()
print("Serial flushed...")
time.sleep(2)

while ser.is_open:
    ser.close()
    print("Serial closed...")

print("Date and time were configured...")
