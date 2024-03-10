class Solution {
private:
    int bs_firstocc(vector<int> nums,int target)
    {
        int s=0;
        int e=nums.size()-1;
        int pos=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                pos=mid;
                e=mid-1;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return pos;
    }
    int bs_lastocc(vector<int> nums,int target)
    {
        int s=0;
        int e=nums.size()-1;
        int pos=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                pos=mid;
                s=mid+1;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return pos;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {bs_firstocc(nums,target),bs_lastocc(nums,target)};
    }
};