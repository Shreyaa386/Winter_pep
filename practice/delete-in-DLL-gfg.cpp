/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        if(head==NULL)
        return NULL;
        
        Node* curr= head;
        if(x==1){
            head=head->next;
            if(head!=NULL)
            head->prev=NULL;
            delete curr;
            return head;
        }
        for(int i=1;i<x && curr!=NULL ;i++){
            curr=curr->next;
        }
        if(curr==NULL)
        return head;
        curr->prev->next = curr->next;
        if(curr->next!=NULL)
        curr->next->prev=curr->prev;
        delete curr;
        return head;
    }
};