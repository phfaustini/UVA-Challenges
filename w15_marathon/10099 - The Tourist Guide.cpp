#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int nCases = 1, resultMatrix[100][100];
    int N, R, C1, C2, P, S, D, T;

    cin >> N >> R;
    while(N > 0 || R > 0){
        for(int i=0; i<N; i++){
            fill(resultMatrix[i],resultMatrix[i]+N, 0);
        }
        for(int i=0; i<R; i++){
            cin >> C1 >> C2 >> P;
            resultMatrix[C1-1][C2-1] = P;
            resultMatrix[C2-1][C1-1] = P;
        }
        for(int i=0; i<N; i++){
            resultMatrix[i][i] = 0;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    resultMatrix[i][j] = max(resultMatrix[i][j], min(resultMatrix[i][k], resultMatrix[k][j]));
                    resultMatrix[j][i] = resultMatrix[i][j];
                }
            }
        }

        cin >> S >> D >> T;
        cout << "Scenario #"<< nCases << endl << "Minimum Number of Trips = " << (int)ceil((double)T/(resultMatrix[S-1][D-1] - 1.0)) << endl << endl;

        nCases++;
        cin >> N >> R;
    }

    return 0;
}
