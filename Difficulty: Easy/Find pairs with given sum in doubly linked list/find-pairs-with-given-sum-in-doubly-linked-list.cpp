// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    Node* findTail(Node* head){
        Node* tail = head;
        while(tail && tail->next != NULL){
            tail = tail->next;
            
        }
        return tail;
    }
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        Node* left = head;
        Node* right = findTail(head);
        vector<pair<int,int>>result;
        
        while(left->data < right->data){
            int sum = left->data + right->data;
            if(sum == target){
                result.push_back({left->data , right->data});
                left = left->next;
                right = right->prev;
            }else if(sum < target){
                left = left->next;
            }else{
                right = right->prev;
            }
        }
        return result;
        
    }
};