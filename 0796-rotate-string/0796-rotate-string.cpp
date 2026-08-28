class Solution {
public:
    bool rotateString(string s, string goal) {
        int len1 = s.size(), len2 = goal.size();
        
        if(len1 != len2) return false;
        if(len1==0) return true;
        string s2= s+s;

        return s2.find(goal) != string::npos; 
        // this is a better approach as substr always makes new memory to store the substring making the program slower.
        // for(int i=0; i < len1; i++){
        //     if(s[i] == goal[0]){
        //         if(s2.substr(i, len2)==goal) return true;
        //     }
        // }
        // return false;
    }
};