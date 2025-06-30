// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        int n = exp.length();
        stack<string>st;
        int i = 0;
        while(i < n){
            if(exp[i] >= 'A' && exp[i] <='Z' ||
            exp[i] >= 'a' && exp[i] <='z' ||
            exp[i] >= '0' && exp[i] <='9' ){
                st.push(string(1 , exp[i]));
            }else{
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string convertedS = '(' + t2 + exp[i] + t1 + ')' ;
                st.push(convertedS);
            }
            i++;
        }
        return st.top();
    }
};