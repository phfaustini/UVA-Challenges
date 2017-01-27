/*
* Answer for https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=10&page=show_problem&problem=762
* Author: Pedro Faustini
* Federal University of Rio Grande do Sul (UFRGS) - Brazil
* INF01056 - Programming Challenges
* Compilation: g++ -lm -lcrypt -O2 -std=c++11 -pipe 821PageHopping.cpp
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    string line;
    vector<int> nums, unique;
    map<int, int> reducer;
    map<int, vector<int> > graph;
    int nodes, test = 0;
    while(getline(cin, line))
    {
        test++;
        nums.clear();
        unique.clear();
        graph.clear();
        reducer.clear();
        
        stringstream ss(line);
        int ti;
        while(ss >> ti) 
            nums.push_back(ti);
        if(nums[0] == 0 && nums[1] == 0)
            break;
        else
        {
            // Last two numbers are zeroes and must be ignored
            nums.pop_back();
            nums.pop_back();
            unique = nums;
            
            sort(unique.begin(), unique.end());
            int j(0);
            for(int i(0); i<unique.size();i++)
                if(! reducer.count(unique[i]))
                    reducer[unique[i]] = j++;
            nodes = reducer.size();
            
            // Building graph 
            for (int i(0); i< nodes; i++)
               for (int j(0); j< nodes; j++)
                   graph[i].push_back(101);
            
            for(int i(0); i<nums.size(); i+=2)
                graph[ reducer[nums[i]] ] [ reducer[nums[i+1]] ] = 1;
                
            // Beginnig Floyd's algorithm
            for(int k(0); k < nodes; k++)
                for(int i(0); i< nodes; i++)
                    for(int j(0); j<nodes; j++)
                        graph[i][j] = min (graph[i][j], graph[i][k] + graph[k][j]);
		    // Ending Floyd's algorithm
            
            // Every node has distance 0 to itself
            for(int i(0); i< nodes; i++)
                for(int j(0); j < nodes; j++)
                    if(i == j)
                        graph[i][j] = 0;
                        
            // Calculating length
            double clicks = 0;
            for(int i(0); i< nodes; i++)
                for(int j(0); j < nodes; j++)
                    if(graph[i][j] != 101)
                        clicks += graph[i][j];
    		clicks /= (nodes*nodes - nodes);
            
            cout << "Case " << test << ": average length between pages = ";
            printf("%.3f clicks\n", clicks);
        }
    }
    return 0;
}