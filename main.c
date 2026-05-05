#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAX 1000 //un int tiene 4 bytes

typedef struct{//lo definimos como un tipo de dato
    char nombre[100];
    long pasos;//long 4 u 8 bytes
    long tiempo;
}resultado;

void BubbleSort(int arr[], int n, resultado *r){
    r->pasos=0;//definimos la cantidad como 0
    for(int i=0;i<n-1;i++){//en cada bucle un elemento ya estara ordenado
        for(int j=0; j<n-1-i; j++){//por cada bucle que pase habra menos 1 elemento que necesita ser ordenado
            r->pasos++;// contamos comparaciones
            if(arr[j]>arr[j+1]){

                r->pasos += 3; // en el intercambio se realizan 3 asignaciones
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//ordenamiento por insercion
//se inspira de las cartas en la mano
//divide la lista em 2 partes, ordenada y no ordenada

//algoritmo
//toma el siguiente elemento de la parte no ordenada
//lo compara con los elementos anteriores
//lo inserta en la posicion correcta desplazando a los demas
void InserionSort(int arr[], int n, resultado *r){
    r->pasos = 0;

    for(int i=1; i<n; i++){//empieza del 2do elemento
        int actual = arr[i];//elemnto a comparar
        r->pasos++; // asignación
        int j=i-1; //indice de los elementos de la parte ordenada

        //vamos a desplazar mientras haya elementos en la parte ordenada y el elemnto actual sea menor al elemento de la pte ordenada
            while(j>=0 && actual<arr[j]){//usamos una variable ya que cambiara de lugar => si indice cambiara

                    r->pasos++;//por cada comparacion sumamos 1

                    arr[j+1]=arr[j];//desplazamos el elemento mayor un espacio a la derecha/parte no ordenada => habra dos sitios con el mismo numero
                     r->pasos++; //por cada asignacion sumamos 1
                    j--;//pasamos a comparar con el elemento anterior de la parte ordenada
            }
            //j+1 ya que en la pos j-1 ya no cumple con las cond de intercambio, el ultimo que cumplia es j
            arr[j+1] = actual;
            r->pasos++;

    }


}

//P1 -> [8 | 3 5 2] <- se considera el 1er elemento como ya ordenado
//P2 -> [3 8 | 5 2]  <- comparamos el 2do elemento con el la parte ord de izq a derecha,
//si es mayor se coloca despues del elemento y si es mayor toma su lugar y desplaza

//P3 -> [3 5 8 | 2] <- comparamos con el sig. 5<8 => toma su lugar y desplaza, ahora comparamos con con el sig(3) no es menos => se queda
//P4 -> [2 3 5 8]<- de la misma manera


//Selection Sort - Ord. por seleccion


//Consiste en buscar el elemento mas pequeno y colocarlo en la posicion correcta, esto en cada iteracion

//Buscar el elemento mínimo de la parte no ordenada
//Intercambiarlo con el primer elemento de esa parte
//Expandir la parte ordenada (con los nuevos 1ros elementos de la parte no ordenada)

void SelectionSort(int arr[], int n, resultado *r){
     r->pasos = 0;

    for(int i=0; i<n-1; i++){//en cada iteracion va haber un numero ordenado
        int min = i;//indica el indice del primer elemento de los elementos no ordenados y tambien lo consideramos como el de menor valor

        for(int j=i+1; j<n; j++){
            r->pasos++; //comparacion
            if(arr[min]>arr[j]){
                min = j;//nueva posicion minima es j
                r->pasos++;  // asignacion
            }
        }

        if(min != i){
            r->pasos += 3; //intercambio
            int temp = arr[i];
            arr[i] = arr[min];//lo colocamos como primero
            arr[min] = temp;// y el 1ro en la pocision del menor
        }
    }

}
//64 25 12 22 11 < - aun no hay parte ordenada
//11 es el menor, inter 11 y 64
// 11 | 25 12 22 64 <- ahora 11 es la parte ordenada
// 11 | 12 25 22 64 <- elem minimo es 12, inter de 12 y 25
// 11 12 |  22 25 64


//QUICK SORT
//por ahora solo se toma en cuenta a las comparaciones como pasos
int particionar(int arreglo[], int inicio, int fin, resultado *r) {

    int pivote = arreglo[fin];
    int indiceMenor = inicio - 1;

    for (int j = inicio; j < fin; j++) {

        r->pasos++; // comparación arr[j] < pivote

        if (arreglo[j] < pivote) {

            indiceMenor++;

            r->pasos += 3;

            int temporal = arreglo[indiceMenor];
            arreglo[indiceMenor] = arreglo[j];
            arreglo[j] = temporal;
        }
    }

    r->pasos += 3;
    int temporal = arreglo[indiceMenor + 1];
    arreglo[indiceMenor + 1] = arreglo[fin];
    arreglo[fin] = temporal;

    return indiceMenor + 1;
}

void quickSort(int arreglo[], int inicio, int fin, resultado *r) {

    r->pasos++;  // comparación inicio < fin
    if (inicio < fin) {

        int posicionPivote = particionar(arreglo, inicio, fin, r);

        quickSort(arreglo, inicio, posicionPivote - 1,r);
        quickSort(arreglo, posicionPivote + 1, fin,r);
    }
}

void QuickSortWrapper(int arr[], int n, resultado *r){//envoltura

    r->pasos = 0;
    quickSort(arr, 0, n-1, r);
}


//Couting Sort

// cuenta cuántas veces aparece cada número y luego reconstruye el arreglo ordenado usando esos conteos
//funciona mejor cuando los numeros del arreglo son enteros y son pocos

//Usa 2 o 3 arreglos
//A: arreglo original
//C: arreglo conteo - cuenta cuantas veces aparece cada numero
//B: es donde se recontruye de forma ordenada el arreglo

//aqui no se realizan comparaciones
//es el mas rapido si el rango es pequeno
void CountingSort(int arr[], int n, resultado *r){
    r->pasos = 0;

    int max = 0;
    //hallamos el valor maximo
    for(int i=0; i<n; i++){

        r->pasos++;//comparacion
        if(arr[i]>max){
            r->pasos++;
            max=arr[i];//asignacion
        }
    }
    //asui se alamacena el numero de ocurrencias de cada numero del array original
    //los indices serian los numeros
    int arrayConteo[max+1];



    //inicializamos en 0


    for(int i = 0; i <= max; i++) {
        arrayConteo[i] = 0;
        r->pasos++;
    }

    //los valores son representados por el indice y la cantidad que se repiten por el contenido
    /*for(int i=0; i<max+1; i++){
        //recorremos el array original para buscar elementos que sean iguales al indice
        //si lo son aumentamos la cantidad en el arrayConteo
        for(int j=0; j<n; j++){
            if(i == arr[j]){
                arrayConteo[i]++;
            }
        }
    }*/


    // contar ocurrencias


    //otra forma mas simple
    //recorremos el array original y si existe la posicion como elemento del otro array sumamos
     for(int j=0; j<n; j++){
        arrayConteo[arr[j]]++;
        r->pasos++;//asignar/contar ocurrencias
    }



    //reconstruimos el arreglo original de forma ordenada


    //indice que guia la posicion en el arreglo orig.
    int indice  = 0;

    //vamos a revisar cada numero posible desde 0 hasta max
    for(int i=0; i<=max ; i++){

            //mientras ese numeros se repita por lo menos 1 vez dentro del array oirg
            //este while lo que hace es ir copiando un mismo numero x veces en el arr orig
            while(arrayConteo[i]>0){
                    r->pasos++;//comparacion
                    arr[indice] = i;
                    r->pasos++;//asignacion ordenada al nuevo array

                    indice++;//avanzamos a la sig posicion en el array original
                    arrayConteo[i]--; //el numero i actual tiene se repite -1 veces ya que ya lo copiamos en el arr original
                    r->pasos++;// reduccion de repetidos en el array de conteo
            }
    }
}

//para medir el tiempo de cada algoritmo, necesitamos medir cada uno
//y como estos estab en funciones tenemos que pasar las funciones
//y lo que vamos a pasar va hacer la direc. de memoria de las funciones
//el orden es el sig <valor q devuelve>, nombre providional de la funcion, parametros
//luego los parametros que pasaremos a esa funcion
long MedirTiempo(void (*algOrdenamiento)(int[],int,resultado*), int arr[], int n, resultado *r){
        struct timespec inicio, fin;//definimos los tip de datos

        clock_gettime(CLOCK_MONOTONIC, &inicio);//medimos el t y asignamos

        algOrdenamiento(arr,n,r);//usamos el algoritmo de ordenamiento

        clock_gettime(CLOCK_MONOTONIC, &fin);//medimos el t y asignamos

        long segundos = fin.tv_sec - inicio.tv_sec;//obtenemos la cant de segundos
        long nanosegundos = fin.tv_nsec - inicio.tv_nsec;// obt la cant de nanosegundos

        return segundos* 1000000000 +nanosegundos;//devolvemos el tiempo total en nanosegundos

}

void ordPorTiempo(resultado arr_res[],int cantAlg){

    for(int i=0; i<cantAlg-1; i++){
            for(int j=0; j<cantAlg-1-i; j++){

                if(arr_res[j].tiempo>arr_res[j+1].tiempo){
                    resultado temp = arr_res[j];
                    arr_res[j] = arr_res[j+1];
                    arr_res[j+1]  = temp;
                }

            }
    }
}

int main()
{
    //ENTRADA
    int total, min, max;
    freopen("input.txt","r",stdin);
    printf("\nCantidad de numeros: ");
    scanf("%d",&total);//el 1er argumento(%d) decide el formato que va entrar, en este caso decimal integer
                  //usamos el ampersand & para obtener la direccion de memoria

    //intervalo para la generacion de numeros
    printf("Intervalo: ");
    scanf("%d", &min);
    scanf("%d", &max);
    printf("\ncantidad de numeros: %d",total);
    printf("\nmin: %d",min);
    printf("\nmax: %d",max);


    int array_numeros[total];//c permite definir el tamano del array en tiempo de ejecucion


    //generamos el array de nros aleatorios
    srand(time(NULL)); // inicializa semilla
    for(int i=0; i<total; i++){
        //int numero = rand()%(max); //si max fuera 10 el rango es de 0 a 9
        //generamos el numero
        int numero  = rand()%(max - min + 1) + min; //nro definido en un intervalo ej. (5-3+1) + 3
                                            // entonces el numero generado sera uno entre 0 y 2, es decir la diferencia o la distancia entre min y max
                                            // a eso le sumamos el minimo y obtenemmos numeros mayores a el minimo mas la diferencia=> minimo + [0,1,2]
        array_numeros[i] = numero;
    }

    printf("\n");
    printf("numeros generados: \n");
    for(int i=0; i<total; i++){
        printf("%d ",array_numeros[i]);
    }


    //tenemos que realizar una copia del array para poder ordenar la copia
    //y mantener la posicion de los nros orignales y pasarlos al siguiente algoritmo(por medio de otra copia)
    //para almacenar los resultados de cada algoritmo usaremos un estruct con el nombre del alg, cant de pasos y tiempo de ejecucion
    int copia[total];
    //usamos mempcy para copiar los elementos o solo un bucle
    //memcpy(destino,origen,tamano en bytes);
    for(int i=0; i<total; i++){
        copia[i] = array_numeros[i];
    }

    int cantAlg = 5;
    //ahora necesitamos un lugar donde guardar los resultados para cada algoritmo
    resultado res[cantAlg];//4 algoritmos


    //BUbble sort res[0]

    //res[0].nombre = "Bubble Sort";
    strcpy(res[0].nombre, "Bubble Sort");//copiamos la cadena en el arreglo
    //BubbleSort(copia,total,&res[0]);//pasamos la dir de memoria y se almacenan la cantidad de pasos
    res[0].tiempo = MedirTiempo(BubbleSort, copia, total, &res[0]);//dentro del algoritmo ya se guardan los pasos
    //asi que hasta este punto ya tenemos todo lo que necesitamos de bubble sort


    //Insertion sort res[1]
    memcpy(copia,array_numeros,sizeof(array_numeros));//copiamos de nuevo el array orig a la copia que acaba de ordenarse
    strcpy(res[1].nombre, "Insertion Sort");
    res[1].tiempo = MedirTiempo(InserionSort,copia, total, &res[1]);


    //Selection Sort res[2]
    memcpy(copia,array_numeros,sizeof(array_numeros));
    strcpy(res[2].nombre, "Selection Sort");
    res[2].tiempo = MedirTiempo(SelectionSort,copia, total, &res[2]);

    //Quick Sort res[3]
    memcpy(copia, array_numeros, sizeof(array_numeros));
    strcpy(res[3].nombre, "Quick Sort");
    res[3].tiempo = MedirTiempo(QuickSortWrapper, copia, total, &res[3]);//pasamos el wrapper ya que la funcion original tiene 3 parametros

    //Couting Sort res[4]
    memcpy(copia, array_numeros, sizeof(array_numeros));
    strcpy(res[4].nombre, "Counting Sort");
    res[4].tiempo = MedirTiempo(CountingSort, copia, total, &res[4]);

    //hacemos esto mismo para los siguientes algoritmos y al final comparamos sus tiempos y ordenamos respecto a eso..


    //ahora ordenamos los algoritmos de acuerdo a su tiempo

    printf("\n");
    printf("\nnumeros ordenados: \n");
    for(int i=0; i<total; i++){
        printf("%d ",copia[i]);
    }

    ordPorTiempo(res,cantAlg);


    //IMPRIMIR en orden los algoritmos
    printf("\n");
    printf("\nPosicion\tAlgoritmo\tPasos\tTiempo(ns)\n");
    for(int i=0; i<cantAlg; i++){
        printf("%d\t\t%s\t%ld\t%ld\n",
        i+1,
        res[i].nombre,
        res[i].pasos,
        res[i].tiempo);

    }

    return 0;
}
