#include <iostream>

int main(void) {
   using namespace std;

   int n;
   cin >> n;

   for(int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if(a == 1) {
         cout << "HARD\n";
         return 0;
      }
   }

   cout << "EASY\n";

   return 0;
}