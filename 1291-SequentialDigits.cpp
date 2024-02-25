// 1291. Sequential Digits
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
T.C- O(n) n means sequencial digit
S.C- O(n)*/
vector<int>sequentialDigits1(int low, int high)
{
    //approach is bfs any
    queue<int> q;
    vector<int> result;
    for(int i=1; i<=8; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        int temp=q.front();
        q.pop();

        if(temp>=low && temp<=high)
        {
            result.push_back(temp);
        }

        int lastDigit=temp%10;
        if(lastDigit+1<=9)
        {
            q.push(temp*10+(lastDigit+1));
        }
    }
    return result;
}

/*
T.C-O(1)
S.C- O(1)
*/
vector<int>sequentialDigits2(int low, int high)
{
    vector<int>result;
    vector<int> digit={ 12, 23, 34, 45, 56, 67, 78, 89,
                        123, 234, 345, 456, 567, 678, 789, 
                        1234, 2345, 3456, 4567, 5678, 6789,
                        12345, 23456, 34567, 45678, 56789,
                        123456, 234567, 345678, 456789,
                        123456, 234567, 345678, 456789,
                        1234567, 2345678, 3456789,
                        12345678,
                        123456789};

    for(int i=0; i<digit.size(); i++)
    {
        if(digit[i]<=low) 
        {
            continue;
        }
        else if(digit[i]>=high)
        {
            break;
        }
        else
        {
            result.push_back(digit[i]);
        }
    }
    return result;
}

int main()
{
//Example 1:
    int low = 100, high = 300;
    vector<int> ans=sequentialDigits2(low, high);
    int n=ans.size();
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
//Output: [123,234]
//Example 2:
    //int low = 1000, high = 13000;
//Output: [1234,2345,3456,4567,5678,6789,12345]
}