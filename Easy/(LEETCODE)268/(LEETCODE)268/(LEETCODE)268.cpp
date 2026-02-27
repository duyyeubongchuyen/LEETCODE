#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    vector<bool> table;
    int result;
    for (int i = 0; i <= nums.size(); i++) {
        table[i] = true;
    }
    for (int i = 0; i < nums.size(); i++) {
        int val = nums[i];
        table[val] = false;
    }
    for (int i = 0; i <= nums.size(); i++) {
        if (table[i] == true) {
            result = i;
        }
    }
    return result;
}

int main() {
    vector<int> nums = { 3,0,1 };
    cout << missingNumber(nums);
}