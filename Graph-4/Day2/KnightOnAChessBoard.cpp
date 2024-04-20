int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>> visited(A,vector<int>(B,0));
    queue<vector<int>> q;
    q.push({C-1,D-1});
    visited[C-1][D-1]=1;
    vector<vector<int>> direction={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,2},{1,-2},{2,-1},{2,1}};
    int c=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size!=0){
        int x=q.front()[0];
        int y=q.front()[1];
        q.pop();
        if(x==E-1 && y==F-1) 
        return c;
        for(int i=0;i<8;i++)
        {
            int u=x+direction[i][0],v=y+direction[i][1];
            if(u>=0 && v>=0 && u<A && v<B && !visited[u][v]){
                q.push({u,v});
                visited[u][v]=1;
            }
        }
        }
        c++;
    }
    return -1;
}