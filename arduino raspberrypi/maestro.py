from quick2wire.gpio import pins,In
import quick2wire.i2c as i2c
from time import sleep

direccionArduino = 0x8

try:
    while True:
        with pins.pin(0,direction=In) as boton:
            valor = boton.value

            with i2c.I2CMaster() as bus:
                transaccion = i2c.writing_bytes(direccionArduino,boton.value)

                bus.transaction(transaccion)
                
                print('Envio ... ',end='')
                print(valor)

        sleep(0.2)
except KeyboardInterrupt:
    pass