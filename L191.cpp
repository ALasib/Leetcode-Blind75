class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            n&=(n-1); //removing last one bit everytime
            res++;
        }
        return res;
    }
}; 

// youtube link: https://www.youtube.com/watch?v=5Km3utixwZs&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=11
