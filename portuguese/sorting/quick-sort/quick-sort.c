

void swap(int i, int j) {
   int temp = array[i];
   array[i] = array[j];
   array[j] = temp;
}
 
 
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
 
void quicksort() {
   quicksortRec(0, n-1);
}
