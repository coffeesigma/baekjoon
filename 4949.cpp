#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> stack;
    string par;
    int flag;

    while (1) {
        flag = 0;
        getline(cin, par);
        if (par == ".") break;
        if (par.at(par.size() - 1) != '.') {
            cout << "no" << endl;
            continue ;
        }
        for (int j = 0; j < par.size(); j++) {
            if (par.at(j) == '(')
                stack.push('(');
            else if (par.at(j) == ')') {
                if (stack.empty() || stack.top() != '(') {
                    flag = 1;
                    break ;
                }
                stack.pop();
            }
            else if (par.at(j) == '[')
                stack.push('[');
            else if (par.at(j) == ']') {
                if (stack.empty() || stack.top() != '[') {
                    flag = 1;
                    break ;
                }
                stack.pop();
            }
        }
        if (stack.empty() && flag != 1)
            cout << "yes" << endl;
        else {
            cout << "no" << endl;
            while (!stack.empty())
                stack.pop();
        }
    }
    return (0);
}