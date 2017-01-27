/*
* Answer for https://uva.onlinejudge.org/external/102/10276.pdf
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ -lm -lcrypt -O2 -std=c++11 -pipe 10276HanoiTowerTroublesAgain.cpp
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int tests = -1;
	string line;
	while(getline(cin,line))
	{
		stringstream ss(line);
		if(tests==-1)
			ss >> tests;
		else
		{
			int n = 0, numberPegs;
			ss >> numberPegs;
			vector< stack<int> > pegs;
			for (int i(0); i< numberPegs; i++)
			{
				stack<int> mystack;
				pegs.push_back(mystack);
			}
			
			while(1)
			{
				n++;
				bool inserted = false;
				for (int i(0); i< numberPegs; i++)
				{
					if(pegs[i].empty() || (sqrt((double)pegs[i].top() + (double)n) == (int) sqrt((double)pegs[i].top() + (double)n)))
					{
						pegs[i].push(n);
						inserted = true;
						break;						
					}
				}
				if(!inserted)
				{
					n--;
					break;
				}
			}
			cout << n << endl;	
			tests-=1;
			if(tests ==0)
				return 0;		
		}
	}
	return 0;
}
