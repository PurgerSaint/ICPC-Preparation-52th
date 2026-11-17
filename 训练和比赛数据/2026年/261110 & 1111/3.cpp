#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct walk {
    int x, y;
    int bot, l, r, mid;
    ll w;
    bool operator<(const walk& other) const {
        return w > other.w;
    }
};

int main() {
    ios;
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

    pair<int, int> target;
    cin >> target.first >> target.second;
    target.second += n - target.first;

    vector<vector<vector<vector<ll>>>> dis(n + 1,
        vector<vector<vector<ll>>>(mx + 1,
            vector<vector<ll>>(5,
                vector<ll>(5, 1LL << 60)
            )
        )
    );
    priority_queue<walk> q;
    q.push({1, n, 4, 1, 3, 2, 0});
    dis[1][n][1][3] = 0;
    while (!q.empty()) {
        auto [x, y, bot, l, r, mid, w] = q.top(); q.pop();
        if (dis[x][y][l][r] != w) continue;
        if (x == target.first && y == target.second) break;

        auto move = [&](int nx, int ny, int nbot, int nl, int nr, int nmid, ll w) -> void {
            if (nx < 1 || nx > n || ny < 1 || ny > mx) return;
            if (nbot != mp[nx][ny] || w + 1 >= dis[nx][ny][nl][nr]) return;
            dis[nx][ny][nl][nr] = w + 1;
            q.push({nx, ny, nbot, nl, nr, nmid, dis[nx][ny][nl][nr]});
        };

        if ((x + y) % 2 == (1 + n) % 2)
            move(x + 1, y, mid, l, r, bot, w);
        else
            move(x - 1, y, mid, l, r, bot, w);
        move(x, y - 1, l, mid, bot, r, w);
        move(x, y + 1, r, bot, mid, l, w);
    }
    ll ans = 1LL << 60;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            ans = min(ans, dis[target.first][target.second][i][j]);
    cout << (ans == 1LL << 60 ? -1LL : ans);
    return 0;
}