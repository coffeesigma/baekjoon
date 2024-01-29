#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<string> input;
    vector<string> output;
    int overtake_count = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        input.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        output.push_back(s);
    }
    vector<string>::iterator iter;
    for (int i = n - 1; i >= 0; i--) {
        iter = find(output.begin(), output.end(), input[i]);
        if (iter != output.end()) {
            if (iter - output.begin() < i) {
                output.erase(iter);
                overtake_count++;
            }
        }
    }
    cout << overtake_count << "\n";

    return 0;
}