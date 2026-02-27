#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool isValid(string s) {
    stack<char> nganxep;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            nganxep.push(s[i]);
            continue;
        }
        if (s[i] == ')') {
            if (nganxep.top() == '(') {
                nganxep.pop();
            }
            else {
                return false;
            }
        }
        if (s[i] == ']') {
            if (nganxep.top() != '[') {
                return false;
            }
            else {
                nganxep.pop();
            }
        }
        if (s[i] == '}') {
            if (nganxep.top() == '{') {
                nganxep.pop();
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string s = "{[])";
    cout << isValid(s);
}