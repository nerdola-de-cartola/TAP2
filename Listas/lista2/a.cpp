#include <iostream>
#include <vector>

using namespace std;

class Time {
   public:
      int m_h;
      int m_m;
      int m_time;

   public:
      Time();
      Time(int h, int m);
      Time(int time);
};

Time::Time() 
   : m_h(0), m_m(0), m_time(0) {}

Time::Time(int h, int m) 
   : m_h(h), m_m(m), m_time((h*60) + m) {}

Time::Time(int time) {
   m_h = time / 60;
   m_m = time - (m_h*60);
}

int main(void) {
   int tests;
   cin >> tests;

   while(tests--) {
      int alarms_amount, h, m;
      int first_alarm = -1;
      int i;
      bool next_day = false;

      cin >> alarms_amount;
      cin >> h;
      cin >> m;

      Time sleep(h, m);
      vector<Time> alarms;
      
      for(i = 0; i < alarms_amount; i++) {
         cin >> h;
         cin >> m;
         Time alarm(h, m);
         alarms.push_back(alarm);
      }

      for(i = 0; i < alarms_amount; i++) {
         if(alarms[i].m_time < sleep.m_time) continue;

         if(first_alarm == -1) first_alarm = alarms[i].m_time;
         else if(alarms[i].m_time <= first_alarm) first_alarm = alarms[i].m_time;
      }

      if(first_alarm == -1) {
         next_day = true;

         for(i = 0; i < alarms_amount; i++) {
            if(first_alarm == -1) first_alarm = alarms[i].m_time;
            else if(alarms[i].m_time <= first_alarm) first_alarm = alarms[i].m_time;
         }
      }

      Time total_sleep;

      if(next_day) total_sleep = Time(24*60 - sleep.m_time + first_alarm);
      else total_sleep = Time(first_alarm - sleep.m_time);
      
      cout << total_sleep.m_h << ' ' << total_sleep.m_m << endl;
   }

   return 0;
}