#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    int x, y;
    int t;
    bool f = 0;
};

struct walk {
    int x, y;
    int dig;
    bool f;
    int w;
    bool operator<(const walk& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
    vector<vector<state>> d(5);
    d[1] = {{0, -1, 2, 1}, {0, 1, 3, 1}, {1, 0, 0, 0}, {-1, 0, 4, 1}};
    d[2] = {{0, -1, 3, 1}, {0, 1, 1, 1}, {1, 0, 0, 0}, {-1, 0, 4, 1}};
    d[3] = {{0, -1, 1, 1}, {0, 1, 2, 1}, {1, 0, 0, 0}, {-1, 0, 4, 1}};
    d[4] = {{0, -1, 1, 1}, {0, 1, 3, 1}, {1, 0, 0, 0}, {-1, 0, 2, 1}};
    vector<vector<state>> p(5);
    p[1] = {{0, -1, 3, 1}, {0, 1, 2, 1}, {1, 0, 4, 1}, {-1, 0, 0, 0}};
    p[2] = {{0, -1, 1, 1}, {0, 1, 3, 1}, {1, 0, 4, 1}, {-1, 0, 0, 0}};
    p[3] = {{0, -1, 2, 1}, {0, 1, 1, 1}, {1, 0, 4, 1}, {-1, 0, 0, 0}};
    p[4] = {{0, -1, 3, 1}, {0, 1, 1, 1}, {1, 0, 2, 1}, {-1, 0, 0, 0}};
    int n; cin >> n;
    int mx = 2 * n - 1;
    vector<vector<int>> mp(n + 1, vector<int>(mx + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = n - i + 1; j < n; j++)
            cin >> mp[i][j];
        cin >> mp[i][n];
        for (int j = n + 1; j < n + i; j++)
            cin >> mp[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= mx; j++)
            cout << mp[i][j] << (j < mx ? " " : "\n");
    }

    pair<int, int> target;
    cin >> target.first >> target.second;
    target.second += n - target.first;

    vector<vector<ll>> dis(n + 1, vector<ll>(mx + 1, 1LL << 60));
    priority_queue<walk> q;
    q.push({1, n, mp[1][n], 1, 0});
    dis[1][n] = 0;
    while (!q.empty()) {
        auto [x, y, dig, f, w] = q.top(); q.pop();
        if (dis[1][n] != w) continue;
        if (x == target.first && y == target.second) break;
        vector<vector<state>>& a = f ? d : p;
        for (auto& [dx, dy, t, c]: a[dig]) {
            if (!c) continue;
            int nx = x + dx, ny = y + dy;
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (mp[nx][ny] != t || dis[nx][ny] <= w + 1) continue;
            dis[nx][ny] = w + 1;
            q.push({nx, ny, t, !f, w + 1});
        }
    }
    ll& ans = dis[target.first][target.second];
    cout << (ans == 1LL << 60 ? -1 : ans);
    return 0;
}