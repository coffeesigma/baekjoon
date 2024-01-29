#include <iostream>
#include <algorithm>

using namespace std;

int abs(int n) {
    if (n < 0) return -n;
    else return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int num;
    int sum;
    int max = 0;
    vector<int> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    while(next_permutation(arr.begin(), arr.end())) {
        sum = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            sum += abs(arr[i] - arr[i + 1]);
        }
        if (sum > max) max = sum;
    }
    cout << max << "\n";

    return 0;
}