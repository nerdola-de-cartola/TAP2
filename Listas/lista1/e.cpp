#include <iostream>

using namespace std;

int main(void) {
   int calories_cost[4];
   int total_calories;
   string clicked_strips;

   for(int i = 0; i < 4; i++) {
      cin >> calories_cost[i];
   }

   cin >> clicked_strips;

   for(char &letter : clicked_strips) {
      total_calories += calories_cost[letter - '0' - 1];
   }

   cout << total_calories << endl;

   return 0;
}