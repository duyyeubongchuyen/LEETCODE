#include <iostream>
#include <string>

using namespace std;

string lengthOfLongestSubstring(string s) {
    string result;
    string cur_string;
    int max_length = 1;
    for (int i = 0; i < s.length(); i++) {
        bool check = true;
        cur_string = cur_string + s[i];
        int max_j = 0;
        for (int j = 0; j < cur_string.length() - 1; j++) {
            if (s[i] == cur_string[j]) {
                check = false;
                if (j > max_j) max_j = j;
            }
        }
        if (check == false) cur_string.erase(0, max_j + 1);
        if (cur_string.length() > max_length) {
            max_length = cur_string.length();
            result = cur_string;
        }
    }
    return result;
}

int main() {
    cout<<lengthOfLongestSubstring("abcabcbb");
}