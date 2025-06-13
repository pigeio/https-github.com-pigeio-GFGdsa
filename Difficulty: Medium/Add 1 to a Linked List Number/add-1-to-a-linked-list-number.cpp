/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int favour(Node* temp){
        if(temp == NULL){
            return 1;
        }
        int carry = favour(temp->next);
        temp->data = temp->data + carry;
        if(temp->data >= 10) return 1;
        if(temp->data < 10) ;
        return 0;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry  = favour(head);
        if(carry == 1){
            Node* newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        return head;
        // return head of list after adding one
    }
};