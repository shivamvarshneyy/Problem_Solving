#include<bits/stdc++.h>
using namespace std;
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]>nums[j])
            {
                i=mid+1;
            }
            else
            {
                j=mid;
            }
        }
        return nums[i];
    }
int main(){
    vector<int> nums = {3,5,8,1,2};
    cout << findMin(nums) << endl;  
    return 0;
}