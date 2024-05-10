#include <bits/stdc++.h>
using namespace std;
long long solve(long long x,long long y,long long z,long long i,long long p,vector<long long> &arr){
    if(i==arr.size()) {
        if(p==3) 
        return 0;
        else     
        return long long_MIN;
    }
    long long pick=0;
    if(p==0) 
    pick=(x*arr[i])+solve(x,y,z,i+1,p+1,arr);
    else if(p==1) 
    pick=(y*arr[i])+solve(x,y,z,i+1,p+1,arr);
    else if(p==2) 
    pick=(z*arr[i])+solve(x,y,z,i+1,p+1,arr);
    return max(solve(x,y,x,i+1,p,arr),pick);
    
}
signed main()
{
    vector<long long> arr={-1, -2, -3, -4, -5};
    long long x=1,y=-2,z=-3;
    cout<<solve(x,y,z,0,0,arr)<<endl;
    return 0;
}