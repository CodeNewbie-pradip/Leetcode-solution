#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

string CustomSortString(string order, string s)
{
    /* The & in [&] means "capture by reference." 
    It allows the lambda to access and modify the variables from the surrounding scope by reference, 
    meaning changes inside the lambda affect the original variables outside the lambda.*/
    auto compare=[&](char a, char b)
    {
        return order.find(a)<order.find(b);
    };

    sort(s.begin(), s.end(), compare);

    return s;
}

int main()
{
    // string order="cba";
    // string s="abcd";
    //Output: "cbad"

    string order = "cbafg";
    string s = "abcd";
    //Output: "cbad"
    cout<<CustomSortString(order, s);
}