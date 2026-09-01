class Solution {
public:
    int firstUniqChar(string s) {
        int seen[26]={0};
        for(int i = 0; i < s.length(); i++){
            seen[s[i]-'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(seen[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};

//implementing using queue when you have DATA STREAM
// class Solution {
// public:
//     int firstUniqChar(string s) {
//         queue<int> q;
//         int seen[26]={0};
//         for(int i = 0; i < s.length(); i++){
//             seen[s[i]-'a']++;
//             q.push(i);
//         }
//         while(!q.empty()){
//             if(seen[s[q.front()]-'a']==1){
//                 return q.front();
//             }
//             else q.pop();
//         }
//         return -1;
//     }
// };
