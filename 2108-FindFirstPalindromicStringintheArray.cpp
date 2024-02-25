/*Given an array of strings words, return the first palindromic string in the array. 
If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//approach 1: 2 pointer
string firstPalindrome1(vector<string>& words)
{
    for(auto word: words)
    {
        int i=0, j=word.length()-1;
        while(i<=j)
        {
            if(word[i]==word[j])
            {
                i++;
                j--;
            }
            else
            {
                break;
            }
        }
        if(i>=j)
        {
            return word;
        }
    }
    return "";
}
//approach 2: Reverse the string and check
string firstPalindrome2(vector<string>& words)
{
    for(auto word: words)
    {
        string temp=word;
        reverse(temp.begin(), temp.end());
        if(temp==word)
        {
            return word;
        }
    }
    return "";
}

//approach 3: Form Reveresed String
string firstPalindrome3(vector<string>& words)
{
    for(auto str: words)
    {
        if(str==string(str.rbegin(), str.rend()))
        {
            return str;
        }
    }
    return "";
}
//approach 4: Equal stl
string firstPalindrome4(vector<string>& words)
{
    for(auto word: words)
    {
        int n=word.size();
        if(equal(word.begin(), word.begin()+n/2, word.rbegin()))
        {
            return word;
        }
    }
    return "";
}
int main()
{
// Example 1:
    vector<string>words = {"abc","car","ada","racecar","cool"};
// Output: "ada"
// Explanation: The first string that is palindromic is "ada".
// Note that "racecar" is also palindromic, but it is not the first.
// Example 2:
    vector<string>words2 = {"notapalindrome","racecar"};
// Output: "racecar"
// Explanation: The first and only string that is palindromic is "racecar".
// Example 3:
    vector<string>words3 = {"def","ghi"};
// Output: ""
// Explanation: There are no palindromic strings, so the empty string is returned.
    cout<<"Approach 1: 2 pointer Approach: "<<endl;
    cout<<firstPalindrome1(words)<<endl;
    cout<<firstPalindrome1(words2)<<endl;
    cout<<firstPalindrome1(words3)<<endl;
    cout<<"approach 2: Reverse the string and check: "<<endl;
    cout<<firstPalindrome2(words)<<endl;
    cout<<firstPalindrome2(words2)<<endl;
    cout<<firstPalindrome2(words3)<<endl;
    cout<<"Approach 3:form Reversed string"<<endl;
    cout<<firstPalindrome3(words)<<endl;
    cout<<firstPalindrome3(words2)<<endl;
    cout<<firstPalindrome3(words3)<<endl;
    cout<<"Approach 4: equal STL"<<endl;
    cout<<firstPalindrome4(words)<<endl;
    cout<<firstPalindrome4(words2)<<endl;
    cout<<firstPalindrome4(words3)<<endl;
}