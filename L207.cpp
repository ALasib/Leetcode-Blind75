class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>graph[numCourses];
        int indegree[numCourses];
        memset(indegree,0,sizeof(indegree));
        int len = prerequisites.size();
        
        for(int i=0;i<len;i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        
        set<pair<int,int>>s;
        for(int i=0;i<numCourses;i++){
            s.insert(make_pair(indegree[i],i));
        }
        
        while(!s.empty()){
            pair<int,int> top = *s.begin();
            s.erase(s.begin());
            
            if(top.first!=0){
                return false;
            }
            
            int sz = graph[top.second].size();
            for(int i=0;i<sz;i++){
                int v = graph[top.second][i];
                if(s.find(make_pair(indegree[v],v))!=s.end()){
                    s.erase(make_pair(indegree[v],v));
                }
                indegree[v]--;
                s.insert(make_pair(indegree[v],v));
            }
        }
        return true;
    }
};

//you tube link: https://www.youtube.com/watch?v=EgI5nU9etnU&list=PLot-Xpze53ldBT_7QA8NVot219jFNr_GI&index=2
