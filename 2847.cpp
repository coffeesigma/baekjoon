#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int score;
    int diff;
    int count = 0;
    vector<int> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> score;
        arr.push_back(score);
    }
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] >= arr[i + 1]) {
            diff = arr[i] - arr[i + 1];
            arr[i] -= diff + 1;
            count += diff + 1;
        }
    }
    cout << count << "\n";

    return 0;
}