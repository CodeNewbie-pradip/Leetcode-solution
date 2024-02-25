#include<iostream>
using namespace std;
bool isPowerOfTwo1(int n)
{
    if(n<=0)
    {
        return false;
    }

    return (n&(n-1))==0;

    /*
    n=8, n-1=7
    1000 & 0111=0000
    when answer 0 false

    n=6, n-1=5
    1010 & 1001=1000
    when answer anothe then fasle
    */
}

bool isPowerOfTwo2(int n)
{
    if(n<=0)
    {
        return false;
    }

    if(n==1)
    {
        return true;
    }

    return n%2==0 && isPowerOfTwo2(n/2);
    /*
    true case
    n=32
    32%2==0 32/2=16
    16%2==0 8/2=4
    4%2==0  4/2=2
    2%2==0  2/2=1 
    return 2%2 && n==1

    false case
    n=30
    30%2==0 30/2=15
    return 15%2==1 15/2=7 
    */
}
int main()
{
    int n=64;
    cout<<isPowerOfTwo1(n)<<endl;
    cout<<isPowerOfTwo2(n)<<endl;
    n=72;
    cout<<isPowerOfTwo1(n)<<endl;
    cout<<isPowerOfTwo2(n)<<endl;
}