class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int total = 0;
        
        for(int i=0;i<=len;i++){
            total^=i;
        }
        int arrayTotal = 0;
        for(int i=0;i<len;i++){
            arrayTotal^=nums[i];
        } 
        return total^arrayTotal;
    }
};

//you tube link: https://www.youtube.com/watch?v=WnPLSRLSANE&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=13
