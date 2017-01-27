/*
* Answer for https://uva.onlinejudge.org/external/101/10172.pdf
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE 10172Cargo.cpp
*/
#include <iostream>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
using namespace std;

int main()
{
  bool getSet = true, header = false;
  int sets = 0, stations = 0, carrierCapacity = 0, platformCapacity = 0, minutes = 0, currentStation = 0;
  stack<int> carrier;
  map<int, queue<int> > station;
  string line;
  while(getline(cin,line))
  {
    stringstream ss(line);
    if(getSet)
    {
      ss >> sets;
  		getSet = false;
  		header = true;
    }
    else if(header)
    {
  		header = false;
      while(!carrier.empty()) carrier.pop();
  		minutes = 0;
  		currentStation = 0;
  		station.clear();
  		ss >> stations;
  		ss >> carrierCapacity;
  		ss >> platformCapacity;
    }
    else{
      currentStation+=1;
      int num;
      while (ss >> num) station[currentStation].push(num);
      station[currentStation].pop();
      if(stations == currentStation)
      {
        currentStation = 0;
        while (true)
        {
          currentStation+=1;
          if(currentStation > stations)
  					currentStation = 1;

          while(! carrier.empty())
          {
            if(carrier.top() == currentStation)
            {
  						carrier.pop();
  						minutes+=1;
            }
  					else if(station[currentStation].size() < platformCapacity)
            {
  						int cargo = carrier.top();
              carrier.pop();
  						station[currentStation].push(cargo);
  						minutes+=1;
            }
  					else
  						break;
          }

          while(carrier.size() < carrierCapacity and station[currentStation].size() > 0)
          {
  					carrier.push(station[currentStation].front());
            station[currentStation].pop();
  					minutes+=1;
          }

          if(carrier.empty())
          {
            bool b = true;
            for (auto const& x : station)
            {
                if(x.second.size() > 0)
                  b = false;
            }
            if(b)
              break;
          }

  				minutes+=2;

        }
        cout << minutes << endl;
        sets--;
  			if(sets == 0)
  				return 0;
  			else
  				header = true;
      }
    }
  }
  return 0;
}
