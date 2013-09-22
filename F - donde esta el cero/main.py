# -*- coding:utf-8 -*-

if __name__ == '__main__':
    cadena = raw_input()
    while cadena != '':
        if cadena.startswith('0'):
            print '0'
        for i in xrange(1, len(cadena)): # Bucle sobre las cifras a considerar
            test_numero = int(cadena[:i])
            cuenta_cifras = i
            cuenta_posiciones = 1
            bueno = False
            next = test_numero
            while True:
                next += 1
                n_cad = cadena[cuenta_cifras:cuenta_cifras+len(str(next))]
                if n_cad.startswith('0'):
                    print cuenta_posiciones
                    bueno = True
                    break
                elif int(n_cad) != next:
                    break
                else:
                    cuenta_cifras += len(n_cad)
                    cuenta_posiciones += 1
            if bueno:
                break
        try:
            cadena = raw_input()
        except EOFError:
            break
