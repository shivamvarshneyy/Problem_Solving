#include<bits/stdc++.h>
using namespace std;
int countsum(vector<int>& arr,int val)
{
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>val)
            break;
        sum+=arr[i];
    }
    return sum;
}
int countbooks(vector<int>& arr,int val)
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

int NoOfBooksRead(int n,vector<int>& A,int m,vector<int>& B,int k)
{
    int s=min(A[0],B[0]);
    int e=max(A[n-1],B[m-1]),ans=0;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(countsum(A,mid)+countsum(B,mid)<=k)
        {
            ans=countbooks(A,mid);
            ans+=countbooks(B,mid);
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> A(n),B(m);
    for(auto i=0;i<n;i++) cin>>A[i];
    for(auto i=0;i<m;i++) cin>>B[i];
    cout<<NoOfBooksRead(n,A,m,B,k)<<endl;
    return 0;
}