#include<iostream>
using namespace std;

string decodeMessage(string key, string message)
{
    char alphabet='a';
    char mapping[256]={0};
    //create mapping
    for(auto ch: key)
    {
        if(ch!=' ' && mapping[ch]==0)
        {
            mapping[ch]=alphabet;
            alphabet++;
        }
    }
    //use mapping
    string ans;
    for(auto ch:message)
    {
        if(ch==' ')
        {
            ans.push_back(ch);
        }
        else{
            char decodechar=mapping[ch];
            ans.push_back(decodechar);
        }
    }
    return ans;
}

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message="vkbs bs t suepuv";
//Output: "this is a secret"
    cout<<decodeMessage(key, message);

    return 0;
}