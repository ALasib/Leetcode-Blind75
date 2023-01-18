class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len==1){
            return nums[0];
        }
        int curMax = nums[0];
        int maxSoFar = nums[0];
        for(int i=1;i<len;i++){
            curMax = max(curMax+nums[i],nums[i]);
            maxSoFar = max(maxSoFar, curMax);
        }
        return maxSoFar;
    }
};
