#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void minMax(ull *arr, int size, int &min, int &max);
void print(ull *arr, int size);

int main(void) {
   int tests;

   cin >> tests;

   while(tests--) {
      int size;

      cin >> size;
      ull numbers[size];

      for(int i = 0; i < size; i++) {
         cin >> numbers[i];
      }

      int last_min, last_max;
      int min = -1, max = -1;

      do {
         last_min = min;
         last_max = max;
         minMax(numbers, size, min, max);
         //print(numbers, size);

         int start = min < max ? min : max;
         int end = min > max ? min : max;

         while(start < end) {
            numbers[start] = numbers[start] & numbers[end];
            numbers[end] = numbers[start] & numbers[end];
            start++;
            end--;
         }
      } while(last_min != min || last_max != max);

      cout << numbers[max] << endl;

   }
   
   return 0;
}

void minMax(ull *arr, int size, int &min, int &max) {
   min = 0;
   max = 0;

   for(int i = 1; i < size; i++) {
      if(arr[i] > arr[max]) max = i;
      if(arr[i] < arr[min]) min = i;
   }
}

void print(ull *arr, int size) {
   for(int i = 0; i < size; i++) {
      cout << arr[i] << ' ';
   }

   cout << endl;
}