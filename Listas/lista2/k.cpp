#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
   int n, total, num_matches;
   int i, j, k;
   int p1, p2;

   cin >> n;
   total = pow(2, n);
   int arr[total];

   for(i = 0; i < total; i++) {
      cin >> arr[i];
   }


   num_matches = total / 2;

   for(i = 0; i < n; i++) {

      p1 = 0;
      p2 = -1;

   	/*
      cout << endl;
      for(j = 0; j < total; j++) {
         cout << arr[j] << ' ';
      }
      cout << endl;
      */

      for(j = 0; j < num_matches; j++) {
         for(k = p2 + 1; k < total; k++) {
            if(arr[k] != 0) {
               p1 = k;
               break;
            }
         }

         for(k = p1+1; k < total; k++) {
            if(arr[k] != 0) {
               p2 = k;
               break;
            }
         }

         if(num_matches == 1) {
            if(arr[p1] < arr[p2]) cout << p1 + 1;
            else cout << p2 + 1;

            cout << endl;
         }

         if(arr[p1] < arr[p2]) arr[p1] = 0;
         else arr[p2] = 0;
      }

      num_matches /= 2;

   }

   /*
   cout << endl;
   for(j = 0; j < total; j++) {
      cout << arr[j] << ' ';
   }
   cout << endl;
   */

   return 0;
}