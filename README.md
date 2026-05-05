# Comparación de Algoritmos de Ordenamiento

Este proyecto implementa diferentes algoritmos de ordenamiento y mide
la cantidad de pasos realizados y el tiempo de ejecución.

### Algoritmos implementados

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Quick Sort
5. Counting Sort

## Requisitos

- Compilador GCC o G++
- Sistema operativo Windows / Linux / Mac
- Terminal o consola

## Compilación

1. Descargar el archivo **ZIP** del repositorio en GitHub.
2. Descomprimir el archivo en una carpeta de tu computadora.
3. Entrar a la carpeta del proyecto hasta encontrar el archivo: main.c y Abrir la consola en esa carpeta
5. Para compilar el programa, en consola, use el siguiente comando:
   ```bash
    g++ main.c -o programa

7. Este comando generará, en la misma carpeta, el archivo ejecutable: programa.exe
8. Una vez compilado el programa, ejecútelo desde la terminal con el siguiente comando:
   ```bash
   .\programa.exe


## Ejemplos de ejecucion

### Ejemplo 1:
Cantidad de números: 100
Intervalo: 1 5

Entrada de numero y generacion de los numeros del array:

<img width="1438" height="166" alt="image" src="https://github.com/user-attachments/assets/49d4e87b-2d9f-4621-8660-d8f7365d5a27" />

Salida:
1. Numeros del array ordenados de menor a mayor
2. Tabla de comparacion de los algoritmos de ordenamiento
   
<img width="1440" height="227" alt="image" src="https://github.com/user-attachments/assets/9cc66bff-36c8-4ded-a5d1-07178294d76a" />



### Ejemplo 2: 
Cantidad de números: 10
Intervalo: 1 20

Entrada de numero y generacion de los numeros del array:

<img width="325" height="120" alt="image" src="https://github.com/user-attachments/assets/e4f3eb4a-3b5a-4e17-bf38-8ec94d17d58d" />

Salida:
1. Numeros del array ordenados de menor a mayor
2. Tabla de comparacion de los algoritmos de ordenamiento
   
<img width="616" height="215" alt="image" src="https://github.com/user-attachments/assets/525858ea-9f5a-4d0a-af19-a9a3398eac89" />


## Descripcion de los algoritmos implementados:

### 1. Bubble Sort
Compara pares de elementos adyacentes del arreglo y los intercambia si están en el orden incorrecto.  
Este proceso se repite varias veces hasta que el arreglo queda completamente ordenado.

**Características:**
- Poco eficiente para grandes cantidades de datos.
- Complejidad temporal promedio: **O(n²)**.

---

### 2. Selection Sort
Funciona buscando el elemento más pequeño del arreglo y colocándolo en la primera posición. Luego busca el siguiente elemento más
pequeño para colocarlo en la segunda posición, y así sucesivamente hasta ordenar todo el arreglo.

**Características:**
- Siempre recorre el arreglo completo para encontrar el mínimo.
- Complejidad temporal: **O(n²)**.

---

### 3. Insertion Sort
Construye el arreglo ordenado de forma progresiva. Toma un elemento del arreglo y lo inserta en la posición correcta dentro
de la parte que ya está ordenada.

**Características:**
- Muy eficiente para arreglos pequeños o casi ordenados.
- Usado como base en algunos algoritmos más avanzados.
- Complejidad temporal promedio: **O(n²)**.

---

### 4. Quick Sort
Algoritmo de tipo **divide y vencerás**.  
Selecciona un elemento llamado **pivote**, divide el arreglo en dos partes
(menores y mayores que el pivote) y luego ordena cada parte de forma recursiva.

**Características:**
- Muy eficiente para grandes conjuntos de datos.
- Complejidad promedio: **O(n log n)**.

---

### 5. Counting Sort
Algoritmo de ordenamiento **no comparativo** que cuenta
cuántas veces aparece cada valor dentro de un rango determinado.  
Luego utiliza esa información para reconstruir el arreglo ordenado.

**Características:**
- Muy rápido cuando el rango de valores es pequeño.
- Complejidad temporal: **O(n + k)**, donde *k* es el rango de valores.






