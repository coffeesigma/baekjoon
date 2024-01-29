#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> hear;
    vector<string> see;
    int hearnum;
    int seenum;
    string input;

    cin >> hearnum;
    cin >> seenum;
    for (int i = 0; i < hearnum; i++) {
        cin >> input;
        hear.push_back(input);
    }
    for (int i = 0; i < seenum; i++) {
        cin >> input;
        if (find(hear.begin(), hear.end(), input) != hear.end())
            see.push_back(input);
    }
    sort(see.begin(), see.end());
    printf("%d\n", (int)see.size());
    for (int i = 0; i < see.size(); i++) {
        printf("%s\n", see.at(i).c_str());
    }
    return (0);
}