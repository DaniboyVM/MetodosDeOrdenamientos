#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <vector>
#include <string>
using namespace std;

enum {
    NUM_PRUEBAS = 1000,
    MIN_TAMANO = 10,
    MAX_TAMANO = 1000,
    INCREMENTO = 10
};

void traspasarArreglo(int desordenado[], int arreglo[], int longitud);
void insercion(int n, int a[]);
void burbuja(int n, int a[]) ;
void seleccion(int n,int a[]);

void fusion(int a[],int inicio,int medio,int fin);
void mezcla(int a[],int inicio,int fin);

int particion(int a[],int inicio,int fin);
void ordenamientoRapido(int a[],int inicio,int fin);

void  shell(int n, int a[]);


void escribirCSV(const vector<vector<long long>> &tiempos, int num_tamanos, string nombre);

int main() {
    int desordenado[1000], arreglo[1000];

    // Calculamos el número total de tamaños de arreglo
    int num_tamanos = (MAX_TAMANO - MIN_TAMANO) / INCREMENTO;

    // Matriz para almacenar los tiempoInsercion de ejecución (+1 fila para promedios)
    vector<vector<long long>> tiempoInsercion(NUM_PRUEBAS + 1, vector<long long>(num_tamanos, 0));
    vector<vector<long long>> tiempoBurbuja(NUM_PRUEBAS + 1, vector<long long>(num_tamanos, 0));
    vector<vector<long long>> tiempoSeleccion(NUM_PRUEBAS + 1, vector<long long>(num_tamanos, 0));
    vector<vector<long long>> tiempoMezla(NUM_PRUEBAS + 1, vector<long long>(num_tamanos, 0));
    vector<vector<long long>> tiempoRapido(NUM_PRUEBAS + 1, vector<long long>(num_tamanos, 0));
     vector<vector<long long>> tiempoShell(NUM_PRUEBAS + 1, vector<long long>(num_tamanos, 0));




    srand(time(NULL));

    int columna = 0;
    for (int l = MIN_TAMANO; l < MAX_TAMANO; l += INCREMENTO) {
        long long suma[7]; // Para calcular el promedio
        suma[0]=0;
        suma[1]=0;
        suma[2]=0;
        suma[3]=0;
        suma[4]=0;
        suma[5]=0;
        suma[6]=0;

        for (int i = 0; i < NUM_PRUEBAS; i++) {

            for (int f = 0; f < l; f++) {
                desordenado[f] = 1 + rand() % 1000;
            }

            traspasarArreglo(desordenado, arreglo, l);


            auto inicio = std::chrono::steady_clock::now();
            insercion(l, arreglo);
            auto fin = std::chrono::steady_clock::now();
            auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);


            tiempoInsercion[i][columna] = duracion.count();
            suma[0] += duracion.count(); // Sumar para el promedio

            //--------------------------------------burbuja
            traspasarArreglo(desordenado, arreglo, l);

            inicio = std::chrono::steady_clock::now();
            burbuja(l, arreglo);
            fin = std::chrono::steady_clock::now();
            duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

            tiempoBurbuja[i][columna] = duracion.count();
            suma[1] += duracion.count(); // Sumar para el promedio

            //--------------------------------------seleccion
            traspasarArreglo(desordenado, arreglo, l);

            inicio = std::chrono::steady_clock::now();
            seleccion(l, arreglo);
            fin = std::chrono::steady_clock::now();
            duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

            tiempoSeleccion[i][columna] = duracion.count();
            suma[2] += duracion.count(); // Sumar para el promedio

            //--------------------------------------Mezcla
            traspasarArreglo(desordenado, arreglo, l);

            inicio = std::chrono::steady_clock::now();
            mezcla(arreglo, 0,l);
            fin = std::chrono::steady_clock::now();
            duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

            tiempoMezla[i][columna] = duracion.count();
            suma[3] += duracion.count(); // Sumar para el promedio

             //--------------------------------------Rapido
            traspasarArreglo(desordenado, arreglo, l);

            inicio = std::chrono::steady_clock::now();
            ordenamientoRapido(arreglo,0, l);
            fin = std::chrono::steady_clock::now();
            duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

            tiempoRapido[i][columna] = duracion.count();
            suma[4] += duracion.count(); // Sumar para el promedio

             //--------------------------------------Shell
            traspasarArreglo(desordenado, arreglo, l);

            inicio = std::chrono::steady_clock::now();
            shell(l,arreglo);
            fin = std::chrono::steady_clock::now();
            duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio);

            tiempoShell[i][columna] = duracion.count();
            suma[5] += duracion.count(); // Sumar para el promedio





        }

        // Calcular el promedio y almacenarlo en la última fila de tiempos
        tiempoInsercion[NUM_PRUEBAS][columna] = suma[0] / NUM_PRUEBAS;
        tiempoBurbuja[NUM_PRUEBAS][columna] = suma[1] / NUM_PRUEBAS;
        tiempoSeleccion[NUM_PRUEBAS][columna] = suma[2] / NUM_PRUEBAS;
        tiempoMezla[NUM_PRUEBAS][columna] = suma[3] / NUM_PRUEBAS;
        tiempoRapido[NUM_PRUEBAS][columna] = suma[4] / NUM_PRUEBAS;
        tiempoShell[NUM_PRUEBAS][columna] = suma[5] / NUM_PRUEBAS;
        columna++;
    }

    // Llamamos a la función para escribir el archivo CSV
    escribirCSV(tiempoInsercion, num_tamanos, "tiempo_Insercion.csv");
    escribirCSV(tiempoBurbuja, num_tamanos,"tiempo_Burbuja.csv");
    escribirCSV(tiempoSeleccion, num_tamanos,"tiempo_Seleccion.csv");
    escribirCSV(tiempoMezla, num_tamanos,"tiempo_Mezcla.csv");
    escribirCSV(tiempoRapido, num_tamanos,"tiempo_Rapido.csv");
    escribirCSV(tiempoShell, num_tamanos,"tiempo_Shell.csv");


    cout << "Archivo CSV generado exitosamente con los promedios incluidos.\n";
    return 0;
}




void traspasarArreglo(int desordenado[], int arreglo[], int longitud) {
    for (int m = 0; m < longitud; m++) {
        arreglo[m] = desordenado[m];
    }
}

void insercion(int n, int a[]) {
    int aux, j;
    for (int i = 0; i < n; i++) {
        aux = a[i];
        j = i - 1;
        while (j >= 0 && aux < a[j]) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = aux;
    }
}

void burbuja(int n, int a[]) {
    int tem;
    for(int i=0; i<n; i++ ){
        for(int j=1; j < n-i; j++){
                if(a[j] < a[j-1]){
                   a[j]=a[j-1];
                   a[j-1]=tem;
                }
        }
    }

}

void seleccion(int n,int a[]){
    int minimo, temp;
    for(int i=0; i<n-1; i++){
        minimo=i;
        for(int j=i+1; j<n; j++ ){
            if(a[j] < a[minimo] ){
                minimo=j;
            }
        }
        if(minimo != i){
           temp=a[i];
           a[i]=a[minimo];
           a[minimo]= temp;
        }
    }

}
void fusion(int a[],int inicio,int medio,int fin ){
    int n1=medio-inicio+1;
    int n2= fin-medio;
    int L[n1], R[n2]; //---------------

    for(int i=0; i<n1; i++){//    i=0
        L[i]=a[inicio+i];
    }
    for(int j=0; j<n2; j++){
        R[j]=a[medio+1+j];// agrege +j
    }
    int i=0;
    int j=0;
    int k=inicio;
    while(i< n1 && j<n2){
        if(L[i] <= R[j]){
            a[k]=L[i];
            i=i+1;
        }else{
            a[k]=R[j];
            j=j+1;
        }
        k=k+1;

    }
    while(i < n1){
        a[k]=L[i];
        i=i+1;
        k=k+1;

    }

    while(j < n2){
        a[k]=R[j];
        j=j+1;
        k=k+1;

    }

}

void mezcla(int a[],int inicio,int fin ){
    if(inicio<fin){
        int medio=inicio+((fin-inicio)/2);

        mezcla(a,inicio,medio );
        mezcla(a,medio+1,fin);
        fusion(a, inicio, medio, fin );

    }

}



//Ordenamiento rapido:
int particion(int a[],int inicio,int fin){
    int aux;
    int pivote=a[fin];
    int i=inicio-1;
    for(int j=inicio; j<fin; j++){
        if(a[j]<=pivote){
            i=i+1;

            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
        }

    }
    aux=a[i+1];
    a[i+1]=a[fin];
    a[fin]=aux;
    return i+1;

}


void ordenamientoRapido(int a[],int inicio,int fin){
     if(inicio<fin){
        int pivote;
        pivote=particion(a,inicio,fin);
        ordenamientoRapido(a,inicio, pivote-1);
        ordenamientoRapido(a,pivote+1, fin);
    }

}

void  shell(int n, int a[]){

        for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j=i;
            while( j >= gap &&  a[j-gap] > temp ){
                a[j] = a[j-gap];
                j=j-gap;
            }
            a[j] = temp;
        }
    }

}









// Función para escribir los datos en un archivo CSV
void escribirCSV(const vector<vector<long long>> &tiempos, int num_tamanos, string nombre) {
    ofstream archivo(nombre);
    if (!archivo) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    // Escribir la primera fila con los tamaños de los arreglos
    archivo << "Prueba";
    for (int l = MIN_TAMANO; l < MAX_TAMANO; l += INCREMENTO) {
        archivo << "," << l;
    }
    archivo << "\n";

    // Escribir los tiempos de cada prueba en filas
    for (size_t i = 0; i < NUM_PRUEBAS; i++) {
        archivo << "Prueba " << (i + 1);
        for (int j = 0; j < num_tamanos; j++) {
            archivo << "," << tiempos[i][j];
        }
        archivo << "\n";
    }

    // Escribir la fila de promedios (última fila de `tiempos`)
    archivo << "Promedio";
    for (int j = 0; j < num_tamanos; j++) {
        archivo << "," << tiempos[NUM_PRUEBAS][j];
    }
    archivo << "\n";

    archivo.close();
}
