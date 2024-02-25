#include<iostream>
#include<vector>
using namespace std;

//approach 1: recursive(getting TLE)
//approach 2: Rec + memo
//approach 3: Tabulation
int main()
{
    //Example 1:
    vector<int> nums={10,9,2,5,3,7,101,18};
    //Output: 4
    //Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
    //Example 2:
    //
    vector<int> nums = {0,1,0,3,2,3};
    //Output: 4
    //Example 3:
    //
    vector<int> nums = {7,7,7,7,7,7,7};
    //Output: 1
}