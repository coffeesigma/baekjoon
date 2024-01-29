#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long stone;
    int arr[7] = {0, 1, 0, 1, 1, 1, 1};

    cin >> stone;
    if (arr[stone % 7] == 0) cout << "CY\n";
    else cout << "SK\n";

    return 0;
}