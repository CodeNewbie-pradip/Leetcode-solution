#include<iostream>
#include<vector>
using namespace std;


bool isValid(vector<string>&board, int row, int col)
{
    //upside
    for(int i=row-1; i>=0; i--)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }

    //left adjacent
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }

    for(int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }

    return true;
}

void solve(vector<vector<string>>& result, vector<string>& board, int row)
{
    
}

vector<vector<string>> solveNQueens(vector<vector<string>>& result, vector<string>& board, int row)
{
    if(row==board.size())
    {
        result.push_back(board);
    }

    for(int col=0; col<board.size(); col++)
    {
        if(isValid(board, row, col))
        {
            board[row][col]='Q';
            solveNQueens(result, board, row+1);
            board[row][col]='.';
        }
    }
    return result;
}

int main()
{
    int n;
    cout<<"enter num"<<endl;
    cin>>n;
    vector<vector<string>>result;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>>ans =solveNQueens(result, board, 0);
    for(auto i: ans)
    {
        for(string j: i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}