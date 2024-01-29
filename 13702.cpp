#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int k;
    vector<int> arr;
    long long start;
    long long end;
    long long now;
    int people_num;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        arr.push_back(v);
    }
    sort(arr.begin(), arr.end());
    start = 1;
    end = arr.back();
    while (start <= end) {
        people_num = 0;
        now = (start + end) / 2;
        for (int x : arr) {
            people_num += x / now;
        }
        if (people_num >= k) {
            start = now + 1;
        }
        else {
            end = now - 1;
        }
        //cout << start << " " << end << " " << now << "\n";
    }
    cout << end << "\n";

    return 0;
}