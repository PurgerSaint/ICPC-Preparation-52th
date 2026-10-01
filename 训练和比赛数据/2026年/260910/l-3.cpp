#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

struct state {
    vector<pair<char, int>> edge;
    bool end = 0;
    int cnt = 0;
};
vector<state> node;

void insert(const string& s) {
    int u = 0;

    for (char c: s) {
        int v = -1;
        for (auto& [c1, v1]: node[u].edge) {
            if (c1 == c) {
                v = v1;
                break;
            }
        }
        if (v == -1) {
            v = static_cast<int>(node.size());
            node.emplace_back();
            node[u].edge.emplace_back(c, v);
        }
        u = v;
        node[u].cnt++;
    }
    node[u].end = 1;
}

int find(const string& s) {
    int u = 0;

    for (char c: s) {
        int v = -1;
        for (auto& [c1, v1]: node[u].edge) {
            if (c1 == c) {
                v = v1;
                break;
            }
        }
        if (v == -1) return 0;
        u = v;
    }

    return node[u].cnt;
}

void solve() {
    node.clear();
    node.emplace_back();
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s);
    }
    while (q--) {
        string s; cin >> s;
        cout << find(s) << (q ? "\n" : "");
    }
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        solve();
        if (t) cout << "\n";
    }
    return 0;
}