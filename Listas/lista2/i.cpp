#include <iostream>

using namespace std;

typedef unsigned long long ulli;

int main(void) {
   ulli hotels_number;
   ulli money;
   ulli start, end, i;

   cin >> hotels_number >> money;
   ulli hotels[hotels_number];

   for(i = 0; i < hotels_number; i++) {
      cin >> hotels[i];
   }

   ulli max_sum = 0, sum = 0;
   start = 0;
   end = 0;
   while(start < hotels_number) {
      if(sum == money) {
         max_sum = sum;
         break;
      } else if(sum < money && end < hotels_number) {
         sum += hotels[end];

         if(end < hotels_number) end++;
         else start++;
      } else {
         sum -= hotels[start];
         start++;
      }

      if(sum > max_sum && sum < money) max_sum = sum ;

   }

   cout << max_sum << endl;

   return 0;
}