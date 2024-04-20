class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        vector<int> res;
        for(auto x:edges){
            s.insert(x[1]);
        }
        for(int i=0;i<n;i++){
            if(!s.count(i)) 
            res.push_back(i);
        }
        return res;
    }
};