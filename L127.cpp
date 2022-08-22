class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        unordered_set<string> dict;
        for(int i=0;i<len;i++){
            dict.insert(wordList[i]);
        }
        
        queue<string> q;
        q.push(beginWord);
        int res = 1;
        
        while(!q.empty()){
            int cnt = q.size();
            
            for(int i=0;i<cnt;i++){
                string curWord = q.front();
                q.pop();
                
                if(curWord==endWord){
                    return res;
                }
                
                int sz = curWord.size();
                if(dict.find(curWord)!=dict.end()){
                    dict.erase(curWord);
                }
                
                for(int j=0;j<sz;j++){
                    char c = curWord[j];
                    for(int k=0;k<26;k++){
                        curWord[j]=k+'a';
                        if(dict.find(curWord)!=dict.end()){
                            q.push(curWord);
                            dict.erase(curWord);
                        }
                        curWord[j]=c;
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
