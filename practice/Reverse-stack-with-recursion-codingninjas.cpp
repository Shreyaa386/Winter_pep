
void insertatbottom(stack<int>& stack , int x){
    if(stack.empty()){
        stack.push(x);
        return ;

    }
    int top = stack.top();
    stack.pop();
    insertatbottom(stack,x);
    stack.push(top);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty())
    return;
    int topelement=stack.top();
    stack.pop();
    reverseStack(stack);
    insertatbottom(stack, topelement);
}