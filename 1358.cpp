#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width;
    int height;
    int x;
    int y;
    int n;
    int count = 0;
    pair<int, int> now;

    cin >> width >> height >> x >> y >> n;
    for (int i = 0; i < n; i++) {
        cin >> now.first >> now.second;
        if (now.first >= x && now.first <= x + width) {
            if (now.second >= y && now.second <= y + height)
                count++;
        }
        else if (now.first < x) {
            if (4 * (pow(now.first - x, 2) + pow(now.second - y - height/2, 2)) <= height * height)
                count++;
        }
        else if (now.first > x + width) {
            if (4 * (pow(now.first - x - width, 2) + pow(now.second - y - height/2, 2)) <= height * height)
                count++;
        }
    }
    cout << count << "\n";

    return 0;
}