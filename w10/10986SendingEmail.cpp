/*
* Partial answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
* (time limit exceeded) 
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ -lm -lcrypt -O2 -std=c++11 -pipe 10986SendingEmail.cpp
*/
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int Dijkstra(int**graph, int source, int target, int nodes)
{
    bool* visited = new bool[nodes];
    int* distance = new int[nodes];
    int unvisited = nodes;
    int current = source;
    
    for(int i(0); i<nodes;i++)
    {
        distance[i] = 10001;
        visited[i] = false; 
    }
    
    distance[source] = 0;
    
    while(unvisited)
    {
        visited[current] = true;
        unvisited--;
        for (int j(0); j<nodes; j++)
            if( distance[current] + graph[current][j] < distance[j] )
                distance[j] = graph[current][j] + distance[current];
        // Pick the next non visited node who has the smallest value in visited array
        int temp = 10001;
        for(int i(0);i<nodes;i++)
        {
            if(!visited[i])
            {                
                    if( distance[i] <= temp )
                    {
                        current = i;
                        temp = visited[i];
                    }
            }
        }        
    }
       
    return distance[target];
}

int main()
{
    string line;
    int** graph;
    int test = 0, tests = -1, nodes = -1, edges, source, target, temp1, temp2, minN, maxN, latency;
    while(getline(cin,line))
    {
        stringstream ss(line);
        if(tests == -1)
            ss >> tests;
        else if(nodes == -1)
        {
            test++;
            ss >> nodes;
            ss >> edges;
            ss >> temp1;
            ss >> temp2;
            source = min(temp1, temp2);
            target = max(temp1, temp2);
            
            if(edges == 0)
            {
                cout << "Case #" << test <<": unreachable" << endl;
                nodes = -1;
                if(test == tests)
                    break;
            }
            else
            {
                // Creating graph
                graph = new int*[nodes];
                for (int i = 0; i < nodes; i++)
                    graph[i] = new int[nodes];
                for (int i = 0; i < nodes; i++)
                    for (int j = 0; j < nodes; j++)
                        graph[i][j] = 10001;
            }
        }
        else
        {
            // Completing graph
            edges--;
            ss >> temp1;
            ss >> temp2;
            ss >> latency;
            minN = min(temp1, temp2);
            maxN = max(temp1, temp2);
            graph[minN][maxN] = latency;
            
            if(edges == 0)
            {
                int distance = Dijkstra(graph, source, target, nodes);
                if(distance < 10001)
                    cout << "Case #"  << test << ": " << distance << endl;
                else
                    cout << "Case #" << test <<": unreachable" << endl;
                nodes = -1;
            }
        }
    }
    return 0;
}