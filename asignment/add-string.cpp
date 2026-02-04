class Solution {
public:
    string addStrings(string num1, string num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        string res(max(num1.size(), num2.size()) + 1, '0');
        int k = res.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res[k--] = (sum % 10) + '0';
            carry = sum / 10;
        }
        return res.substr(k + 1);
  }
};