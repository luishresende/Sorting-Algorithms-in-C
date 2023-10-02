#include <stdio.h>
#include <stdlib.h>
#include "Auxiliar.h"

int particione(int *numbers, int esq, int dir){
    int random_index = rand() % (dir - esq + 1) + esq;
    int x = numbers[random_index];

    numbers[random_index] = numbers[esq];
    numbers[esq] = x;

    int up = dir;
    int down = esq;


    while(down < up){
        while(down < dir && numbers[down] <= x){
            down++;
        }
        while(numbers[up] > x){
            up--;
        }
        if(down < up){
            int aux = numbers[down];
            numbers[down] = numbers[up];
            numbers[up] = aux;
        }
    }

    numbers[esq] = numbers[up];
    numbers[up] = x;
    return up;
}

void quick_sort_execute(int *numbers, int esq, int dir){
    int i;
    if(dir > esq){
        i = particione(numbers, esq, dir);
        quick_sort_execute(numbers, esq, i-1);
        quick_sort_execute(numbers, i+1, dir);
    }
}

void merge(int *numbers, int p, int q, int r){
    int i, j, k;
    int *w = (int *)malloc((r - p + 1) * sizeof(int));

    i = p;
    j = q + 1;
    k = 0;

    while (i <= q && j <= r) {
        if (numbers[i] <= numbers[j]){
            w[k++] = numbers[i++];
        }else{
            w[k++] = numbers[j++];
        }

    }

    while (i <= q){
        w[k++] = numbers[i++];
    }

    while (j <= r){
        w[k++] = numbers[j++];
    }

    for (i = p, k = 0; i <= r; i++, k++) {
        numbers[i] = w[k];
    }
    free(w);
}

void merge_sort_execute(int *numbers, int esq, int dir){
    if(esq < dir){
        int meio = (esq + dir) / 2;
        merge_sort_execute(numbers, esq, meio);
        merge_sort_execute(numbers, meio+1, dir);
        merge(numbers, esq, meio, dir);
    }
}

void trocar(int *a, int *b) {
    int tempvar = *a;
    *a = *b;
    *b = tempvar;
}

void heap_sort_execute(int *numbers, int n, int i){
    int greatest = i;
    int leftSide = 2 * i + 1;
    int rightSide = 2 * i + 2;

    if (leftSide < n && numbers[leftSide] > numbers[greatest])
      greatest = leftSide;

    if (rightSide < n && numbers[rightSide] > numbers[greatest])
      greatest = rightSide;

    if (greatest != i) {
      trocar(&numbers[i], &numbers[greatest]);
      heap_sort_execute(numbers, n, greatest);
    }
}

// Function to get the largest element from an array
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void radix_sort_execute(int numbers[], int n, int place) {
      int output[n + 1];
      int max = (numbers[0] / place) % 10;

      for (int i = 1; i < n; i++) {
        if (((numbers[i] / place) % 10) > max)
          max = numbers[i];
      }
      int count[max + 1];

      for (int i = 0; i < max; ++i)
        count[i] = 0;

      for (int i = 0; i < n; i++)
        count[(numbers[i] / place) % 10]++;

      for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

      for (int i = n - 1; i >= 0; i--) {
        output[count[(numbers[i] / place) % 10] - 1] = numbers[i];
        count[(numbers[i] / place) % 10]--;
      }

      for (int i = 0; i < n; i++)
        numbers[i] = output[i];
}
