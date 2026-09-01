class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int nStudents = students.size(), StudentsWhoATE = 0, rejections = 0;
        for(int i=0 ; i<nStudents; i++){
            q.push(students[i]);
        }
        while(!q.empty() && rejections < q.size()){
            if(q.front() == sandwiches[StudentsWhoATE]){
                StudentsWhoATE++;
                q.pop();
                rejections=0;
            }
            else{
                int first = q.front();
                q.pop();
                q.push(first);
                rejections++;
            }
        }
        return nStudents-StudentsWhoATE;
    }
};