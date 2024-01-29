#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int min_score = 2147483647;

    cin >> n;
    vector<int> temp(n, 0);

    for (int i = n / 2; i < n; i++) {
        temp[i] = 1;
    }
    vector<vector<int> > arr(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            arr[min(i, j)][max(i, j)] += x;
        }
    }
    do {
        vector<int> team1;
        vector<int> team2;
        vector<int> team_temp(n / 2, 1);
        int team1_now_score = 0;
        int team2_now_score = 0;
        team_temp[0] = 0;
        team_temp[1] = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] == 0) team1.push_back(i + 1);
            else team2.push_back(i + 1);
        }
        do {
            vector<int> team1_add_score;
            vector<int> team2_add_score;
            for (int i = 0; i < n / 2; i++) {
                if (team_temp[i] == 0) {
                    team1_add_score.push_back(team1[i]);
                    team2_add_score.push_back(team2[i]);
                }
            }
            team1_now_score += arr[team1_add_score[0]][team1_add_score[1]];
            team2_now_score += arr[team2_add_score[0]][team2_add_score[1]];
        } while (next_permutation(team_temp.begin(), team_temp.end()));
        //cout << team1_now_score << " " << team2_now_score << "\n";
        min_score = min(min_score, abs(team1_now_score - team2_now_score));
    } while (next_permutation(temp.begin(), temp.end()));
    cout << min_score << "\n";

    return 0;
}