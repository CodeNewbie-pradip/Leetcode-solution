#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray1(vector<int>& nums)
{
    vector<int>pos;
    vector<int>neg;
    vector<int>ans;

    for(auto num: nums)
    {
        (num > 0 ? pos : neg).push_back(num);
    }

    for(int i=0; i<pos.size(); i++)
    {
        ans.push_back(pos[i]);
        ans.push_back(neg[i]);
    }
    return ans;
}

//approach 2
vector<int> rearrangeArray2(vector<int>& nums)
{
    vector<int> ans(nums.size());
    int i=0, j=1;
    for(auto num: nums)
    {
        if(num>0)
        {
            ans[i]=num;
            i+=2;
        }
        else
        {
            ans[j]=num;
            j+=2;
        }
    }
    return ans;
}

int main()
{
    vector<int>nums={3,1,-2,-5,2,-4};
    //vector<int>nums={-1, 1};
    //Output: [3,-2,1,-5,2,-4]
    cout<<"beefore"<<endl;
    for(auto i: nums)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //vector<int>ans=rearrangeArray1(nums);
    vector<int>ans=rearrangeArray2(nums);
    cout<<"After"<<endl;
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
}