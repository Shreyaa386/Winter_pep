#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={100,2,19,13,16,18};
    stack<int>st;
    for(int i=0;i<6;i++){
        if(arr[i]%2==0)
        st.push(arr[i]);
    
    }

    cout<<"stcak pop order";
    while(!st.empty()){
        cout<<st.top()<<"";

        st.pop();
    }
    int size=st.size();
    int mid=size/2;
    for(int i=0;i<mid;i++)
    st.pop();
cout<<"Middle element in stack:"<<st.top();
return 0;
}