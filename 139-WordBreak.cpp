#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

bool wordBreak1(int idx, int n, string s, vector<string>& wordDict, unordered_set<string> &st)
{
    if(idx==n)
    {
        return true;
    }
    
    if(st.find(s) != st.end())
    {
        return true;
    }
        
    for(int len=0; len<n; len++)
    {
        string temp=s.substr(idx, len);
        if(st.find(temp)!=st.end() && wordBreak1(idx+len, n, s, wordDict, st))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak2(int idx, int n, string s, vector<string>& wordDict, vector<int> &dp, unordered_set<string> &st)
{
    if(idx==n)
    {
        return true;
    }
    
    if(st.find(s) != st.end())
    {
        return true;
    }
    
    if(dp[idx] != -1)
    {
        return dp[idx];
    }
        
    for(int len=0; len<n; len++)
    {
        string temp=s.substr(idx, len);
        if(st.find(temp)!=st.end() && wordBreak2(idx+len, n, s, wordDict, dp, st))
        {
            return dp[idx]= true;
        }
    }
    return dp[idx]=false;
}

int main()
{
// Example 1:
    string s = "leetcode";
    int n=s.length();
    vector<string> wordDict = {"leet","code"};
    unordered_set<string>st;
    for(auto word: wordDict)
    {
        st.insert(word);
    }
    vector<int>dp(n+1, -1);
    cout<<"Recursion Solu : "<<wordBreak1(0, n, s, wordDict, st)<<endl;
    cout<<"Recursion + Mem: " <<wordBreak2(0, n, s, wordDict, dp, st)<<endl;
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false
}