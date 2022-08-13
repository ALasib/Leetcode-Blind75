class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        dp[0]=0;
        int offset = 1;
        
        for(int i=1;i<=n;i++){
            if(offset*2==i){
                offset = i;
            }
            dp[i]=1+dp[i-offset];
        }
        return dp;
    }
};

// you tube link: https://www.youtube.com/watch?v=RyBM56RIWrM&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=12
