/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(head == NULL || head->next == NULL) return head;
        Node* temp1 = head;
        
        
        while(temp1 != NULL && temp1->next != NULL){
            
            if(temp1->data == temp1->next->data){
                Node* duplicate = temp1->next;
                temp1->next = duplicate->next;
                
                if(duplicate->next){
                    duplicate->next->prev = temp1;
                }
                delete duplicate;
                
            }else{
                temp1 = temp1->next;
            }
        }
        return head;
        
    }
};