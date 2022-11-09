#include <iostream>

using namespace std;

int main(void) {
   int limak, bob;

   cin >> limak;
   cin >> bob;

   int years = 1;
   while(true) {
      limak *= 3;
      bob *= 2;

      if(limak > bob) break;

      years++;
   }
   
   cout << years << endl;

   return 0;
}