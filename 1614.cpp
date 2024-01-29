#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long sick;
    long long count;
    long long number = 0;
    cin >> sick >> count;
    if (sick == 1) {
        number = 8 * count;
    }
    else if (sick == 5) {
        number = 4 + 8 * count;
    }
    else {
        if (count % 2 == 0) {
            number = 4 * count + sick - 1;
        }
        else {
            number = 4 + 4 * (count - 1) + 5 - sick;
        }
    }
    cout << number << "\n";
    
    return 0;
}