//POTD 26/01/2024
//576. Out of Boundary Paths
#include<iostream>
#include<vector>
using namespace std;
/*
problem statement-
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the
grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move 
the ball out of the grid boundary. Since the answer can be very large, return it modulo 10^9 + 7.
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
*/
const int mod=1e9 + 7;

int findPathsRecursion(int m, int n, int maxMove, int startRow, int startColumn)
{
    //return the number of paths to move the ball out of the grid boundary
    if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n)
    {
        return 1;
    }
    if(maxMove==0)
    {
        return 0;
    }

    long long int paths=0;
    paths+=findPathsRecursion(m, n, maxMove-1, startRow-1, startColumn);
    paths+=findPathsRecursion(m, n, maxMove-1, startRow+1, startColumn);
    paths+=findPathsRecursion(m, n, maxMove-1, startRow, startColumn-1);
    paths+=findPathsRecursion(m, n, maxMove-1, startRow, startColumn+1);

    return paths;
}

int findPathRecMemoisation(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>&dp)
{
    if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n)
    {
        return 1;
    }

    if(maxMove==0)
    {
        return 0;
    }

    //already exist answer
    if(dp[startRow][startColumn][maxMove]!=-1)
    {
        return dp[startRow][startColumn][maxMove];
    }
    long long int path=0;

    path+=findPathRecMemoisation(m, n, maxMove-1, startRow-1, startColumn, dp);
    path+=findPathRecMemoisation(m, n, maxMove-1, startRow+1, startColumn, dp);
    path+=findPathRecMemoisation(m, n, maxMove-1, startRow, startColumn-1, dp);
    path+=findPathRecMemoisation(m, n, maxMove-1, startRow, startColumn+1, dp);

    dp[startRow][startColumn][maxMove]=path;
    return dp[startRow][startColumn][maxMove];
}

// int findPathTabulation(int m, int n, int maxMove, int startRow, int startColumn)
// {
//     vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, 0)));
//     const int mod=1e9 + 7;
//     long long int path=0;
//     //analyse the base cases
//     for(int move=1; move<=maxMove; move++)
//     {
//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 //i am always forgotting convert verisble to for loop var name 
//                 //move=m, i=m=startRow, j=n=startColumn
//                 if(i>0) path=(path + dp[i-1][j][move-1] )%mod;//it is case of minus the least value
//                 if(i<m-1) path=(path + dp[i+1][j][move-1] )%mod;//it is case of add the max value
//                 if(j>0) path=(path + dp[i][j-1][move-1] )%mod;
//                 if(j<n-1) path=(path + dp[i][j+1][move-1] )%mod;
//                 dp[i][j][move]=path;
//             }
//         }
//     }
//     return dp[startRow][startColumn][maxMove];
// }
int findPathTabulation(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
    const int mod = 1e9 + 7;
    dp[startRow][startColumn][0] = 1;  // Initialize starting cell to 1
    for (int move = 1; move <= maxMove; move++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long int path = 0; // Reset path for each cell and each move

                if (i > 0) path = (path + dp[i - 1][j][move - 1]) % mod;
                if (i < m - 1) path = (path + dp[i + 1][j][move - 1]) % mod;
                if (j > 0) path = (path + dp[i][j - 1][move - 1]) % mod;
                if (j < n - 1) path = (path + dp[i][j + 1][move - 1]) % mod;

                dp[i][j][move] = path;
            }
        }
    }

    return dp[startRow][startColumn][maxMove];
}

int main()
{
//Input1: 
//int m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0;
//Output: 6
//int ans=findPaths(m, n, maxMove, startRow, startColumn);
//cout<<ans;
//Input2:
int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
//Output: 12
cout<<"Method Recursion: "<<endl;
int ans=findPathsRecursion(m, n, maxMove, startRow, startColumn);
cout<<ans<<" "<<endl;
cout<<"Recursion + memoisation: "<<endl;
vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
ans=findPathRecMemoisation(m, n, maxMove, startRow, startColumn, dp);
cout<<ans<<" "<<endl;
cout<<"Method Tabulation: "<<endl;
ans=findPathTabulation(m, n, maxMove, startRow, startColumn);
cout<<ans<<endl;
}