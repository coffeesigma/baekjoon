#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    unsigned long long num;

    while (cin >> n) {
        int ret = 1;
        num = 1;
        while(1) {
            if (num % n == 0) break;
            num = num * 10 + 1;
            num = num % n;
            ret++;
        }
        cout << ret << "\n";
    }

    return 0;
}