#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void findPos(ll size, ll p) {

   ll i, j;
   ll l, c;
   ll mid = size/2;

   /*
   for(i = 0; i < size; i++) {
      for(j = 0; j < size; j++) {
         matrix[i][j] = 0;
      }
   }
   */
   

   ll last_pos = 1;
   ll pos = 1;

   if(last_pos == p) {
      cout << "Line = " << mid+1 << ", column = " << mid+1 << ".\n";
      return;
   }

   for(i = 1, j = 1; i <= mid; i++, j += 2) {

      pos = last_pos + (j*2) + ((j+1)*2);

      if(pos >= p) {

         last_pos++;
         i--;

         c = mid+i;

         for(l = mid+i-1; l >= mid-i-1; l--) {
            pos = last_pos;

            if(last_pos == p) {
               cout << "Line = " << size-l << ", column = " << c+1 << ".\n";
               return;
            }

            last_pos++;
         }

         l = mid-i-1;

         for(c = mid+i-1; c >= mid-i; c--) {
            pos = last_pos;

            if(last_pos == p) {
               cout << "Line = " << size-l << ", column = " << c+1 << ".\n";
               return;
            }

            last_pos++;
         }

         c = mid-i-1;

            for(l = mid-i-1; l <= mid+i+1; l++) {
            pos = last_pos;

            if(last_pos == p) {
               cout << "Line = " << size-l << ", column = " << c+1 << ".\n";
               return;
            }

            last_pos++;
         }

         
         l = mid+i+1;

         for(c = mid-i; c <= mid+i; c++) {
            pos = last_pos;

            if(last_pos == p) {
               cout << "Line = " << size-l << ", column = " << c+1 << ".\n";
               return;
            }

            last_pos++;
         }

         break;
      }

      last_pos = pos;

   }

   if(i == (mid+1) && p > last_pos) {
      // cout << "aqui\n";

      c = size-1;

      for(l = mid+i-1; l >= mid-i-1; l--) {
         pos = last_pos;

         if(last_pos == p) {
            cout << "Line = " << size-l << ", column = " << c+1 << ".\n";
            return;
         }

         last_pos++;
      }
      
   }

   /*
   for(i = 0; i < size; i++) {

      for(j = 0; j < size; j++) {
         cout << matrix[i][j] << '\t';
      }

      cout << '\n';
   }
   */
   


}

int main(void) {

   ll size, p;

   while(true) {

      cin >> size >> p;

      if(size == 0 && p == 0)
         break;

      findPos(size, p);
   }

   return 0;
}