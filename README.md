Este programa en C analiza una matriz cuadrada binaria (coeficientes de 0s y 1s) y encuentra la secuencia más larga de 1s de sus diagonales en dirección de derecha a izquierda, desde la esquina inferior derecha hacia la esquina superior izquierda. El proceso comienza con la lectura de un archivo de texto plano que contiene la matriz, el cual es proporcionado por el usuario. Para manejar esta entrada, el programa utiliza funciones como fopen para abrir el archivo y fgets para leer cada línea. Cada línea se divide usando strtok, lo que permite separar los valores de cada coeficiente de la matriz. Estos valores se validan para asegurar que sean estrictamente 0 o 1, y si se encuentra algún valor no binario, el programa muestra un mensaje de error y termina. Además, el código verifica que la matriz sea cuadrada, si no cumple esta condición, también se genera un error y el programa se detiene.

Una vez que la matriz se ha leído y validado correctamente, se almacena en una matriz de tamaño fijo definido por la constante TAMANO y después imprime la matriz. La parte central del código es la función encontrar_diagonal_mas_larga, que se encarga de recorrer todas las diagonales de la matriz buscando la secuencia más larga de 1s. Mientras se recorre la matriz, un contador registra el valor de las secuencias de 1s, reiniciándose cada vez que se encuentra un 0. El valor más alto registrado se devuelve como resultado.

Finalmente, el programa muestra el valor de la secuencia más larga de 1s encontrada en las diagonales de la matriz. 

Se utiliza el compilador GCC (GNU Compiler Collection) para generar un ejecutable (gcc T1_C34587.c -o t1). Al ejecutar el programa, este pedirá el nombre del archivo de texto plano del cual se extrae la matriz y, seguidamente, imprimirá la matriz del archivo junto con la secuencia más larga de 1s. 

En la siguiente imagen se puede observar ejemplos de salidas del programa:

![Ejemplos de salidas del programa](https://github.com/andrxsmz/Tarea1-IE0117/raw/86dce8dadd28833d630973eba2500ec20592ad6e/T1_C34587.png)
