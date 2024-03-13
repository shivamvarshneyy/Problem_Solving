class Solution {
private:
    int maxLengthSubarray(int arr[],int k,int n)
    {
            int maxLength = 0;
            int currentSum = 0;
            int s=0;
            for(int i=0;i<n;i++) {
                currentSum+=arr[i];
                while (currentSum>k && s<=i) {
                    currentSum-=arr[s];
                    s++;
                }
                int currentLength=i-s+1;
                maxLength=max(maxLength,currentLength);
            }
            return maxLength;
    }
public:
    int equalSubstring(string s, string t, int maxCost) {
        int arr[s.length()];
        for(int i=0;i<s.length();i++){
            arr[i]=abs(s[i]-t[i]);
        }
        return maxLengthSubarray(arr,maxCost,s.length());
    }
};