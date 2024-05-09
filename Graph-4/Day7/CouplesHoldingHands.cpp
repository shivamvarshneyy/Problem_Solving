class Solution {
public:

    int findpos(int pair, vector<int> &row){
        int i=0;
        for(i=0; i<row.size(); i++){
            if(row[i]==pair){
                return i;
            }
        }
        return -1;
    }

    int minSwapsCouples(vector<int>& row) {
        int count=0;
        for (int i=0; i<row.size(); i+=2) {
            int pair = row[i] ^ 1;
            if (row[i+1] == pair) {
                continue;
            }
            int pos = findpos(pair, row); 
            swap(row[pos], row[i+1]);
            count += 1;
        }
        return count;
    }
};