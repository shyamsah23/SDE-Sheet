#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printPermutation(int index,vector<int> & arr,vector<vector<int>> & ans)
{
    if(index>=arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for(int i=index;i<arr.size();i++)
    {
        swap(arr[index],arr[i]);
        printPermutation(index+1,arr,ans);
        swap(arr[index],arr[i]);
    }


}

int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>>ans;

    printPermutation(0,arr,ans);

    for(auto it:ans)
    {
        for(auto j:it)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
