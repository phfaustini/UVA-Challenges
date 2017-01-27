/*
* Answer for https://uva.onlinejudge.org/external/114/11459.pdf
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ 11459SnakesandLadders.cpp  -lm -lcrypt -O2 -std=c++11
*/

#include<iostream>
#include <sstream>
#include <string>
#include<map>
#define TEST_INFO 1
#define SNAKE 2
#define DIE_ROLL 3

using namespace std;

int main()
{
  int lineNumber = 0, player = 0, die = 0;
  map<int,int> jumps, positionTemp;
  int *header = new int[3];
  string line;
  bool print = true;

  while(getline(cin,line))
  {
      stringstream ss(line);
      int i = 0;
      if(lineNumber == 0)
        lineNumber = TEST_INFO;
      else if(lineNumber == TEST_INFO)
      {
          print = true;
          player = 0;
          die = 0;
          jumps.clear();
          positionTemp.clear();
          while(ss >> header[i++]);
          for(i=1;i<=header[0];i++)
              positionTemp[i] = 1;
          if(header[1] > 0)
              lineNumber = SNAKE;
          else if(header[2] > 0) // There is no snakes, goes straight to die
              lineNumber = DIE_ROLL;
          else // There is no snakes nor die rolls, hence all players are on the same square
              for(i = 1; i<=header[0];i++)
                  cout << "Position of player " << i << " is 1." << endl;
      }
      else if(lineNumber == SNAKE)
      {
          int key, value;
          ss >> key;
          ss >> value;
          jumps[key] = value;
          header[1]--;
          if(header[1] == 0 && header[2] > 0)
              lineNumber = DIE_ROLL;
          else if(header[1] == 0 && header[2] ==0) // There is no dies, hence all players are on the same square
          {
                lineNumber = TEST_INFO;
                for(i = 1; i<=header[0];i++)
                    cout << "Position of player " << i << " is 1." << endl;
          }
      }
      else if(lineNumber == DIE_ROLL)
      {
        int position;
        ss >> position;
        position++;
        player++;
        die++;
        if(header[0] >= header[2])
        {
            if ( jumps.find(position) == jumps.end() )
                cout << "Position of player " << player << " is " << position << "." << endl;
            else
                cout << "Position of player " << player << " is " << jumps[position] << "." << endl;
            if(die == header[2])
            {
                lineNumber = TEST_INFO;
                if(player < header[0])
                {
                    player++;
                    while (player <= header[0]) {
                        cout << "Position of player " << player << " is 1." << endl;
                        player++;
                  }
                }
            }
        }
        else{ // Players are to play more than once. Outputs only final position
          if(print){
              if(jumps[positionTemp[player] + position - 1] > 0){
                    positionTemp[player] = jumps[positionTemp[player] + position - 1];
              }
              else{
                    positionTemp[player] += position - 1;
              }
          }

          if(positionTemp[player] >= 100){
              print = false;
              positionTemp[player] = 100;
          }

          if(die == header[2]) // No more dies to play
          {
                lineNumber = TEST_INFO;
                for(int i(1);i<=header[0];i++)
                {
                    cout << "Position of player " << i << " is " << positionTemp[i] << "." << endl;
                }
          }
          if(player == header[0])
                player = 0;
        }
      }
  }
  return 0;
}
