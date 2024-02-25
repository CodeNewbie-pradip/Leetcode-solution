#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        cout<<"i= "<<i<<endl;
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prevIndex = st.top();
            st.pop();
            cout<<"prevIndex= "<<prevIndex<<endl;
            cout<<"result[prevIndex]= "<<prevIndex<<" = "<<" i - prevIndex= "<< i - prevIndex<<endl;
            result[prevIndex] = i - prevIndex;
        }
        st.push(i);
    }

    return result;
}

int main() {
    // Example usage:
    vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    vector<int> result1 = dailyTemperatures(temperatures1);
    cout<<"printing result"<<endl;
    for(auto i: result1)
    {
        cout<<i<<" ";
    }

    //vector<int> temperatures2 = {30,40,50,60};
    //vector<int> result2 = dailyTemperatures(temperatures2);

    //vector<int> temperatures3 = {30,60,90};
    //vector<int> result3 = dailyTemperatures(temperatures3);

    return 0;
}