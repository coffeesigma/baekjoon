#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pipe;
    int n;
    int tape;
    int ret = 0;

    cin >> n >> tape;
    for (int i = 0; i < n; i++) {
        int hole;
        cin >> hole;
        pipe.push_back(hole);
    }
    int now_tape = -1001;
    sort(pipe.begin(), pipe.end());
    for (int x : pipe) {
        if (x >= now_tape + tape) {
            now_tape = x;
            ret++;
        }
    }
    cout << ret << "\n";

    return 0;
}
