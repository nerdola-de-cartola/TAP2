#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;

ui countBits(ui x);

int main(void) {
   ui number_of_players, number_of_soldiers, friend_coefficient;

   cin >> number_of_soldiers >> number_of_players >> friend_coefficient;
   ui players[number_of_players];

   for(ui i = 0; i < number_of_players; i++) {
      cin >> players[i];
   }

   ui fedor;
   cin >> fedor;

   ui friends = 0;
   for(ui i = 0; i < number_of_players; i++) {
      ui different_bits = countBits(players[i] ^ fedor);

      if(different_bits <= friend_coefficient) friends++;
   }

   cout << friends << endl;

   return 0;
}

ui countBits(ui x) {
   ui count = 0;

   while(x != 0) {
      if(x & 1) count++;

      x = x >> 1;
   }
   
   return count;
}