#include <bits/stdc++.h> 


void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int n = inputStack.size();
    stack<int>temp;
    int mid = (n-1)/2;
    for(int i=0;i<mid;i++){
        temp.push(inputStack.top());
        inputStack.pop();
    }
    inputStack.pop();

    while(!temp.empty()){
        inputStack.push(temp.top());
        temp.pop();
    }


   
}