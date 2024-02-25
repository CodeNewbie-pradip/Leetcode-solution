#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int solveRec(int idx, vector<int>& heights, int bricks, int ladders)
{
    if(idx>heights.size()-1)
    {
        return 0;
    }

    int diff=heights[idx+1]-heights[idx];
    int ans=0;
    if(diff<=0)
    {
        return 1+solveRec(idx+1, heights, bricks, ladders);
    }
    else
    {
        //ladders bricks
        int ladderCount=0;
        int bricksCount=0;
        if(ladders>0)
        {
            ladderCount=1+solveRec(idx+1, heights, bricks, ladders-1);
        }
        if(bricks>=diff)
        {
            bricksCount=1+solveRec(idx+1, heights, bricks-diff, ladders);
        }
        ans=max(ladderCount, bricksCount);
    }
    return ans;
}

int solveminHeap(vector<int>& heights, int bricks, int ladders)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0; i<=heights.size()-1; i++)
    {
        int diff=heights[i+1]-heights[i];

        if(diff>0)
        {
            minHeap.push(diff);
        }
        if(minHeap.size()>ladders)
        {
            bricks-=minHeap.top();
            minHeap.pop();
        }
        if(bricks<0)
        {
            return i;
        }
    }
    return heights.size()-1;
}

int solvemaxHeap(vector<int>& heights, int bricks, int ladders)
{
    priority_queue<int>maxHeap;

    int i=0;
    for(; i<heights.size()-1; i++)
    {
        int diff=heights[i+1]-heights[i];
        if(heights[i]>=heights[i+1])
        {
            continue;
        }
        if(diff<=bricks)
        {
            bricks-=diff;
            maxHeap.push(diff);
        }
        else if(ladders>0)
        {
           if(!maxHeap.empty())
           {
                int past_bricks=maxHeap.top();
                if(past_bricks < diff)
                {
                    bricks+=past_bricks;
                    maxHeap.pop();
                    maxHeap.push(diff);
                    bricks-=diff;
                }
           }
            ladders--;
        }
        else
        {
            break;
        }
    }
    return i;
}

int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
{
//recursive solution
    // cout<<"Recursive solution: "<<endl;
    // int ans= solveRec(0, heights, bricks, ladders);
    // cout<<ans<<endl;
    //T.C=O(2^n). S>C- O(height.size()) recursion stack
//minHeap solution
    // cout<<"Min-Heap Solution: "<<endl;
    // int ans=solveminHeap(heights, bricks, ladders);
    // return ans;
//maxHeap solution
    cout<<"Max-Heap Solution: "<<endl;
    int ans=solvemaxHeap(heights, bricks, ladders);
    return ans;

}

int main()
{
// Example 1:
    vector<int>heights1 = {4, 2, 7, 6, 9, 14, 12};
    int bricks1 = 5, ladders1 = 1;
    cout<<furthestBuilding(heights1, bricks1, ladders1)<<endl;
// Output: 4
// Explanation: Starting at building 0, you can follow these steps:
// - Go to building 1 without using ladders nor bricks since 4 >= 2.
// - Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
// - Go to building 3 without using ladders nor bricks since 7 >= 6.
// - Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
// It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
// Example 2:
// 
    vector<int> heights2 = {4,12,2,7,3,18,20,3,19};
    int bricks2 = 10, ladders2 = 2;
    cout<<furthestBuilding(heights2, bricks2, ladders2)<<endl;
// Output: 7
// Example 3:
    vector<int>heights3 = {14,3,19,3};
    int bricks3 = 17, ladders3 = 0;
    cout<<furthestBuilding(heights3, bricks3, ladders3)<<endl;
// Output: 3
// Example 4:
    vector<int> heights4= {4,12,2,7,3,18,20,3,19};
    int bricks4= 10, ladders4= 2;
    cout<<furthestBuilding(heights4, bricks4, ladders4)<<endl;
// Output: 7
}