#include <iostream>
using namespace std;
int main() {
    double num1, num2;
    char c;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the operator('+','-','*','/','%'): ";
    cin >> c;
    cout << "Enter the second number: ";
    cin >> num2;
    switch (c) {
        case '+':
            cout << "Result = " << num1 + num2;
            break;

        case '-':
            cout << "Result = " << num1 - num2;
            break;

        case '*':
            cout << "Result = " << num1 * num2;
            break;

        case '/':
            if (num2 != 0)
                cout << "Result = " << num1 / num2;
            else
                cout << "Error!";
            break;
        case '%':
            if (num2 != 0)
                cout << "Result = " << num1 % num2;
            else
                cout << "Error!";
            break;

        default:
            cout << "Invalid operator!";
    }

    return 0;
}