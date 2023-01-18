class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int goal = len -1 ;

        for(int i=len-2;i>=0;i--){
            if(i+nums[i]>=goal){
                goal = i;
            }
        }
        return (goal==0);
    }
};
