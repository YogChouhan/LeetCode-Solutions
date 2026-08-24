class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum=0;
        for (string s: operations){
            
            if(s=="C"){
                sum=sum-st.top();
                st.pop();
            }
            else if(s=="D"){
                sum+=st.top()*2;
                st.push(st.top()*2);
            }
            else if(s=="+"){
                int last=st.top();
                st.pop();
                int slast=st.top();
                st.push(last);
                st.push(last+slast);
                sum=sum+last+slast;
            }
            else{
                int num=stoi(s);
                sum+=num;
                st.push(num);
            }
        }
        return sum;
    }
};