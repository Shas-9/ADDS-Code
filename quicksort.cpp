#include<iostream>
#include<cmath>

void interchange(int* a, int* b) {
  int c = *a;
  *a = *b;
  *b = c;
}

int divide(int array[], int start, int end) {
  // pivot is last element
  int i = start - 1;
  int pivot = array[end];

  // j=0; i=-1; 
  // whenever array[j] is less than the pivot, increment i and swap array[i] with array[j]
  // this will make sure array[i] is always greater than the pivot when incremented
  // so swapping the next element<pivot with array[i] results in everything less than 
  // the pivot being on the left and everything greater moved to the right

  for (int j = start; j <= end; j++) {
    if (array[j] < pivot) {
      i++;
      interchange(&array[i], &array[j]);
    }
  }
  // increment i to get the "set" position of pivot
  i++;
  interchange(&array[i], &array[end]);

  return i;
}

void sort(int array[], int start, int end) {
  int pivot_index = divide(array, start, end);

  if (start < end) {
    // when pivot is at index = 0 it gets swapped with the last element of the array, causing errors
    if (pivot_index != 0) {
      sort(array, start, pivot_index-1);
    }
    
    // when pivot is the last element of subarray, it gets swapped with the next element, causing errors
    if (pivot_index < end) {
      sort(array, pivot_index+1, end);
    }
  }
}


int median_array(int array[], int n) {
  if (n<1 || n%2==0) {
    return 0;
  }

  sort(array, 0, n-1);

  int median_position = floor(n/2) + 1;

  int median = array[median_position];

  return median;
}


int main() {
  int n = 15;
  int array[15] = {3, 4, 5, 6, 7, 8, 9, 11, 12, 14, 15, 17, 18, 19, 20};

  std::cout << "Median: " << median_array(array, 15) << "\n";

  for (int i=0; i<n; i++) {
    std::cout << array[i]  << " ";
  }
  
  return 0;
}