#include <iostream>

using namespace std;

int cards[13];

int lowest_card(int mary_points, int john_points);

int main(void) {
   int rounds_played;
   int john[2], mary[2];
   int john_points, mary_points, common_points;
   int input;
   int i;

   cin >> rounds_played;
   cin >> john[0];
   cin >> john[1];
   cin >> mary[0];
   cin >> mary[1];

   for(i = 0; i < 13; i++) {
      cards[i] = 4;
   }

   cards[john[0] - 1]--;
   cards[john[1] - 1]--;
   cards[mary[0] - 1]--;
   cards[mary[1] - 1]--;

   common_points = 0;

   for(i = 0; i < rounds_played; i++) {
      cin >> input;
      cards[input-1]--;
      common_points += input > 10 ? 10 : input;
   }

   mary_points = common_points;
   mary_points += mary[0] > 10 ? 10 : mary[0];
   mary_points += mary[1] > 10 ? 10 : mary[1];

   john_points = common_points;
   john_points += john[0] > 10 ? 10 : john[0];
   john_points += john[1] > 10 ? 10 : john[1];

   cout << lowest_card(mary_points, john_points) << endl;

   return 0;
}

int lowest_card(int mary_points, int john_points) {
   int games[13][2]; // john = 0, mary = 1

   int i;
   for(i = 0; i < 13; i++) {

      if(cards[i] != 0) {
         if(i < 10) {
            games[i][0] = john_points + i + 1;
            games[i][1] = mary_points + i + 1;
         } else  {
            games[i][0] = john_points + 10;
            games[i][1] = mary_points + 10;
         }
      } else {
         games[i][0] = -1;
         games[i][1] = -1;
      }

   }

   for(i = 0; i < 13; i++) {
      if(games[i][0] == -1) continue;

      if(games[i][1] > 23) {
         return -1;
      } else if(games[i][0] > 23 || games[i][1] == 23) {
         return i + 1;
      } 
   }

   return -1;
}