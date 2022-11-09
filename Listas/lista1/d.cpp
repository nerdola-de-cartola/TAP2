#include <iostream>

using namespace std;

int mod(int a);

int main(void) {
   int matrix[5][5];

   for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
         cin >> matrix[i][j];
      }
   }

   /*
   cout << endl;
   
   
   for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
         cout << matrix[i][j] << ' ';
      }
      cout << endl;
   }

   cout << endl;
   */

   int i_one, j_one;
   for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) {
         if(matrix[i][j] == 1) {
            i_one = i;
            j_one = j;
         }
      }
   }

   int moves = 0;
   moves += mod(i_one - 2);
   moves += mod(j_one - 2);

   cout << moves << endl;
   
   return 0;
}

int mod(int a) {
   if(a < 0) return -a;
   return a;
}