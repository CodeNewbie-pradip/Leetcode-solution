/*
1043. Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k.
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. 
Test cases are generated so that the answer fits in a 32-bit integer.
*/
#include<iostream>
#include<vector>
using namespace std;

int solvebyRecursion(vector<int>& arr, int i, int k, int size)
{
    if(i>=size)
    {
        return 0;
    }

    int result=0;
    int curr_max=0;
    for(int j=i; j<size && j-i+1<=k; j++)
    {
        curr_max=max(curr_max, arr[j]);

        //current subarray=> arr[i to j]
        result=max(result, ((j-i+1)*curr_max)+ solvebyRecursion(arr, j+1, k, size));
    }
    return result;
}

int solvebyRecuMemo(vector<int>& arr, int i, int k, int size, vector<int>& dp)
{
    if(i>=size)
    {
        return 0;
    }

    if(dp[i]!=-1)
    {
        return dp[i];
    }

    int result=0;
    int curr_max=0;

    for(int j=i; j<size && j-i+1<=k; j++)
    {
        curr_max=max(curr_max, arr[j]);

        //current subarray=arr[i to j]
        result=max(result, ((j-i+1)*curr_max)+ solvebyRecuMemo(arr, j+1, k, size, dp));
    }
    dp[i]=result;
    return dp[i];
}

int solvebyTabulation1(vector<int>& arr, int i, int k, int size)
{
    vector<int>dp(size+1, 0);

    for(int i=size-1; i>=0; i--)
    {
        int result=0;
        int curr_max=0;

        for(int j=i; j<size && j-i+1<=k; j++)
        {
            curr_max=max(curr_max, arr[j]);
            //current subarray=arr[i to j]
            result=max(result, ((j-i+1)*curr_max)+ dp[j+1]);
        }
        dp[i]=result;
    }
    return dp[0];
}

int solvebyTabulation2(vector<int>& arr, int i, int k, int size)
{
    vector<int>dp(size+1, 0);

    for(int i=1; i<=size; i++)
    {
        int curr_max=0;

        for(int j=1; j<=k && i-j>=0; j++)
        {
            curr_max=max(curr_max, arr[i-j]);
            //current subarray=arr[i to j]
            dp[i]=max(dp[i], ((j*curr_max)+ dp[i-j]));
        }
    }
    return dp[size];
}

int maxSumAfterPartitioning(vector<int>& arr, int k) 
{
    int n=arr.size();
    // cout<<"Solve By Recursion: "<<endl;
    // return solvebyRecursion(arr, 0, k, n);
    //cout<<"Solve By Rec+Memo: "<<endl;
    // vector<int>dp(n+1, -1);
    // return solvebyRecuMemo(arr, 0, k, n, dp);
    cout<<"Solve By Tabu: "<<endl;
    return solvebyTabulation2(arr, 0, k, n);
}

int main()
{
//Example 1:
    vector<int>arr = {1,15,7,9,2,5,10}; 
    int k = 3;
    int ans=maxSumAfterPartitioning(arr, k);
    cout<<ans;
//Output: 84
//Explanation: arr becomes [15,15,15,9,10,10,10]
//Example 2:
    //vetor<int>arr = {1,4,1,5,7,3,6,1,9,9,3};
    //int k = 4;
//Output: 83
//Example 3:
    //vector<int>arr = {1}; 
    //int k = 1;
//Output: 1
}
