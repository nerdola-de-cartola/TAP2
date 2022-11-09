#include <iostream>

using namespace std;

void print(char **matrix, int i_max, int j_max);

int main(void) {
   int n;
   cin >> n;

   char **bus = new char*[n];

   for(int i = 0; i < n; i++) {
      bus[i] = new char[5];
   }

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < 5; j++) {
         cin >> bus[i][j];
      }
   }

   for(int i = 0; i < n; i++) {
      if(bus[i][0] == 'O' && bus[i][1] == 'O') {
         bus[i][0] = '+';
         bus[i][1] = '+';
         cout << "YES" << endl;
         print(bus, n, 5);
         return 0;
      } else if(bus[i][3] == 'O' && bus[i][4] == 'O') {
         bus[i][3] = '+';
         bus[i][4] = '+';
         cout << "YES" << endl;
         print(bus, n, 5);
         return 0;
      }
   }

   cout << "NO" << endl;

   return 0;
}

void print(char **matrix, int i_max, int j_max) {
   for(int i = 0; i < i_max; i++) {
      for(int j = 0; j < j_max; j++) {
         cout << matrix[i][j];
      }
      cout << endl;
   }
}