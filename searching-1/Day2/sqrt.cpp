class Solution {
public:
    int mySqrt(int x) {
        int s=1,e=x,mid,i;
        if(x==0||x==1)
            {
              return x;
            }
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(mid==x/mid){
              return mid;
            }
            else if(mid>x/mid){
              e=mid-1;
            }
            else{
              s=mid+1;
            }
        }
        return e;
    }
};