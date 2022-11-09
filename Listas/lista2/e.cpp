#include <iostream>

using namespace std;

long long int mod(long long int n) {
   if(n < 0) return -n;
   else return n;
}

int main(void) {
   long long int base1, base2;
   long long int exp;
   char answer; 

   cin >> base1;
   cin >> base2;
   cin >> exp;

   if(exp & 1) { // Impar
      if(base1 == base2) answer = '=';
      else if(base1 > base2) answer = '>';
      else answer = '<';
   } else { // Par
      if(mod(base1) == mod(base2)) answer = '=';
      else if(mod(base1) > mod(base2)) answer = '>';
      else answer = '<';
   }

   cout << answer << endl;


   return 0;
}