#include <iostream>

using namespace std;

int main(void) {
   int n;
   cin >> n;

   int *boxes = new int[n];
   int *sbecs = new int[n];

   for(int i = 0; i < n; i++) {
      cin >> boxes[i];
      sbecs[i] = 100;
   }

   for(int i = 0; i < n; i++) {
      if(i == 0) sbecs[i] += boxes[i];
      else sbecs[i] = sbecs[i-1] += boxes[i];
   }

   int maximum_possible = 100;

   for(int i = 0; i < n; i++) {
      if(sbecs[i] > maximum_possible) maximum_possible = sbecs[i];
   }

   cout << maximum_possible << endl;
   
   return 0;
}