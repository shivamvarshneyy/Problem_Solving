class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        if(v.empty()||v[0].empty())
        {
            return false;
        }
        int m=v.size();
        int n=v[0].size();
        int i;
        int s=0;
        int e=m*n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int m=v[mid/n][mid%n];
            if(m==t)
            {
                return true;
            }
            else if(m<t)
            {
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return false;
    }
};