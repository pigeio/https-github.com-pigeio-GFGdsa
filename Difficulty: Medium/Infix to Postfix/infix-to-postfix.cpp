class Solution {
  public:
    int priority(char op){
        if(op == '^') return 3;
        if(op == '*' || op == '/') return 2;
        if(op == '+' || op == '-')return 1;
        return 0;
    }
    string infixToPostfix(string& s) {
        // code here
        stack<char>st;
        string ans = "";
        int n = s.length();
        
        for (int i = 0; i < n ; i++){
            if(s[i] >= 'A' && s[i] <= 'Z' ||
            s[i] >= 'a' && s[i] <= 'z' ||
            s[i] >= '0' && s[i] <= '9'){
               ans += s[i];
               
               
            }else if(s[i] == '('){
                st.push(s[i]);
                
            }else if(s[i]==')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }else{
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
