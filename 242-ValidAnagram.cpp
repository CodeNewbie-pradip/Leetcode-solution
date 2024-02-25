#include<iostream>
#include<string>
using namespace std;

//why taking 256 frequency
//char 1byte=> 8bit means range is 2^8=>256
//that's taking frequency size is 256
//approach 1->
bool isAnagram(string s, string t) 
{
    int frequency[256]={0};
    for(auto ch: s)
    {
        cout<<"ch->"<<ch<<" ";
        frequency[ch]++;
        cout<<"frequency[ch]-> "<< frequency[ch]<<endl;
    }
    for(auto ch: t)
    {
        frequency[ch]--;
    }
    for(int i=0; i<256; i++)
    {
        if(frequency[i]!=0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    //Example 1:
    string s = "anagram";
    string t = "nagaram";
    //Output: true
    if(isAnagram(s, t))
    {
        cout<<"true! it is anagram"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    
    //Example 2:
    cout<<endl;
    cout<<"Example->2 "<<endl;
    string s1 = "rat";
    string t1 = "car";
    if(isAnagram(s1, t1))
    {
        cout<<"true! it is anagram"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    //Output: false
}