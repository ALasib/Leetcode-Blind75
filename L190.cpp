class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i=0;i<32;i++){
            uint32_t bit = (n>>i)&1;
            res|=(bit<<(31-i));
        }
        return res;
    }
};

//you tube link: https://www.youtube.com/watch?v=UcoN6UjAI64&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=14
