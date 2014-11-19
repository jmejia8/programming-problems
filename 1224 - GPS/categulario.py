import sys

num_calles = int(sys.stdin.readline().strip())
direcciones_verticales = sys.stdin.readline().strip().split()



for i in range(num_calles):
    descripcion_calle = sys.stdin.readline().strip().split()

    numero    = descripcion_calle[0]

    direccion = descripcion_calle[1]

    cruces    = descripcion_calle[2:]
