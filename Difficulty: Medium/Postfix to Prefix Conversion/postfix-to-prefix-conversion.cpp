// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        int n = post_exp.length();
        stack<string>st;
        int i = 0;
        while(i < n){
            if(post_exp[i] >= 'A' && post_exp[i] <= 'Z' ||
            post_exp[i] >= 'a' && post_exp[i] <= 'z' ||
            post_exp[i] >= '0' && post_exp[i] <= '9'){
                st.push(string(1 , post_exp[i]));
            }else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string convertedS =  post_exp[i] + t2 + t1 ;
                st.push(convertedS);
                
                
            }
            i++;
        }
        return st.top();
    }
};