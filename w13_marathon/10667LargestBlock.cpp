#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;



int main(){
	
	int n_cases, b_size , n_blocks, r1 ,r2,c1,c2;

	cin >> n_cases;

	for (int kk=0;kk<n_cases;kk++){
	
		cin >> b_size >> n_blocks;

		int board[102][102] = {};

		for (int i=1;i<=b_size;i++)
			for (int j=1;j<=b_size;j++)
				board[i][j] = 0;

		for (int jj=1;jj<=n_blocks;jj++){
			cin >> r1 >> c1 >> r2 >> c2;
			for (int rr=r1;rr<=r2;rr++)
				for (int cc=c1;cc<=c2;cc++)
					board[rr][cc] = 1;
		}

		int length,width, temp_sum = 0;
		int max_sum = 0;
		for (int i=1;i<=b_size;i++){
			int b_sum[102] = {};
			for (int j=i;j<=b_size;j++){
				for (int k=1;k<=b_size;k++){
					b_sum[k] += !board[j][k];

					if ( k == 1 || temp_sum != length * width){
						temp_sum = 0;
						length = 0;
					}

					temp_sum += b_sum[k];
					length++;
					width = (j-i)+1;

					if (temp_sum == length * width)
						max_sum = max(max_sum,temp_sum);
							
				}
			}
		}

		cout << max_sum << endl;
		/*
		for (int i=1;i<=b_size;i++){
			cout << endl;
			for (int j=1;j<=b_size;j++)
				cout << board[i][j];
		} 

		*/
	}

	

}
