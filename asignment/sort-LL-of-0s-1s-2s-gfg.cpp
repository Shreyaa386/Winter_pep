/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int cnt0=0, cnt1=0,cnt2=0;
        Node* curr=head;
        while(curr!=NULL){
            if(curr->data==0) cnt0++;
            else if(curr->data==1) cnt1++;
            else cnt2++;
            curr=curr->next;
        }
        
        curr=head;
        while(cnt0--){
            curr->data=0;
            curr=curr->next;
            
        }
        while(cnt1--){
            curr->data=1;
            curr=curr->next;
        }
        while(cnt2--){
            curr->data=2;
            curr=curr->next;
        }
        return head;
    }
};