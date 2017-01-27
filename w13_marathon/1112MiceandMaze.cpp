#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    int i,j,N,E,T,M,numtest,result,ms,md,w,count;
    bool finish;
    cin>>numtest;
    while(numtest--){
        cin >> N >> E >> T >> M;
        vector<vector<pair<int,int> > > cellsConections(N,vector<pair<int,int> >());
        for(i=0;i<M;i++){
            cin >> ms >>md >> w ;
                cellsConections[ms-1].push_back(make_pair(md-1,w));
        }
        count =0;
        for(j=0;j<N;j++){
            if(j!=E-1){
                priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > q;
                vector< int > d(N, -1);
                pair<int,int> p; 
                int v;
                result=0;
                finish = false;
                q.push( make_pair(0,j) );
                while (!q.empty() && !finish && result <= T){
                    p = q.top(); 
                    q.pop();
                    v = p.second;
                    result = p.first;
                    if ( d[v] != -1) {
                        continue;
                    }
                    if (v != E-1 && result <= T) {                    
                        d[v] = result;
                        for (int i = 0; i <  cellsConections[v].size(); i++){
                            if ( d[ cellsConections[v][i].first ] == -1 || d[ cellsConections[v][i].first ]  > result+cellsConections[v][i].second){
                                q.push( make_pair(result+cellsConections[v][i].second,cellsConections[v][i].first) );
                            }
                        }
                    }
                    else if(result <= T){
                        finish=true;
                    }
                }
                if(result<=T && finish)
                    count++;
            } else
                count++;
        }
        if(numtest==0)
            cout << count << endl;
        else    
            cout << count << endl << endl;
    }
}