// Question Link :- https://leetcode.com/problems/sort-colors/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sortZerosOnesAndTwos(vector<int> & arr)
{
    int zeros=0;
    int ones=0;
    int twos=arr.size()-1;
    while(ones<twos)
    {
        if(arr[ones]==0)
        {
            swap(arr[zeros],arr[ones]);
            zeros++;
            ones++;
        }
        else if(arr[ones]==1)
        {
            ones++;
        }
        else
        {
            swap(arr[ones],arr[twos]);
            twos--;
        }
    }
}

int main()
{
    vector<int> arr= {1,0,2,1,1,1,0,0,0,2,1,0,1};
    sortZerosOnesAndTwos(arr);

    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    
}