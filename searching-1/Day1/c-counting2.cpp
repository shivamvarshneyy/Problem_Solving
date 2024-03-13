#include<bits/stdc++.h>
using namespace std;
long long int bs_find(vector<long long int>& arr,long long int target)
    {
        long long int s=0;
        long long int e=arr.size()-1;
        long long int pos=arr.size();
        while(s<=e)
        {
            long long int mid=s+(e-s)/2;
            if(arr[mid]>=target)
            {
                pos=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return pos;
    }
  int main()
  {
      long long int n,q,k;
      cin>>n>>q;
      vector<long long int> arr;
      for(int i=0;i<n;i++)
      {
        cin>>k;
        arr.push_back(k);
      }
      vector<long long int> que;
      for(int i=0;i<q;i++)
      {
        cin>>k;
        que.push_back(k);
      }
      sort(arr.begin(),arr.end());
      for(int i=0;i<q;i++)
      {
        int r=bs_find(arr,que[i]);
        cout<<n-r<<endl;
      }
      return 0;
    }