/*
* Answer for https://uva.onlinejudge.org/external/110/11085.pdf
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ -lm -lcrypt -O2 -std=c++11 -pipe 11085BackToThe8Queens.cpp
*/
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int board[8][8] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

int combinations[92][8];


bool isUnderAttack(int r, int c)
{
	for(int c_aux = c-1; c_aux >= 0; c_aux--)
		if(board[r][c_aux] == 1)
			return true;

	int c_aux = c - 1, r_aux = r - 1;
	while(c_aux >= 0 && r_aux >= 0)
	{
		if(board[r_aux][c_aux] == 1)
			return true;
		c_aux--; r_aux--;
	}

	c_aux = c - 1, r_aux = r + 1;
	while(c_aux >= 0 && r_aux <= 7)
	{
		if(board[r_aux][c_aux] == 1)
			return true;
		c_aux--; r_aux++;
	}
	return false;
}


void findAllCombinations()
{
	for(int i(0); i < 92; i++)
	{
				
	}
}


int main()
{
	string line;
	int test = 0;
	while(getline(cin,line))
	{
		test++;
		for (int i(0);i<8;i++) for (int j(0);j<8;j++)  board[i][j] = 0;
		int r = 0;
		int c = -1;
		int movements = 0;
		stringstream ss(line);
		while(ss >> r)
		{
			c++;
			board[r][c] = 1;
			if(isUnderAttack(r, c))
			{
				movements++;
				board[r][c] = 0;
				r=0;
				while(! isUnderAttack(r, c))
					r++;
				board[r][c] = 1;
			}
		}	
		cout << "Case " << test << ": " <<movements << endl;	
	}
	return 0;
}
