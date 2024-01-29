#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define INF 1000

vector<int> dijkstra(int start, int N, vector<vector<pair<int, int> > > graph) {
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int> > pq;

    dist[start] = 0;
    pq.push(make_pair(start, 0));
    while (!pq.empty()) {
        int cur_node = pq.top().first;
        int cur_dist = -pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int nxt_node = graph[cur_node][i].first;
            int nxt_dist = cur_dist + graph[cur_node][i].second;
            if (dist[nxt_node] > nxt_dist) {
                dist[nxt_node] = nxt_dist;
                pq.push(make_pair(nxt_node, -nxt_dist));
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int m;
    int start;
    int end;
    vector<int> dist;
    cin >> n >> m;
    vector<vector<pair<int, int> > > graph(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }
    cin >> start >> end;
    dist = dijkstra(start, n, graph);
    cout << dist[end] << "\n";

    return 0;
}