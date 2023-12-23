from asyncio.windows_events import NULL
import cv2
import numpy as np
import serial
import time
import io

# Cargar la imagen en escala de grises
image = cv2.imread('diana.jpg', cv2.IMREAD_GRAYSCALE)

# Redimensionar la imagen
image = cv2.resize(image, (100, 100))

# Aplicar un umbral para obtener una imagen binaria
_, thresh = cv2.threshold(image, 180, 255, cv2.THRESH_BINARY)
# Aplicar un filtro Gaussiano para suavizar la imagen y quitar imperfecciones
blurred = cv2.GaussianBlur(thresh, (1,1), 1)

# Detectar los bordes usando el operador Laplaciano
edges = cv2.Laplacian(blurred, cv2.CV_8U, ksize=1)

# Encontrar los contornos en los bordes detectados
contours, hierarchy = cv2.findContours(edges.copy(), cv2.RETR_EXTERNAL , cv2.CHAIN_APPROX_NONE )

# Mostrar la imagen redimensionada
#cv2.imshow('Imagen redimensionada',img_array )


ser = serial.Serial('COM8',9600)

time.sleep(1)
print(ser)
const=0
# Crear una imagen en blanco del mismo tamaño que la imagen original
border_image = np.ones_like(image)*255

visitados = np.zeros_like(border_image, dtype=bool)

for cnt in contours:
    
    print(const)

    # Dibujar los contornos en la imagen en blanco
    cv2.drawContours(border_image, contours,const, (0), thickness=1)
    
    # Convertir la imagen en una matriz de numpy
    img_array = np.array(border_image)

    # Crear una pila para almacenar los elementos a visitar
    pila = []
    
    auxpila=(0,0)

    for i in range(img_array.shape[0]):
        for j in range(img_array.shape[1]):

            if img_array[i, j] == 0:

                # Realizar la acción deseada aquí
                pila.append(tuple((i,j)))
                break

        if img_array[i, j] == 0:
            break
            
    punto='xx|'+str(pila[0][0])+'|y|'+str(pila[0][1])+'|\n'

    time.sleep(2)
    ser.write(punto.encode('UTF-8'))

    print("punto inicio: %s",punto)
    
    # Realizar la búsqueda en profundidad de manera iterativa
    while pila:
        
        # Obtener el siguiente elemento a visitar
        i, j = pila.pop()

        # Verificar si la posición actual está dentro de la matriz y si el elemento no ha sido visitado
        if 0 <= i < img_array.shape[0] and 0 <= j < img_array.shape[1] and not visitados[i, j]:

            # Marcar el elemento como visitado
            visitados[i, j] = True

            # Verificar si el elemento tiene el valor 0
            if img_array[i, j] == 0:

                # hacer lo que quiera con los puntos negros
                punto='xx|'+str(i)+'|y|'+str(j)+'|\n'

                # Enviar datos al Arduino
                ser.write(punto.encode('UTF-8'))

                time.sleep(0.09)

                if(i%100==0 or j%100==0):
                   print(punto)

                # Agregar los elementos adyacentes a la pila
                pila.append((i - 1, j))
                pila.append((i + 1, j))
                pila.append((i, j - 1))
                pila.append((i, j + 1))
                # diagonales
                pila.append((i - 1, j-1))
                pila.append((i + 1, j+1))
                pila.append((i+1, j - 1))
                pila.append((i-1, j + 1))
        
    const+=1
        
#Mostrar la imagen redimensionada
cv2.imshow('Imagen redimensionada',img_array )

ser.close()
cv2.waitKey(0)
cv2.destroyAllWindows()

