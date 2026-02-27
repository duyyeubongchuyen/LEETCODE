#include <iostream>

using namespace std;

int main() {
	uint32_t n = 11;
	int bit = n & 1;
	int bit1 = (n >>= 1) & 1;
	bit1 = bit1 + bit;
	cout << bit1 << " " << n;
}