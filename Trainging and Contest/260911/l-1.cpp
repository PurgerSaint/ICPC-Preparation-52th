#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

bool solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> mp(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        mp[u].emplace_back(v, w);
        if (w >= 0) mp[v].emplace_back(u, w);
    }
    const ll INF = 1LL << 60;
    vector<ll> dis(n + 1, INF);
    vector<bool> vis(n + 1, 0);             // 是否在队列中
    vector<int> cnt(n + 1, 0);              // 某点更新次数
    queue<int> q;
    q.push(1);  vis[1] = 1; dis[1] = 0;     // 根据题目要求决定从哪些位置开始
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;                         // 不在队列中(将其出队)
        for (auto& [v, w]: mp[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;        // 记录更新次数
                if (cnt[v] >= n) return 1;  // 更新次数超过n，存在负环
                if (!vis[v]) {              // 选择未入队的点
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO");
        if (t) cout << "\n";
    }
    return 0;
}