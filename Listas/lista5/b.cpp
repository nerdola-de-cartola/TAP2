#include <bits/stdc++.h>

using namespace std;

int comb(int n) {
   return n * (n - 1) / 2;
}

int main(void) {
   int n;
   cin >> n;

   bool chocolate[n][n];

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         char input;
         cin >> input;

         chocolate[i][j] = (input == '.') ? false : true;
      }
   }

   int total_row = 0;
   for(int i = 0; i < n; i++) {
      int qtd = 0;

      for(int j = 0; j < n; j++) {
         if(chocolate[i][j]) qtd++;
      }

      total_row += (qtd < 2) ? 0 : comb(qtd); 
   }

   int total_column = 0;
   for(int j = 0; j < n; j++) {
      int qtd = 0;

      for(int i = 0; i < n; i++) {
         if(chocolate[i][j]) qtd++;
      }

      total_column += (qtd < 2) ? 0 : comb(qtd); 
   }

   cout << total_row + total_column << endl;

   return 0;
}