class Solution {
private:
    int bs(vector<int>& nums,int n,int m)
    {
        int s=0,e=n-1,ans=INT_MIN;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==m)
            {
                return mid;
            }
            else if(nums[mid]<m)
            {
                s=mid+1;
                ans=max(ans,mid+1);
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int s=0,e=0;
        int min1=*min_element(nums1.begin(),nums1.end());
        int min2=*min_element(nums2.begin(),nums2.end());
        int max1=*max_element(nums1.begin(),nums1.end());
        int max2=*max_element(nums2.begin(),nums2.end());
        s=min(min1,min2);
        e=max(max1,max2);
        int c=0;
        int ans=0;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            c=bs(nums1,n,mid);
            c+=bs(nums2,m,mid);
            if(c<(n+m)/2)
            {
                ans=mid;
                s=mid+1;
            }
            else if(c>(n+m)/2)
            e=mid-1;
            else
            {
                ans=mid;
                s=mid+1;
            }
        }
        if((n+m)%2==0)
        {
            int c1=0;
            int ans1=0;
            min1=*min_element(nums1.begin(),nums1.end());
            min2=*min_element(nums2.begin(),nums2.end());
            max1=*max_element(nums1.begin(),nums1.end());
            max2=*max_element(nums2.begin(),nums2.end());
            s=min(min1,min2);
            e=max(max1,max2);
            while(s<=e)
            {
                int mid=s+(e-s)/2;
                c1=bs(nums1,n,mid);
                c1+=bs(nums2,m,mid);
                if(c1<((n+m)/2)-1)
                {
                    ans1=mid;
                    s=mid+1;
                }
                else if(c1>((n+m)/2)-1)
                e=mid-1;
            }
            return double(ans+ans1)/2;
        }
        return ans;
    }
};