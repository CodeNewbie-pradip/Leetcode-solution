// Evaluate Reverse Polish Notation
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.
// Note that:
// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 
 #include<iostream>
 #include<stack>
 #include<string>
 #include<vector>
 #include<unordered_set>
 using namespace std;

static unordered_set<string> ops({"+", "-", "*","/"});

 int evalRPN(vector<string>& tokens)
 {
    stack<int>st;
    for(auto t: tokens)
    {
        if(ops.find(t)==ops.end())
        {
            st.push(stoi(t));
        }
        else
        {
            //here is catch second value on top means n-1&& first value n-2 
            //| 4 |    operation is 3+4
            //| 3 |    so top b and n-2 is  b=top(), pop(); a=top();
            //------
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(t=="+")
            {
                st.push(a+b);
            }
            else if(t=="-")
            {
                st.push(a-b);
            }
            else if(t=="*")
            {
                st.push(a*b);
            }
            else
            {
                st.push(a/b);
            }
        }
    }
    return st.top();
 }

 int main()
 {
//Example 1:Input: 
vector<string> tokens={"2","1","+","3","*"}; 
int ans= evalRPN(tokens);
cout<<ans<<" "<<endl;
//Output: 9 Explanation: ((2 + 1) * 3) = 9
//Example 2: Input: 
vector<string>tokens1={"4","13","5","/","+"};
ans=evalRPN(tokens1);
cout<<ans<<" "<<endl;
//Output: 6 Explanation: (4 + (13 / 5)) = 6
//Example 3: Input: 
vector<string>tokens2={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
ans=evalRPN(tokens2);
cout<<ans<<" "<<endl;
//Output: 22
 }