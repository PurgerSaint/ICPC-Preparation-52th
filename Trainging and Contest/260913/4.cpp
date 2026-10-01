#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

vector<string> mp;
int n, m; 
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int gx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, gy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int dfs1(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (mp[i][j] != '1') return 0;
    int ans = 1;
    mp[i][j] = '*';
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (mp[x][y] != '1') continue;
        ans += dfs1(x, y);
    }
    return ans;
}

int dfs2(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (mp[i][j] != '*') return 0;
    int ans = 1;
    mp[i][j] = '1';
    for (int k = 0; k < 8; k++) {
        int x = i + gx[k], y = j + gy[k];
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (mp[x][y] != '*') continue;
        ans += dfs2(x, y);
    }
    return ans;
}

int main() {
    ios;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp.push_back(s);
    }
    int cnt4 = 0, cnt8 = 0;
    int mx4 = 0, mx8 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '1') {
                cnt4++;
                mx4 = max(mx4, dfs1(i, j));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '*') {
                cnt8++;
                mx8 = max(mx8, dfs2(i, j));
            }
        }
    }
    cout << (cnt4 - cnt8) << " " << mx4 << " " << mx8;
    return 0;
}