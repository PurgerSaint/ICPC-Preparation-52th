#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

vector<vector<int>> ans;
void dfs(int w, vector<int>& path) {
    int sz = path.size();
    if (sz == 10) {
        if (w == 0) ans.push_back(path);
        return;
    }
    if (w < (10 - sz) || w > 3 * (10 - sz)) return;
    for (int i = 1; i <= 3; i++) {
        path.push_back(i);
        dfs(w - i, path);
        path.pop_back();
    }
}

int main() {
    ios;
    int n; cin >> n;
    vector<int> path;
    dfs(n, path);
    cout << ans.size() << "\n";
    for (auto it = ans.begin(); it != ans.end(); it++) {
        vector<int>& p = *it;
        for (auto i = p.begin(); i != p.end(); i++)
            cout << (*i) << (i + 1 != p.end() ? " " : "");
        if (it + 1 != ans.end()) cout << "\n";
    }
    return 0;
}