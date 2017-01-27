#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

typedef pair<int, int> ii;      // In this chapter, we will frequently use these
typedef vector<ii> vii;      // three data type shortcuts. They may look cryptic
typedef vector<int> vi;   // but shortcuts are useful in competitive programming

vector<vii> AdjList;
map<int, int> mapper, reverseMapper;
  vi p;                               // addition: the predecessor/parent vector

void printPath(int u, int s) {    // simple function to extract information from `vi p'
  if (u == s) { printf("%d", reverseMapper[u]); return; }
  printPath(p[u],s);   // recursive call: to make the output format: s -> ... -> t
  printf(" %d", reverseMapper[u]); 
}


int pathSize(int u, int s) {    // simple function to extract information from `vi p'
  if (u == s) { return 0; }
  else 
		return (pathSize(p[u],s) + 1);   // recursive call: to make the output format: s -> ... -> t

}

int main(){
	
	int n_tests, node, n_nodes, source, target,a,b;
	int counter, case_counter;

	case_counter = 1;
	while(cin >> n_nodes){
		
		AdjList.assign(21, vii());
 		counter = 0;
//		cout << n_nodes;
		for (int j=0;j<n_nodes;j++){

				cin >> node;
				a = 1; //+1
				b = node;
//				cout << a << " " << node << endl;
				if (mapper.find(a) == mapper.end()) { // mapping trick
				  mapper[a] = counter++;
				  reverseMapper[mapper[a]] = a;
				}
				if (mapper.find(b) == mapper.end()) {
				  mapper[b] = counter++;
				  reverseMapper[mapper[b]] = b;
				}
				AdjList[mapper[a]].push_back(ii(mapper[b], 0));
				AdjList[mapper[b]].push_back(ii(mapper[a], 0));
			}
//		cout << endl;
		for (int i=1;i<19;i++){
//			counter++;
			cin >> n_nodes;
//			cout << n_nodes;
			for (int j=0;j<n_nodes;j++){
				cin >> node;
				a = i+1; //+1
				b = node;
//				cout << a << " " << node << endl;
				if (mapper.find(a) == mapper.end()) { // mapping trick
				  mapper[a] = counter++;
				  reverseMapper[mapper[a]] = a;
				}
				if (mapper.find(b) == mapper.end()) {
				  mapper[b] = counter++;
				  reverseMapper[mapper[b]] = b;
				}
				AdjList[mapper[a]].push_back(ii(mapper[b], 0));
				AdjList[mapper[b]].push_back(ii(mapper[a], 0));
			}
//			cout << endl;
		}
				
//		cout << "lines " << counter << endl;
		cin >> n_tests;
		cout << "Test Set #" << case_counter++ << endl;
		for (int i=0;i<n_tests;i++){
			cin >> source >> target;
			int s = mapper[source];
			cout << setw(2);
			cout << source << " to " << setw(2) <<target << ": ";
			
	
			  // BFS routine
			  // inside int main() -- we do not use recursion, thus we do not need to create separate function!
			  map<int, int> dist; dist[s] = 0;          // distance to source is 0 (default)
			  queue<int> q; q.push(s);                                  // start from source
			  p.assign(21, -1); // to store parent information (p must be a global variable!)
			  int layer = -1;                             // for our output printing purpose
			  bool isBipartite = true;       // addition of one boolean flag, initially true

			  while (!q.empty()) {
				int u = q.front(); q.pop();                        // queue: layer by layer!
//				if (dist[u] != layer) printf("\nLayer %d:", dist[u]);
				layer = dist[u];

//				printf(", visit %d", reverseMapper[u]); // reverseMapper maps index to actual vertex label
				for (int j = 0; j < (int)AdjList[u].size(); j++) {
				  ii v = AdjList[u][j];                           // for each neighbors of u
				  if (!dist.count(v.first)) {    // dist.find(v.first) == dist.end() also ok
					dist[v.first] = dist[u] + 1;                  // v unvisited + reachable
					p[v.first] = u;          // addition: the parent of vertex v->first is u
					q.push(v.first);                              // enqueue v for next step
				  }
				  else if ((dist[v.first] % 2) == (dist[u] % 2))              // same parity
					isBipartite = false;


			  }}
				cout << pathSize( mapper[target],s) << endl;
		}
		cout << endl;

		}

	return 0;
	}

