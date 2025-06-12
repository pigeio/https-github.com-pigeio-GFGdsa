/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
   Node* findMiddle(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    } 
    
    Node* mergeTwoList(Node* list1  , Node* list2){
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(list1 != NULL && list2 != NULL){
            if(list1->data <= list2->data){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;
        return dummyNode->next;
    }
    
    Node* segregate(Node* head) {
        // code here
        if(head == NULL || head->next == NULL){
            return head;
        }

        Node* middle = findMiddle(head);
        Node* right = middle->next;
        middle->next = NULL;
        Node* left  = head; 

        left = segregate(left);
        right = segregate(right);
        return mergeTwoList(left , right);
    }
    
};