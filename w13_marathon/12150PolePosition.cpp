// g++ -lm -lcrypt -O2 -std=c++11 -pipe 12150PolePosition.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	string line;
	int cars, C = -1, i;
	int* pole;
	int* gridCar;
	int* gridOffset;
  	while(getline(cin,line))
  	{	
		stringstream ss(line);
		if(C == -1)
		{
			ss >> C;
			cars = C;
			pole = new int[C];
			gridCar = new int[C];
			gridOffset = new int[C];
			i = 0;
		}
		else
		{
			cars--;
			ss >> gridCar[i];
			ss >> gridOffset[i];
			i++;
			if(cars == 0)
			{
				bool impossible = false;
				for (int pos(0); pos < C; pos++)
				{
					if(pos + gridOffset[pos] >= C || pos + gridOffset[pos] < 0)
					{
						impossible = true;
						break;
					}
					else
						if(pole[pos + gridOffset[pos]] != 0)
						{
							impossible = true;
							break;
						}
						else
						{
							pole[pos + gridOffset[pos]] = gridCar[pos];
						}
				}
				if(impossible)
					cout << -1 << endl;
				else
				{
					for(int j(0); j < C; j++)
					{
						cout << pole[j];
						if( j != C-1)
							cout << " ";
					}
					cout << endl;
				}	
				cars = -1;
				C = -1;
				i = 0;
			}
		}
	}
}
