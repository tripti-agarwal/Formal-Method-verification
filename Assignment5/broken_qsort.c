#include "klee/klee.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int *array, int low, int high) {
  
  int pivot = array[0];
  
  int i = (low - 1);
  
  if(pivot < 5)	return i;
  
  else {
	  for (int j = low; j < high; j++) {
	    if (array[j] <= pivot) {
	      i++;
	      swap(&array[i], &array[j]);
	    }
	  }
	  swap(&array[i + 1], &array[high]);
	  return (i + 1);
  }
}

void quickSort(int *array, int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}



void test(int *array, unsigned nelem) {
  int *temp1 = malloc(sizeof(*array) * nelem);

  memcpy(temp1, array, sizeof(*array) * 5);
  

  quickSort(temp1,0, 4);
  
  for (unsigned i = 0; i != (nelem-1); ++i)
    assert(temp1[i] <= temp1[i+1]);
  

  free(temp1);
  
}

int main() {
  int input[5] = {5, 4, 3, 2, 1};

  klee_make_symbolic(&input, sizeof(input), "input");
  test(input, 5);

  return 0;
}
