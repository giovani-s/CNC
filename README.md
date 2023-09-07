# Máquina CNC Personalizada a base de lectores DVD
![guita1](/banner.jpg)

## Acerca del proyecto:
Este proyecto documenta la construcción de una máquina CNC utilizando materiales obtenidos de lectores de DVD y componentes electrónicos necesarios para controlar dos motores paso a paso, que son la parte mecanica principal de este "pequeño" proyecto.

## Contexto:
CNC, que significa Control Numérico por Computadora en inglés (Computerized  Numeric Control) es un metodo de control utilizado ampliamente en la industria de la tecnologia, desde pequeños trabajos y aprendizaje en las escuelas hasta la industria pesada como la construccion de coetes espaciales y viviendas, soldadura, etc. En este caso, decidí  construir una pequeña maquina funcional CNC a escala, para mostrar mis habilidades y conocimientos aplicados en situaciones del mundo real.

Es importante destacar que para la contruccion de este proyecto, **no** me he basado en otro proyecto por lo que; la funcionalidad de esta CNC podría no ser común o generica.

## Proceso
- DISEÑO: En el diseño mi objetivo principal fue lograr dos ejes independientes, además como fase inicial decidi que la CNC escribiría con un bolígrafo, dando como resultado :

![2](/general.jpg)

Colocar los ejes superpuestos, para asi formar un plano cartesiano con x e y como coordenadas.

- CONSTRUCCION:
Utilizando 2 drivers A4988 uno para cada motor, procedo a programar una tarjeta microcontroladora mbed. Esto permitió que, al enviar información de las coordenadas a las que debe posicionarse el bolígrafo, los motores se muevan a esta posicion en el nuevo plano cartesiano formado de sobreponer los ejes de cada motor. Gracias a esto, se logró un movimiento en bidimensional permitiendo así, un trazo con el boligrafo.

Se dispone un boligrafor con una punta fina (0.5mm) el cual tiene como proposito hacer visibles los movimientos recibidos como informacion por medio del puerto serial. 

## Funcionamiento:
Para su funcionamiento, se desarrolló un algoritmo de procesamiento de imágenes en Python. Este algoritmo permitió que la aplicación que enviaba los datos de coordenadas al puerto serial de la Mbed seleccionara una imagen de tipo silueta y la procesara. El proceso incluyó un algoritmo de búsqueda en profundidad que seguía la silueta procesada de la imagen original. Siendo esto necesario para que el bolígrafo recorriera el camino una sola vez.

## Resultados y Conclusiones

![guita1](/demo%20guitar1.gif)
![guita2](/demo%20guitar2.gif)

Como resultado, logré crear una máquina CNC funcional que podía trazar una copia de las imágenes en estilo de siluetas. Este proyecto me permitió desarrollar y reforzaar habilidades en programación, diseño mecánico, controladores de motores y procesamiento de imágenes, además de aprender a aplicar estas habilidades en un proyecto práctico.


![circle1](/demo%20circle1.gif)
![circle2](/demo%20circle2.gif)

![1](/protoboard%20con%20drivers%20y%20mbed1.jpg)

![3](/Resultados.jpg)

