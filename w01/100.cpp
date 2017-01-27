#include<iostream>
#include<algorithm>
using namespace std;

int f(int n, int c)
{
	if (n==1)
		return c+1;
	else if(n%2!=0)
		f(3*n+1,c+1);
		else return f(n/2,c+1);
}

int main()
{
	int i, j;
	while(cin >> i >> j)
	{
		int cicles=0;
		int smallest = min(i,j);
		int biggest = max(i,j);
		i=smallest; j= biggest;
		
		for(int k=i;k<=j;k++)
		{
			int temp = f(k,0);
			if(temp >cicles)
				cicles=temp;
		}
		cout << i <<" " << cicles << " " << j << endl;
	}
	return 0;
}
