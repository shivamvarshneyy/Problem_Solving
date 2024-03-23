int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int s=mat[0][0];
  int e=mat[n-1][n-1];
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int ub=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            cnt+=ub; 
        }
        if(count>=k)
            e=mid-1;
        else
            s=mid+1;
    }
    return s;
}