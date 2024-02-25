// 387. First Unique Character in a String
// Given a string s, find the first non-repeating character in it and return its index. 
// If it does not exist, return -1.

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> charIndex;

    for(auto c: s)
    {
        charIndex[c]++;
    }
    for(int i=0; i<s.length(); i++)
    {
        if(charIndex[s[i]]==1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
// Example 1:
    string s = "leetcode";
    int ans=firstUniqChar(s);
    cout<<ans<<endl;
// Output: 0
// Example 2:
    s = "loveleetcode";
    ans=firstUniqChar(s);
    cout<<ans<<endl;
// Output: 2
// Example 3:
    s = "aabb";
    ans=firstUniqChar(s);
    cout<<ans<<endl;
// Output: -1
}