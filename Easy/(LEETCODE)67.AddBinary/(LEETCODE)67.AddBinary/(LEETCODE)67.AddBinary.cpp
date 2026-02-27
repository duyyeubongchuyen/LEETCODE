#include <iostream>
#include <string>

using namespace std;

void thembit(string& a, string& b) {
    int max_length = (a.length() >= b.length()) ? a.length() : b.length();
    while (a.length() < max_length) {
        a = "0" + a;
    }
    while (b.length() < max_length) {
        b = "0" + b;
    }
}

int main() {
    string a = "11";
    string b = "1";
    thembit(a, b);
    int max_length = (a.length() >= b.length()) ? a.length() : b.length();
    string sum;
    int k = 0;
    if (a[1] == '1') {
        cout << "ok";
    }
}