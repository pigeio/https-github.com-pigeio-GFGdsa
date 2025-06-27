class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode *temp = new StackNode(x);
        temp->next = top;
        top = temp;
    }

    int pop() {
        if(top == NULL) return -1;
        int popped = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    MyStack() { top = NULL; }
};