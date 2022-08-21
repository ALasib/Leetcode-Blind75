class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int indegree[numCourses];
        memset(indegree,0,sizeof(indegree));
        vector<int>graph[numCourses];
        set<pair<int,int>>s;
        vector<int>ans;
        int len = prerequisites.size();
        
        for(int i=0;i<len;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        for(int i=0;i<numCourses;i++){
            s.insert({indegree[i],i});
        }
        
        while(!s.empty()){
            pair<int,int> top = *s.begin();
            int edges = top.first;
            int node = top.second;
            s.erase(s.begin());
            
            if(edges!=0){
                return {};
            }
            ans.push_back(node);
            int l = graph[node].size();
            for(int i=0;i<l;i++){
                int dis = graph[node][i];
                if(s.find({indegree[dis],dis})!=s.end()){
                    s.erase({indegree[dis],dis});
                }
                indegree[dis]--;
                s.insert({indegree[dis],dis});
            }
        }
        return ans;
    }
};
