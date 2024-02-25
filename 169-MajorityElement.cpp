// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//approach 1: sort methods
int majorityElement1(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

//approach 2 : Boyer-Moore Majority Voting Algorithm
int majorityElement2(vector<int>& nums)
{
    int n=nums.size();
    int major=nums[0];
    int count=1;

    for(int i=1; i<n; i++)
    {
        if(count==0)
        {
            major=nums[i];
        }
        if(nums[i]==major)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return major;
}
int main()
{
// Example 1:
    vector<int>nums={3, 2, 3};
    cout<<majorityElement1(nums)<<endl;
    cout<<majorityElement2(nums)<<endl;
// Output: 3
// Example 2:
    vector<int>nums1={2 , 2, 1, 1, 1, 2, 2};
    cout<<majorityElement1(nums1)<<endl;
    cout<<majorityElement2(nums1)<<endl;
// Output: 2
}