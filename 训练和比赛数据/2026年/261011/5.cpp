#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

vector<vector<int>> ans;
void dfs(int n, vector<int> path) {
    if (n < 0) return;
    if (n == 0) {
        ans.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!path.empty() && i != path.back()) {
            // cout << "in " <<  n << " " << i << "\n";
            path.push_back(i);
            dfs(n - i, path);
            path.pop_back();
        }
    }
}

int main() {
    ios;
    int n; cin >> n;
    vector<int> path;
    for (int i = 1; i <= n; i++) {
        path.push_back(i);
        dfs(n - i, path);
        path.pop_back();
    }
    for (vector<int>& p: ans) {
        for (auto it = p.begin(); it != p.end(); it++)
            cout << *it << (it + 1 != p.end() ? " " : "");
        cout << "\n";
    }
    return 0;
}