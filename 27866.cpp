#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int point;

    cin >> str;
    cin >> point;
    cout << str.at(point - 1) << endl;
    return (0);
}
