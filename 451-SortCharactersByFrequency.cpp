#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
/*Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.*/
string frequencySort(string& s)
{
    vector<pair<char, int>>vec(122, {0, 0});

    for(auto ch: s)
    {
        vec[ch].first=ch;
        vec[ch].second++;
    }

    auto lambda=[&](pair<char, int>& p1, pair<char, int>& p2)
    {
        return p1.second > p2.second;
    };

    sort(begin(vec), end(vec), lambda);

    string result="";
    for(auto p: vec)
    {
        if(p.second>0)
        {
            result+=string(p.second, p.first);
        }
    }
    return result;
}
int main()
{
//Example 1:
    string s = "tree";
    string ans=frequencySort(s);
    cout<<ans<<endl;
//Output: "eert"
//Explanation: 'e' appears twice while 'r' and 't' both appear once.
//So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//Example 2:
    string s1 = "cccaaa";
    string ans2=frequencySort(s1);
    cout<<ans2<<endl;
//Output: "aaaccc"
//Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
//Note that "cacaca" is incorrect, as the same characters must be together.
//Example 3:
//Input: s = "Aabb"
//Output: "bbAa"
//Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
//Note that 'A' and 'a' are treated as two different characters.
}