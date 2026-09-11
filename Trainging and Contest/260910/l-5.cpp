#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

struct state {
    vector<pair<char, int>> edge;
    bool end = 0;
    vector<int> loc;
};

int main() {
    ios;
    int n; cin >> n;
    vector<state> node;
    node.emplace_back();
    for (int i = 1; i <= n; i++) {
        int sz; cin >> sz;
        while (sz--) {
            string s; cin >> s;
            
            int u = 0;
            for (char c: s) {
                int v = -1;
                for (auto& [c1, v1]: node[u].edge) {
                    if (c == c1) {
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
            if (node[u].loc.empty() || node[u].loc.back() != i)
                node[u].loc.push_back(i);
        }
    }
    int q; cin >> q;
    while (q--) {
        string s; cin >> s;
        
        int u = 0;
        bool f = 0;
        for (char c: s) {
            int v = -1;
            for (auto& [c1, v1]: node[u].edge) {
                if (c == c1) {
                    v = v1; break;
                }
            }
            if (v == -1) {
                f = 1;
                break;
            }
            u = v;
        }
        if (f) {
            if (q) cout << "\n";
            continue;
        }
        vector<int>& loc = node[u].loc;
        for (auto it = loc.begin(); it != loc.end(); it++)
            cout << *it << (it + 1 != loc.end() ? " " : "");
        if (q) cout << "\n";
    }
    return 0;
}