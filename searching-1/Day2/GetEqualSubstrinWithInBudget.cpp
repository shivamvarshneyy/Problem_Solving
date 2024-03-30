class Solution {
public:
    bool subs(int mid,string &s,string &t,int maxCost){
        int cost=0;
        for(int i=0;i<mid;i++){
            cost+=abs(s[i]-t[i]);
        }
        if(cost<=maxCost) return true;
        int st= 0;
        for(int i=mid;i<s.size();i++){
            cost+=abs(s[i]-t[i]);
            cost-=abs(s[st]-t[st]);
            st++;
            if(cost<=maxCost) return true;
        }
        return false;
    }
    int equalSubstring(string s, string t, int maxCost) {
        int st=0;
        int e=s.size();
        cout<<subs(1,s,t,maxCost);
        while(st<e){
            int mid=st+(e-st)/2;
            if(predicate(mid,s,t,maxCost)){
                st=mid+1;
            }else{
                e=mid-1;
            }
        }
        if(subs(st,s,t,maxCost)) return s;
        else return st-1;
    }
};