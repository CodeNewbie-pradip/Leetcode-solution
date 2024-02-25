#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
You are given an integer array nums of size n and a positive integer k.
Divide the array into one or more arrays of size 3 satisfying the following conditions:
Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, 
an empty array. And if there are multiple answers, return any of them.
Example 1:
Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
Output: [[1,1,3],[3,4,5],[7,8,9]]
Explanation: We can divide the array into the following arrays: [1,1,3], [3,4,5] and [7,8,9].
The difference between any two elements in each array is less than or equal to 2.
Note that the order of elements is not important.

Example 2:
Input: nums = [1,3,3,2,7,3], k = 3
Output: []
Explanation: It is not possible to divide the array satisfying all the conditions.
*/

vector<vector<int>> divideArray(vector<int>& nums, int k)
{
    int n=nums.size();
    vector<vector<int>>result;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i+=3)
    {
        if(nums[i+2]-nums[i]>k)
        {
            return {};
        }
        result.push_back({nums[i], nums[i+1], nums[i+2]});
    }
    return result;
}

int main()
{
    // vector<int>nums={1,3,4,8,7,9,3,5,1};
    // int k=2;
    // vector<vector<int>>ans=divideArray(nums, k);
    // for(int i=0; i<ans.size(); i++)
    // {
    //     cout<<"[";
    //     for(int j=0;j<ans[0].size(); j++)
    //     {
    //         cout<<ans[i][j];
    //     }
    //     cout<<"] ";
    // }

    vector<int>nums{1,3,3,2,7,3};
    int k=3;
    vector<vector<int>>ans=divideArray(nums, k);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<"[";
        for(int j=0;j<ans[0].size(); j++)
        {
            cout<<ans[i][j];
        }
        cout<<"] ";
    }
}