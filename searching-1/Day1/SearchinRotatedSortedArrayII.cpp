class Solution {
public:
    bool search(vector<int>& v, int t) {
        int n=v.size(),i;
        int s=0;
        int e=n-1,mid;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(v[mid]==t)
            {
                return true;
            }
            if((v[s]==v[mid]) && (v[e] == v[mid]))
            {
                s++;
                e--;
            }
            else if(v[s]<=v[mid])
            {
                if(t>=v[s] && t<v[mid])
                e=mid-1;
                else
                s=mid+1;
            }
            else
            {
                if(t>v[mid] && t<=v[e])
                s=mid+1;
                else
                e=mid-1;
            }   
        }
    return false;
    }
};