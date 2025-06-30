// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        int n = pre_exp.length();
        stack<string>st;
        int i = n-1;
        while(i >= 0){
            if( pre_exp[i] >= 'A' &&  pre_exp[i] <= 'Z' ||
            pre_exp[i] >= 'a' &&  pre_exp[i] <= 'z' ||
            pre_exp[i] >= '0' &&  pre_exp[i] <= '9'){
                st.push(string(1 ,  pre_exp[i]));
            }else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string convertedS = t1 + t2 +  pre_exp[i];
                st.push(convertedS);
            }
            i--;
        }
        return st.top();
    }
};