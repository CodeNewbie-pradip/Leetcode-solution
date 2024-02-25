#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int numSubMatrixTarget(vector<vector<int>>& matrix, int target)
{
    int rows=matrix.size();
    int cols=matrix[0].size();
    int result=0;

    //calculate the cummulative sum
    for(int i=0; i<rows; i++)
    {
        for(int j=1; j<cols; j++)
        {
            matrix[i][j]+=matrix[i][j-1];
        }
    }

    for(int col1 = 0; col1 < cols; ++col1) 
    {
        for (int col2 = col1; col2 < cols; ++col2) 
        {
            std::unordered_map<int, int> count; // Map to store cumulative sums and their frequencies
            int currentSum = 0;
            count[0] = 1; // Initialize with 0 to handle submatrices starting from the first row
            // Iterate over all rows
            for (int row = 0; row < rows; ++row) 
            {
                int element = matrix[row][col2] - (col1 > 0 ? matrix[row][col1 - 1] : 0);
                currentSum += element;
                // Check if there is a submatrix with the target sum
                if (count.find(currentSum - target) != count.end()) 
                {
                    result += count[currentSum - target];
                }
                // Update the count of currentSum in the map
                count[currentSum]++;
            }
        }
    }
    return result;
}   

int main()
{
    //vector<vector<int>>matrix{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};//output- 4
    vector<vector<int>>matrix{{1,-1},{-1,1}};//output- 5
    int ans=numSubMatrixTarget(matrix, 0);
    cout<<ans<<endl;
}