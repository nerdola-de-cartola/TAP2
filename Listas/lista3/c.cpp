#include <bits/stdc++.h>

using namespace std;

int main(void) {
   int tests;

   cin >> tests;

   while(tests--) {
      int size;

      cin >> size;
      int arr[size];

      for(int i = 0; i < size; i++) {
         cin >> arr[i];
      }

      for(int i = 0; i < size; i++) {
         int xor_sum = 0;

         for(int j = 0; j < size; j++) {
            if(j == i) continue;
            xor_sum = xor_sum ^ arr[j];
         }

         if(xor_sum == arr[i]) {
            cout << arr[i] << endl;
            break;
         }
      }

   }

   return 0;
}