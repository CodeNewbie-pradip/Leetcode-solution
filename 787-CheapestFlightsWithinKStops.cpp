#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<unordered_map>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
    vector<int> distance(n, INT_MAX);

    unordered_map<int, vector<pair<int, int>>> adjList;
    for(auto vec: flights)
    {
        int u=vec[0];
        int v=vec[1];
        int cost=vec[2];

        adjList[u].push_back({v, cost});
    }

    queue<pair<int, int>>q;
    q.push({src, 0});
    distance[src]=0;
    int steps=0;

    while(!q.empty() && steps<=k)
    {
        int N=q.size();
        while(N--)
        {
            int u=q.front().first;
            int d=q.front().second;
            q.pop();
            
            for(auto nbr: adjList[u])
            {
                int v=nbr.first;
                int cost=nbr.second;
                if(distance[v] > d+cost)
                {
                    distance[v]=d+cost;
                    q.push({v, d+cost});
                }
            }
        }
        steps++;
    }
    return (distance[dst]==INT_MAX) ? -1 : distance[dst];
}

int main()
{
    int n = 4,  src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout<<findCheapestPrice(n, flights, src, dst, k)<<endl;
    //Output: 700

    //Example 2:
    // int n = 3, src = 0, dst = 2, k = 1;
    // vector<vector<int>> flights = {{0,1,100},
    //                                {1,2,100},
    //                                {0,2,500}};
    // cout<<findCheapestPrice(n, flights, src, dst, k)<<endl;
    //Output: 200

    //Example 3:
    //int n = 3,  src = 0, dst = 2, k = 0;
    //vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    //Output: 500
}