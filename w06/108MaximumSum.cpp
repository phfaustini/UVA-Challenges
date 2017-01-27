/*
* Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=44
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ -lm -lcrypt -O2 -std=c++11 -pipe 108MaximumSum.cpp
*/
#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <map>
using namespace std;
int** matrix;

int main()
{
	int n = 128, i = 0 , j = 0;
	string line;

	/*Initialise matrix*/
	while(getline(cin,line))
	{
		stringstream ss(line);
		if (n == 128)
		{
			ss >> n;
			matrix = new int*[n];
			for (i=0;i<n;i++)
				matrix[i] = new int[n];
			i = 0;
		}
		else
		{
			int element;
			while(ss >> element)
			{
				matrix[i][j] = element;
				j++;
				if (j == n)
				{
					j = 0;
					i++;
				}
			}
		}
	}
	
	map<int,int> mymap;
	int best = INT_MIN;
	//Find the sum of the maximal sub-rectangle
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			//Computes sum of a sub-rectangle
			int candidate = 0;
			for(int i_inner = i; i_inner<n; i_inner++)
			{
				int row = 0;
				for (int j_inner = j; j_inner<n; j_inner++)
				{
					row += matrix[i_inner][j_inner];
					candidate = row + mymap[j_inner];
					mymap[j_inner] += row;
					if(candidate > best)
						best = candidate;
				}
				candidate = 0;
			}
			mymap.clear();
		}

	cout << best << endl;
	return 0;
}

