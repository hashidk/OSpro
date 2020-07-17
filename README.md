#                                                                PROYECTO DE SISTEMAS OPERATIVOS 
## Nombre:   
## Antecedentes del problema  
El presente proyecto tratara de simular los algoritmos de planificación de procesos, descritos en el curso y en el capítulo 5 del texto guía “Operating System Concepts” 10th edition by Silberschatz, FCFS, SJF y Round Robind, usando una cola solo para interrupciones y una cola para procesos nuevos. Este proyecto contiene tres ejecutables separados: un simulador del Planificador schedsim, un generador de llegada de proceso schedgen y un programa de estadísticas y tiempos schedstats que produce archivos de datos consolidados utilizados para gráficos de rendimiento.
## Uso de los programas  
### •	schedsim
Para el programa schedsim se debe ejecutar en Ubuntu de la siguiente forma:      
./schedsim  Paramtero1 Parametro2  Parametro\
**Parámetros:**\
Parametro1: Nombre de archivo de entrada donde se almacena una secuencia del proceso de llegada y tiempos de ráfaga.\
Parametro2: El algoritmo elegido: FCFS, SJF y Round Robind(rr).\
Parametro3: El quatun de tiempo Q round-robin (entero positivo), si y solo si el Parametro2 es rr.
### •	schedgen
Para el programa schedsim se debe ejecutar en Ubuntu de la siguiente forma :      
./schedgen Parametro1 Parametro2  Parametro3  Parametro4\
**Parámetros:**\
Parametro1: El total número de procesos N (entero positivo).\
Parametro2: La probabilidad de llegada de un proceso pa (número real entre 0 y 1).\
Parametro3: La probabilidad de longitud de ráfaga de un proceso pb (número real entre 0 y 1).                  
Parametro4: El nombre del archivo que generará la ejecución del programa (Por recomendación debe llamarse “schedtimes.dat” , además este archivo se usara en el  programa   Schedstats).
### •	schedstats
Para el programa schedsim se debe ejecutar en Ubuntu de la siguiente forma:      
./schedstats Parametro1\
**Parámetros:**\
Parametro1: El nombre de archivo de entrada que contiene los tiempos de proceso (el cual  es el mismo que se usa como  Parametro4 en el programa  Schedgen ).
### •	graficas.py
Para el programa grafica.py se debe ejecutar en Ubuntu de la siguiente forma:    
Python  3 graficas.py .\
**Parámetros:**\
El programa que gráfica, recibe el contenido de los archivos: schedturns.dat, schednturns.dat y schedwaits.dat del programa  Schedstats  , pero esto está dentro del programa , así que no se necesita  ingresar ningún parámetro. 

## Resultado típico
