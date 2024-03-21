#include <bits/stdc++.h>
using namespace std;
int count(vector<int>v,int mid)
{
  int s=0,e=v.size()-1;
  while (s<=e)
  {
    int midinner=s+(e-s)/2;
    if (v[midinner] <= mid)
    {
      s=midinner+1;
    }
    else
    {
      e=midinner-1;
    }
  }
  return s;
}
int findMedian(vector<vector<int>> arr)
{
  int s=1;
  int e=INT_MAX;
  int n=arr.size();
  int m=arr[0].size();
  while (s<=e)
  {
    int mid=s+(e-s)/2;
    int c=0;
    for (int i=0;i<n;i++)
    {
      c+=count(arr[i],mid);
    }
    if (c<=(n*m)/2){
      s=mid+1;
    }
    else{
      e=mid-1;
    }
  }
  return s;
}
int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    cout<<findMedian(arr)<<endl;
    return 0;
}