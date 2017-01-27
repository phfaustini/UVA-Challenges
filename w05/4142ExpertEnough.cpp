/*
* Answer for https://uva.onlinejudge.org/external/12/1237.pdf
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ -lm -lcrypt -O2 -std=c++11 -pipe 4142ExpertEnough.cpp
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
  int tests = -1, dbSize = -1, queries = -1;
  vector<string> name; vector<int> lowest, highest;
  string line;
  while(getline(cin,line))
  {
    stringstream ss(line);
    if(tests == -1)
          ss >> tests;
    else if(dbSize == -1)
          ss >> dbSize;
    else if(dbSize > 0)
    {
          dbSize--;
          string nameTemp;
          ss >> nameTemp;
          name.push_back(nameTemp);
          int temp;
          ss >> temp;
          lowest.push_back(temp);
          ss >> temp;
          highest.push_back(temp);
    }
    else if(queries == -1)
          ss >> queries;
    else
    {
          string output;
          int value, occurrences = 0;
          ss >> value;
          for(unsigned i(0); i<name.size(); i++)
          {
              if(lowest.at(i) <= value && highest.at(i) >= value)
              {
                  occurrences++;
                  output = name.at(i);
              }
          }
          if(occurrences == 1)
              cout << output << "\n";
          else
              puts("UNDETERMINED");

          queries--;
          if(queries == 0)
          {
                if(tests != 1) puts("");
                name.clear();
                lowest.clear();
                highest.clear();
                dbSize = -1;
                queries = -1;
                tests -= 1;
                if(tests == 0)
                  return(0);
          }

    }
  }
  return 0;
}
