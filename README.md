# Carreras De Algoritmos
## [Repositorio GitHub](https://github.com/ColoroGit/ProyectoUnidad3_AyED.git)

Este programa fue elaborado por Tomás Concha, como solución a la problematica entregada por el profesor Manuel Moscoso, para el proyecto de la tercera unidad del curso Algoritmos y Estructiras de Datos. 

Este proyecto tuvo como propósito la replicación de varios algoritmos de ordenamiento conocidos (exponenciales y logarítmicos) y su comparación en cuanto al tiempo que toman en ser ejecutados, en tres contextos distintos que definen una cantidad aproximada de elementos y la forma en que estos están repartidos. Todos estos contextos tienen relación con los contextos de los dos proyectos previos, los cuales puede revisar [aquí](https://github.com/ColoroGit/TheGuardiansTournament.git) y [aquí](https://github.com/ColoroGit/TheGuardianJourney).

Los algoritmos analizados fueron:

    - Selection Sort
    - Bubble Sort
    - Insertion Sort
    - Shell Sort
    - Merge Sort
    - Quick Sort
    - Heap Sort

Y los contextos teóricos en los que serían aplicados eran:

    - Tablero de puntaje: El módulo de tablero de puntaje busca poder ordenar de la
      mejor manera a los jugadores en un tablero que refleje su avance. El avance se
      medirá en tiempo real por lo que es necesario contar con un algoritmo que pueda
      ordenar el tablero posterior a una actualización. Se espera tener hasta un rango
      de 90.000 a 100.000 jugadores en la primera versión.
    - Determinación de camino entre aldeas: En la actualización del viaje de los
      aprendices se establecieron valores para cada camino entre aldeas con el propósito 
      de sumar dificultad. Se está interesado en poder tener un algoritmo que pueda ordenar
      y establecer un ranking entre los posibles recorridos. Al ser un mundo abierto se 
      considera dentro de las combinaciones posible tener entre 50.000 a 70.000 posibles caminos.
    - Dibujo o renderizado de objetos: El siguiente proyecto busca poder entregar un
      panel de inventario que permita a los jugadores comercializar los tesoros o
      productos obtenidos. La idea es poder tener un algoritmo que pueda recibir los
      tesoros o productos de cada jugador y ordenarlos con el propósito de facilitar,
      en base a las preferencias del usuario, la selección para transformar, vender o
      comercializar, y que se pueda ver gráficamente.
      Aquí se considera mantener una variación de objetos totales disponibles entre
      500 y 1000 por cada categoría. Al día de hoy se cuenta con 15 categorías en 
      total que conforman la vestimenta completa de los guardianes.


Además de esto, se nos pidió como individuos hacer un video explicativo en el que se presenta la solución, los distintos aspectos que diferencian a estos algoritmos entre sí, los resultados de los tiempos, y un análisis respecto a cuál o cuáles algoritmos eran más eficientes en cuanto a tiempo en los distintos contextos. 
Si desea ver el recurso audiovisual al que se hace referencia, puede acceder a él haciendo click [aquí](https://drive.google.com/file/d/19-Mp5niduRtpUlDwABy7_abPbaxZivwt/view?usp=sharing).

*Importante a tener en cuenta*: en este proyecto no se usó la versión optimizada de Bubble Sort, y por ende la notacion en el mejor caso cambia a n^2, lo cual aparece distinto en la tabla del video.

Si decide probar el programa, siga las indicaciones del archivo INSTALL. Una vez instalado, usted tiene la opción, si lo desea, de modificar el archivo "Config.txt" para cambiar el rango de valores que se cargarán para cada carrera, siendo en cada linea el primer número el límite inferior, y el segundo, separado por una `,`, el límite superior. Tenga en mente que el programa se demora más en ser ejecutado mientras más valores tenga, e incluso dependiendo de su hardware puede que reciba errores si la cantidad de elementos sobrepasa los 32.000. 
El resto del programa es simplemente la selección de si quiere que el ordenamiento se haga de forma ascendente o descendente, la creación de los arreglos numéricos, y los tiempos que demora cada algoritmo en ordenar cada set numérico con los distintos máximos definidos.