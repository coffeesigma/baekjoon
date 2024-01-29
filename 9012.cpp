#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<int> stack;
    int num;
    string par;
    int flag;

    cin >> num;
    for (int i = 0; i < num; i++) {
        flag = 0;
        cin >> par;
        for (int j = 0; j < par.size(); j++) {
            if (par.at(j) == '(')
                stack.push(1);
            else {
                if (stack.empty()) {
                    flag = 1;
                    break ;
                }
                stack.pop();
            }
        }
        if (stack.empty() && flag != 1)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            while (!stack.empty())
                stack.pop();
        }
    }
    return (0);
}