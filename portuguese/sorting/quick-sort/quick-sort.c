
#include <stdio.h>
#include <math.h>
#include <time.h>

#define n 10000

int array[n];

 //produz um array ordenado de forma decrescente
 void decrescente() {
    int i;
    for (i = 0; i < n; i++){
       array[i] = n - 1 - i;
    }
 }

//mostrar elementos do array
void mostrar() {
   printf("[ ");
 
   int i;
   for (i = 0; i < n; i++) {
      printf("%d ", array[i]);
   }
 
   printf("] \n");
}

void swap(int i, int j) {
   int temp = array[i];
   array[i] = array[j];
   array[j] = temp;
}
 
//lógica do quicksort
void quicksortRec (int esq, int dir) {
   int i = esq, j = dir;
   int pivo = array[(dir+esq)/2];
   while (i <= j) {
      while (array[i] < pivo) i++;
      while (array[j] > pivo) j--;
      if (i <= j) {
         swap(i, j);
         i++;
         j--;
      }
   }
   if (esq < j)  quicksortRec(esq, j);
   if (i < dir)  quicksortRec(i, dir);
}
 
//algoritmo de ordenacao
void quicksort() {
   quicksortRec(0, n-1);
}

void main() {
   srand(time(NULL));
   decrescente();
   mostrar();     
   clock_t comeco = clock();
   quicksort();
   clock_t fim = clock();
   clock_t total = (fim - comeco);
 
   mostrar();
   printf("Tempo para ordenar: %f ms.", (float)total);
}
