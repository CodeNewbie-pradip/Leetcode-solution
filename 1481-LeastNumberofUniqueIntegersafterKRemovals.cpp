#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

//1481. Least Number of Unique Integers after K Removals
//Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.
int findLeastNumOfUniqueInts(vector<int>& nums, int k)
{
    unordered_map<int, int>mp;
    for(auto x: nums)
    {
        mp[x]++;
    }
    //create new frequency vector
    vector<int>freq;
    for(auto i: mp)
    {
        freq.push_back(i.second);
    }
    //sort freq incresing order
    sort(freq.begin(), freq.end());

    //freq-k=ans 2-4=-2 less than 0 means size-i
    for(int i=0; i<freq.size(); i++)
    {
        k-=freq[i];
        if(k<0)
        {
            return freq.size()-i;
        }
    }
    return 0;
}

int findLeastNumOfUniqueInts2(vector<int>& nums, int k)
{
    unordered_map<int, int>mp;
    for(auto i: nums)
    {
        mp[i]++;
    }

    priority_queue<int, vector<int>, greater<int>>pqMinheap;
    
    for(auto i:mp)
    {
        pqMinheap.push(i.second);
    }

    while (!pqMinheap.empty())
    {
        k-=pqMinheap.top();
        if(k<0)
        {
            return pqMinheap.size();
        }
        pqMinheap.pop();
    }
    return 0;
}
int main()
{
// Example 1:
    vector<int>arr={5,5,4};
    int k = 1;
    cout<<findLeastNumOfUniqueInts(arr, k)<<endl;
    cout<<findLeastNumOfUniqueInts2(arr, k)<<endl;
// Output: 1
// Explanation: Remove the single 4, only 5 is left.
// Example 2:
    vector<int>arr2 = {4,3,1,1,3,3,2};
    int x = 3;
    cout<<findLeastNumOfUniqueInts(arr2, x)<<endl;
    cout<<findLeastNumOfUniqueInts2(arr2, x)<<endl;
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
}