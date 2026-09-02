class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        int seen[26]={0};
        for(int i = 0; i < s.length(); i++){
            seen[s[i]-'a']++;
            q.push(i);
        }
        while(!q.empty()){
            if(seen[s[q.front()]-'a']==1){
                return q.front();
            }
            else q.pop();
        }
        return -1;
    }
};