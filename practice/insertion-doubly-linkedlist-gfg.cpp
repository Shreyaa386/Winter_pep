/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* newNode = new Node(x);
       
        Node* curr = head;
        for(int i=0;i<p ;i++){
            curr= curr->next;
        }
        if(curr==NULL)
        return head;
        newNode->next=curr->next;
        newNode->prev = curr;
        if(curr->next!=NULL)
        curr->next->prev=newNode;
        curr->next=newNode;
        return head;
    }
};