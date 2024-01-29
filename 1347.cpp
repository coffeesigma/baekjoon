#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int len;
    string s;
    vector<pair<int, int> > dir;
    vector<int> dir_count(4, 50);
    int now_dir = 0;
    pair<int, int> cur_pos = make_pair(50, 50);
    vector<vector<int> > map(101, vector<int>(101, 0));

    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(0, -1));
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(0, 1));

    cin >> len;
    cin >> s;
    map[cur_pos.first][cur_pos.second] = 1;
    for (char c : s) {
        if (c == 'R') now_dir = (now_dir + 1) % 4;
        else if (c == 'L') {
            if (now_dir == 0) now_dir = 3;
            else now_dir -= 1;
        }
        else {
            cur_pos.first += dir[now_dir].first;
            cur_pos.second += dir[now_dir].second;
            if (now_dir == 0) dir_count[now_dir] = max(dir_count[now_dir], cur_pos.first);
            else if (now_dir == 1) dir_count[now_dir] = min(dir_count[now_dir], cur_pos.second);
            else if (now_dir == 2) dir_count[now_dir] = min(dir_count[now_dir], cur_pos.first);
            else dir_count[now_dir] = max(dir_count[now_dir], cur_pos.second);
            map[cur_pos.first][cur_pos.second] = 1;
        }
    }
    for (int i = dir_count[2]; i <= dir_count[0]; i++) {
        for (int j = dir_count[1]; j <= dir_count[3]; j++) {
            if (map[i][j] == 0) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
    return 0;
}