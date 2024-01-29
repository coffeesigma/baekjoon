#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string arr;
    stack<int> state;
    int is_ppap = 0;
    int i;

    cin >> arr;
    state.push(0);
    if (arr[0] == 'P') {
        for (i = 1; i < arr.size(); i++) {
            if (state.top() == 0) {
                if (arr[i] == 'A') break;
                else state.push(1);
            }
            else if (state.top() == 1) {
                if (arr[i] == 'P') state.push(1);
                else state.push(2);
            }
            else {
                if (arr[i] == 'A') break;
                else {
                    for (int j = 0; j < 3; j++) state.pop();
                    if (state.empty()) state.push(0);
                    else state.push(1); 
                }
            }
        }
    }
    if (!state.empty() && state.size() == 1 && state.top() == 0 && i == arr.size()) cout << "PPAP\n";
    else cout << "NP\n";

    return 0;
}