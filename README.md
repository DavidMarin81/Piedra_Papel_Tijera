# Piedra_Papel_Tijera

Juego de piedra, papel, tijera con Arduino

Compuesto por:
  - Arduino
  - Sensor ultrasónico
  - 3 servomotores
  
Cuando el sensor ultrasónico nota movimiento a menos de 20 cms, crea un número random entre el 1 y el 3.
  - 1 = Piedra
  - 2 = Papel
  - 3 = Tijera
Según el número random, el sensor ultrasónico activará el servomotor asignado para que muestre la opción random (Piedra, papel o tijera)  
