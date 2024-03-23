#include<bits/stdc++.h>
using namespace std;

int countArray(vector<int> arr,int val)
{
    int s=0,e=arr.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]<=val)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return s;
}

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int s=min(arr1[0],arr2[0]);
    int e=max(arr1[n-1],arr2[m-1]);
    int ans=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int count=countArray(arr1,mid);
        count+=countArray(arr2,mid);
        if(count>=k)
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    int n,m,k;
    cin>>n;
    vector<int> arr1(n);
    for(auto i=0;i<n;i++) cin>>arr1[i];
    cin>>m;
    vector<int> arr2(m);
    for(auto i=0;i<m;i++) cin>>arr2[i];
    cin>>k;
    cout<<kthElement(arr1,arr2,n,m,k)<<endl;
    return 0;
}