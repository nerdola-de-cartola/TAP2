#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

int main(void) {
   lli tests;

   cin >> tests;

   while(tests--) {
      lli number_levels;

      cin >> number_levels;

      lli start_life = 0;
      lli current_life = start_life;

      for(lli i = 0; i < number_levels; i++) {
         lli life_level;

         cin >> life_level;

         current_life += life_level;

         if(current_life < 1) {
            start_life += fabs(current_life - 1);
            current_life = 1;
         }
      }

      cout << start_life << endl;
   }


   return 0;
}