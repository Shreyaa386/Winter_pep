class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<long long> st;
        for (string &s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = 0;
                if (s == "+") res = a + b;
                else if (s == "-") res = a - b;
                else if (s == "*") res = a * b;
                else if (s == "/") {
                    if ((a < 0) ^ (b < 0) && a % b != 0)
                        res = a / b - 1;
                    else
                        res = a / b;
                }
                else if (s == "^") {
                    res = pow(a, b);
                }
                st.push(res);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};