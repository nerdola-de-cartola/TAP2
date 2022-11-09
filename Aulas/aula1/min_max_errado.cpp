#include <iostream>

void minMax(int *arr, int start, int end, int &min, int &max);
void minMax(int *arr, int size, int &min, int &max);

int main(void) {
   int arr[9] = {120, 165, 0, 554, 654, 32, 5, 0, -56};
   int min, max;

   minMax(arr, 9, min, max);

   std::cout << min << " e " << max << std::endl;

   return 0;
}

void minMax(int *arr, int size, int &min, int &max) {
   min = arr[0];
   max = arr[0];

   minMax(arr, 0, size, min, max);
}

void minMax(int *arr, int start, int end, int &min, int &max) {
   if(start == end) {
      min = arr[start];
      max = arr[start];
   } else if(start == end-1) {
      min = arr[start] < arr[end] ? arr[start] : arr[end];
      max = arr[start] > arr[end] ? arr[start] : arr[end];
   } else {
      int mid = (start + end) / 2;
      int min1 = min;
      int min2 = min;
      int max1 = max;
      int max2 = max;

      minMax(arr, start, mid, min1, max1);
      minMax(arr, mid + 1, end, min2, max2);

      if(min1 < min) min = min1; 
      if(min2 < min) min = min2; 

      if(max1 > max) max = max1; 
      if(max2 > max) max = max2;
   }
}