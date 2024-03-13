#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>& arr,int mid,int target)
{
    for (int i=0;i<arr.size()-mid;i++) {
        int sum=0;
        for (int j=i;j<=i+mid;j++) {
            sum += arr[j];
        }
        if (sum>target) {
            return false;
        }
    }
    return true;
}
int findMaxSubarraySum(vector<int>& arr, int n, int sum) 
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(ispossible(arr,mid,sum))
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return ans+1;
}
int main()
{
    vector<int> arr={1,4,3,2};
    int n=arr.size();
    int s=7;
    int max_subarray_sum=findMaxSubarraySum(arr, n, s);
    cout << "Maximum subarray sum: "<< max_subarray_sum <<endl;
    return 0;
}