/*
* Answer for https://uva.onlinejudge.org/external/5/556.pdf
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ 556Amazing.cpp  -lm -lcrypt -O2 -std=c++11
*/

#include<iostream>
#include<string>
#include <sstream>
using namespace std;

int **maze;

void printMaze(int l, int c){
  for(int i(0);i<l;i++){
    for(int j(0);j<c;j++)
        cout << maze[i][j] << "    ";
    cout << endl << "--------------------------" << endl << endl;
  }
}

char turn_left(char orientation)
{
  switch (orientation)
  {
    case '>': return '^';
    case '^': return '<';
    case '<': return 'v';
    default: return '>';
  }
}

/*Returns true if there is no wall on the next position*/
bool validate_next_position(char orientation, int current_line, int current_column, int line, int column)
{
    int nextL = current_line, nextC = current_column;

    switch (orientation)
    {
      case '>': nextC++;
                break;
      case '<': nextC--;
                break;
      case '^': nextL--;
                break;
      case 'v': nextL++;
                break;
    }
    if(nextC >= column || nextL >= line || nextC == -1 || nextL == -1){ // Out of maze
      return false;}
    else if(maze[nextL][nextC] == -1){ // Is a wall
      return false;}
    else return true;
}

bool wall_on_my_right(char orientation, int l, int c, int line_max, int column_max)
{
  switch (orientation)
  {
    case '>': if((l+1 == line_max) || maze[l+1][c] == -1){
                  return true;
              }else {
                return false;
              }
    case '<': if((l-1 == -1) || maze[l-1][c] == -1){
                  return true;
              }else return false;
    case 'v': if((c-1 == -1) || maze[l][c-1] == -1) {
                  return true;
              }else  return false;
    default: if((c+1 == column_max) || maze[l][c+1] == -1){
                  return true;
              }else  return false;
  }
}

void get_next_position(char orientation, int position[])
{
    switch (orientation)
    {
      case '>': position[1]++;
                break;
      case '<': position[1]--;
                break;
      case '^': position[0]--;
                break;
      default:  position[0]++;
    }
}

int main()
{
    int l=0, c=0, lineNumber = -1;
    string line;
    while(getline(cin,line))
    {
        stringstream ss(line);
        if(lineNumber == -1)
        {
            lineNumber = 0;
            ss >> l;
            ss >> c;
            if(l == 0 && c ==0)
                  return(0);
            else /*initialise the maze with zeros*/
            {
                maze = new int *[l];
                for (int i = 0; i < l; i++)
                    maze[i] = new int[c];
            }
        }
        else{
            for(int i=0; i<c; i++)
                if (line[i] == '0') maze[lineNumber][i] = 0;
                else maze[lineNumber][i] = -1;
            if(lineNumber == l-1){
                lineNumber = -1;
                int *position = new int[2];
                int *lastPosition = new int[2];
                char orientation = '>';
                int *output = new int[5];
                position[0] = l-1; position[1] = 0;
                /*Measure how many times each cell has been visited*/
                while(maze[l-1][0] == 0)
                {
                    if(validate_next_position(orientation, position[0], position[1], l, c) && wall_on_my_right(orientation, position[0], position[1], l, c))
                    {
                      lastPosition[0] = position[0]; lastPosition[1] = position[1];
                      get_next_position(orientation, position);
                      maze[position[0]][position[1]] += 1;
                    }
                    else if(wall_on_my_right(orientation, position[0], position[1], l, c) == false)
                    {
                        switch (orientation)
                        {
                          case '<': orientation = '^';
                                    break;
                          case '>': orientation = 'v';
                                    break;
                          case '^': orientation = '>';
                                    break;
                          default:  orientation = '<';
                        }
                        lastPosition[0] = position[0]; lastPosition[1] = position[1];
                        get_next_position(orientation, position);
                        maze[position[0]][position[1]] += 1;
                    }
                    else{
                      orientation = turn_left(orientation);
                    }
                }

                /*Prepare output*/
                for(int i=0; i < l; i++)
                  for(int j=0; j < c; j++){
                    if(maze[i][j] == 0)
                        output[0]++;
                    else if(maze[i][j] == 1)
                        output[1]++;
                    else if(maze[i][j] == 2)
                        output[2]++;
                    else if(maze[i][j] == 3)
                        output[3]++;
                    else if(maze[i][j] == 4)
                        output[4]++;
                  }
                for(int i=0; i < 5; i++)
                      if(output[i]<10)
                          cout << "  " << output[i];
                      else if(output[i] < 100)
                          cout << " " << output[i];
                      else cout << output[i];
                cout << endl;
            }
            else
                lineNumber++;
        }
    }
    return(0);
}
