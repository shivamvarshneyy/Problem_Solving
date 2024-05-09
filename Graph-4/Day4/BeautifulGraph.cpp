#include <bits/stdc++.h>
using namespace std;
long long power(long long a,long long b,long long mod){
    if(b==0) return 1;
    if(b==1){
        return a;
    }
    if(b%2==0){
        return power((a*a)%mod,b/2,mod);
    }
    else return (a*power(a,b-1,mod))%mod;
}
long long help(long long s,vector<long long> &col,vector<vector<long long>> &adj)
{
    long long mod=998244353;
    long long f=1,cnt=0,tcnt=0;
    queue<long long> q;
    q.push(s);
    col[s]=f;
    cnt++;
    while(!q.empty()){
        long long size=q.size();
        f=(f+1)%2;
        while(size--){
            long long fr=q.front();
            q.pop();
            tcnt++;
            for(auto x:adj[fr]){
                if(col[x]==-1){
                    if(f) cnt++;
                    col[x]=f;
                    q.push(x);
                }
                else if(col[x]!=f) return 0;
            }
        }
    }
    return (power(2,cnt,mod)%mod+power(2,tcnt-cnt,mod)%mod)%mod;
}
int main()
{
    long long mod=998244353;
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<vector<long long>> adj(n+1);
        vector<long long> col(n+1,-1);
        for(long long i=0;i<m;i++){
            long long u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long cnt=1;
        for(long long i=1;i<=n;i++){
            if(col[i]==-1){
                cnt=(cnt*help(i,col,adj))%mod;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}