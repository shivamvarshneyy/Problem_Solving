bool ispossible(int u,int v,int C,int D,vector<int> &E,vector<int> &F){
    for(int i=0;i<C;i++){
        double l=sqrt((double)(pow(E[i]-u,2)+pow(F[i]-v,2)));
        if(l<=D) 
        return false;
    }
    return true;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    queue<vector<int>> q;
    vector<vector<int>> visited(A+1,vector<int>(B+1,0));
    q.push({0,0});
    visited[0][0]=1;
    while(!q.empty()){
        int x=q.front()[0];
        int y=q.front()[1];
        q.pop();
        if(x==A && y==B) 
        return "YES";
        vector<vector<int>> direction={{0,-1},{0,1},{1,0},{-1,0}};
        for(int i=0;i<4;i++){
            int u=x+direction[i][0];
            int v=y+direction[i][1];
            if(u>=0 && v>=0 && u<A+1 && v<B+1 && !visited[u][v] && ispossible(u,v,C,D,E,F)){
                q.push({u,v});
                visited[u][v]=1;
            }
        }
    }
    return "NO";
}