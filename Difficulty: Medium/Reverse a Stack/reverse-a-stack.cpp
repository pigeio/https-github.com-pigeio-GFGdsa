// User function Template for C++

class Solution {
  public:
    void insertBottom(stack<int>&st , int element){
        //Base case
        if(st.empty()){
            st.push(element);
            return ;
        }
        int num = st.top();
        st.pop();
        
        insertBottom(st , element);
        st.push(num);
    }
    void Reverse(stack<int> &St) {
        // Base case
        if(St.empty()){
            return ;
        }
        
        int top = St.top();
        St.pop();
        Reverse(St);
        insertBottom(St , top);
    }
};