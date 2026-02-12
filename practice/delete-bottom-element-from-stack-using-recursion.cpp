#include <iostream>
#include <stack>
using namespace std;

void deleteBottom(stack<int>& st) {
    
    if (st.empty())
        return;
    int topElement = st.top();
    st.pop();
    if (st.empty()) {
        return;  
    }

    deleteBottom(st);

    st.push(topElement);
}

int main() {
    
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Original Stack: ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    
    cout << endl;

    
    deleteBottom(st);

    cout << "After Deleting Bottom Element: ";

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}