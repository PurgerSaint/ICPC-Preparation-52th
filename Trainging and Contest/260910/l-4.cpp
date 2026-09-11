#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

struct state {
    vector<pair<char, int>> edge;
    bool end = 0;
};
vector<state> node;

void insert(const string& s) {
    int u = 0;

    for (char c: s) {
        int v = -1;
        for (auto& [c1, v1]: node[u].edge) {
            if (c1 == c) {
                v = v1; break;
            }
        }
        if (v == -1) {
            v = static_cast<int>(node.size());
            node.emplace_back();
            node[u].edge.emplace_back(c, v);
        }
        u = v;
    }
    node[u].end = 1; 
}

string target = "";
int n;
vector<int> memo;
int dfs(int i) {
    if (i >= n) return n;
    if (memo[i] != -1) return memo[i];
    int u = 0, ans = i;
    for (int j = i; j < n; j++) {
        int v = -1;
        for (auto& [c, v1]: node[u].edge) {
            if (c == target[j]) {
                v = v1; break;
            }
        }
        if (v == -1) break;
        u = v;
        if (node[u].end) ans = max(ans, dfs(j + 1));
    }
    return memo[i] = ans;
}

int main() {
    ios;
    node.emplace_back();
    while (true) {
        string s; cin >> s;
        if (s == ".") break;
        insert(s);
    }

    string s;
    while (cin >> s) target += s; 
    n = target.size();
    memo = vector<int>(n, -1);
    cout << dfs(0);
    return 0;
}