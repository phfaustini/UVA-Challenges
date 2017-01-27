#include<iostream>
#include <sstream>
#include<vector>
#include <math.h>
#include<climits>
using namespace std;

// g++ -lm -lcrypt -O2 -std=c++11 -pipe 11078OpenCreditSystem.cpp


int main()
{
	string line;
	int n = -1, students, i, tests = -1;
	vector<int> marks;
	while(getline(cin,line))
	{	
		stringstream ss(line);
		if(tests == -1)
			ss >> tests;
		else if(n == -1)
		{
			tests--;
			ss >> n;
			students = n;
			i = 0;
		}
		else
		{
			int temp;
			students--;
			ss >> temp;
			marks.push_back(temp);
			if(students == 0)
			{
				int max = INT_MIN;
				int biggest = marks[0];
				int temp;
				for(i=1;i<n;i++)
				{
					temp = biggest - marks[i];
					if(temp > max)
						max = temp;
					if(marks[i] > biggest)
					{
						biggest = marks[i];
					}
						/*if(marks[i] > biggest)
						{
							biggest = marks[i];
							for(int j=i+1;j<n;j++)
							{
								temp = marks[i] - marks[j];
								if (temp > max)
									max = temp;
							}
						}*/
				}
				n = -1;
				cout << max << endl;
				marks.clear();
			}
		}
	}
}
