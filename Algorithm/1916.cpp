#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int s, d;
vector<pair<int, int>>vec[1001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int dist[1001];
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        vec[from].push_back({ to, cost });
    }
    for (int i = 0; i <= 1000; i++)
        dist[i] = 1e9;
    cin >> s >> d;
    dist[s] = 0;
    pq.push({ 0,s });

    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        int s = vec[here].size();
        for (int i = 0; i < s; i++) {
            int next = vec[here][i].first;
            int val = vec[here][i].second;

            if (dist[next] > cost + val) {
                dist[next] = cost + val;
                pq.push({ cost + val,next });
            }
        }
    }

    cout << dist[d] << "\n";
    return 0;
}