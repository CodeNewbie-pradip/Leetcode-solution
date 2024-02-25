/*
For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and
nums[i] > nums[j].Given two integers n and k, return the number of different arrays consist of numbers from 1 to n 
such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.
Example 1:Input: n = 3, k = 0, Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
Example 2: Input: n = 3, k = 1, Output: 2
Explanation: The array [1,3,2] and [2,1,3] have exactly 1 inverse pair.
*/

#include<iostream>
#include<vector>
using namespace std;

int kInversePairsRecursion(int n, int k)
{
    if(n==0)
    {
        return 0;
    }
    if(k==0)
    {
        return 1;
    }
    int ans=0;
    //all possible permutation to make inverse pair
    //min(k, n) when k>n or n<k it not need to extra operation to perform 
    //we have alredy tell in problem statement to make pair k eg. k4 n=2 so it is not possible
    for(int inv=0; inv<=min(k, n-1); inv++)
    {
        ans+=kInversePairsRecursion(n-1, k-inv);
    }
    return ans;
}

int kInversePairsMemoisation(int n, int k)
{
    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
    if(n==0)
    {
        return 0;
    }
    if(k==0)
    {
        return 1;
    }

    //ans already exist
    if(dp[n][k]!=-1)
    {
        return dp[n][k];
    }
    int ans=0;
    for(int inv=0; inv<=min(k, n-1); inv++)
    {
        ans+=kInversePairsMemoisation(n-1, k-inv);
    }

    return dp[n][k]=ans;
}

int kInversePairsTabulation(int n, int k, vector<vector<int>>& dp)
{
    //analyse the base case
    //k==0 return 1 means first col is set 1 k-is col
    //n is assign on row dp[n][k=0]=1
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=1;
    }

    //in mem fun call goes n,k->0 but in tabulation is opposite
    //loop traverse 0->n, k
    //0 row col set 1 thats why loop start from 1
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            //here paste tabulation sol
            for(int inv=0; inv<=min(i-1, j); inv++)
            {
                dp[i][j]+=dp[i-1][j-inv];
            }
        }
    }
    //loop goes n, k
    //so answer is created n, k
    return dp[n][k];
}

int kInversePairsTabulationSO(int n, int k)
{
    vector<vector<int>>dp(n+1, vector<int>(k+1));
    for(int i=0; i<=n; i++)
    {
        dp[i][0]=1;
    }

    //in mem fun call goes n,k->0 but in tabulation is opposite
    //loop traverse 0->n, k
    //0 row col set 1 thats why loop start from 1
    for(int i=1; i<=n; i++)
    {
        long long currSum=1;
        for(int j=1; j<=k; j++)
        {
            //here paste tabulation sol
            currSum+=dp[i-1][j];
            if(j>=i)
            {
                currSum-=dp[i-1][j-i];
            }
            dp[i][j]=currSum;
        }
    }
    //loop goes n, k
    //so answer is created n, k
    return dp[n][k];
}
int main()
{
    //int n=3, k=0;
    int n=3, k=1;
    cout<<"Solve by Recusrion: "<<endl;
    int ans=kInversePairsRecursion(n, k);
    cout<<ans<<endl;
    cout<<"Solve by Rec+Memoisation: "<<endl;
    ans=kInversePairsMemoisation(n, k);
    cout<<ans<<" "<<endl;
    cout<<"Solve by Tabulation: "<<endl;
    vector<vector<int>>dp(n+1, vector<int>(k+1, 0));
    ans=kInversePairsTabulation(n, k, dp);
    cout<<ans<<endl;
    cout<<"Tabulation SO:"<<endl;
    ans=kInversePairsTabulationSO(n, k);
    cout<<ans<<endl;
}