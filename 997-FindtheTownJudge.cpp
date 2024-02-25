#include<iostream>
#include<vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) 
{
    vector<int> indDegree(n+1);
    vector<int> outDegree(n+1);

    for(auto degree: trust)
    {
        int u=degree[0];
        int v=degree[1];

        cout<<u<<" "<<outDegree[u]++<<endl;;
        cout<<v<<" "<<indDegree[v]++<<endl;
    }

    for(int i=1; i<=n; i++)
    {
        if(indDegree[i]==n-1 && outDegree[i]==0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout<<"Example 1: "<<endl;
    int n = 2;
    vector<vector<int>> trust1 = {{1,2}};
    cout<<findJudge(n, trust1)<<endl;
    // Output: 2
    cout<<"Example 2: "<<endl;
    n = 3;
    vector<vector<int>>trust2 = {{1,3},{2,3}};
    cout<<findJudge(n, trust2)<<endl;
    // Output: 3
    cout<<"Example 3: "<<endl;
    n = 3;
    vector<vector<int>> trust3 = {{1,3},{2,3},{3,1}};
    cout<<findJudge(n, trust3)<<endl;
    // Output: -1
}