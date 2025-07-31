/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void sortInsert(stack<int>& s , int element){
    if(s.empty() || s.top() < element){
        s.push(element);
        return;
    }
    
    
    int top = s.top();
    s.pop();
    
    sortInsert(s , element);
    s.push(top);
}

void SortedStack ::sort() {
    // Your code here
    if(s.empty())return;
    
    int top = s.top();
    s.pop();
    
    sort();
    sortInsert(s , top);
}