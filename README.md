# CNC a base de partes reutilizadas de lectores DVD
![guita1](https://github.com/giovani-s/CNC/blob/main/banner.jpg)

##Acerca del proyecto
Este proyecto documenta la construcción de una maquina CNC utilizando materiales derivados de lectores de DVD, así como tambíen algunos elemetos electronicos necesarios para controlar dos motores paso a paso que son la parte mecanica principal de este "pequeño" proyecto.

CNC por sus siglas en ingles (Computerized  Numeric Control) es un metodo de control utilizado ampliamente en la industria de la tecnologia, desde pequeñas areas en las escuelas hasta la industria pesada como la construccion de coetes espaciales, contrucción de casas, soldadura, etc. En este caso no me fui tan lejos y he decidido construir una pequeña maquina funcional CNC, y con esto pretendo mostrar algunas de mis habilidades y conocimientos aplicados a la vida real.

Es importante destacar que para la contruccion de este proyecto, no me he basado en otro proyecto por lo que; la funcionalidad de esta CNC podría no ser común o generica, y esto se debe a que he creado la logica del funcionamiento por mi cuenta.

## Proceso
-DISEÑO: En el diseño mi objetivo principal fue lograr dos ejes independientes ya que como fase inicial decidi que la CNC escribiera con un boligrafo, dando como resultado :
imagen:
colocar un eje superpuesto al otro para asi formar un plano cartesiano con x e y como coordenadas.

-CONSTRUCCION: Utilizando 2 drivers A4988 uno para cada motor, procedo a programar una tarjeta microcontroladora mbed, de manera que al enviar informacion de las coordenadas a la que debe posicionarse el boligrafo, mueva los motores a esta posicion en el nuevo plano cartesiano que se formó de sobreponer los ejes de cada motor, y gracias a este consiguiedo un movimiento en 2 dimensiones por las que se puede desplazar formando un trazado con el boligrafo.

Se dispone un boligrafor con una punta fina (0.5mm) el cual tiene como proposito hacer visibles los movimientos recibidos como informacion por medio del puerto serial. 
![guita1](https://github.com/giovani-s/CNC/blob/main/protoboard%20con%20drivers%20y%20mbed.jpg)
![guita1](https://github.com/giovani-s/CNC/blob/main/general.jpg)
![guita1](https://github.com/giovani-s/CNC/blob/main/Resultados.jpg)

Para su funcionamiento se crea un algorimo de procesamiento de imagenes en lenguje python que permite al aplicativo que envia los datos de las coordenadas hacia el puerto serial de la Mbed, seleccionar una imagen de tipo silueta y procesarla para que por medio de un algoritmo de busqueda en profundidaad logre recorrer un camino basado en la silueta procesada de la imagen original, necesario para recorrer el camino solo una vez.

##RESULTADOS

![guita1](https://github.com/giovani-s/CNC/blob/main/demo%20guitar1.gif)
![guita2](https://github.com/giovani-s/CNC/blob/main/demo%20guitar2.gif)


![circle1](https://github.com/giovani-s/CNC/blob/main/demo%20circle1.gif)
![circle2](https://github.com/giovani-s/CNC/blob/main/demo%20circle2.gif)

##CONCLUSIONES

##Resultaados

##Conclusiones
