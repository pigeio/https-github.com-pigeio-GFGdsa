/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    int loopLength(Node* slow , Node* fast){
        int count = 1;
        fast = fast->next;
        
        while(fast != slow){
            fast = fast->next;
            count++;
        }
        return count;
    }
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        if(head == NULL || head->next == NULL ) return 0;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                return loopLength(slow , fast);
            }
        }
        return 0;
    }
};