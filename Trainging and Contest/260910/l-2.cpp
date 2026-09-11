#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

struct state {
    vector<pair<char, int>> edge;
    bool end = 0;
    bool rep = 0;
};
vector<state> node;

void insert(const string& s) {
    int u = 0;

    for (char c: s) {
        int v = -1;
        for (auto& [c1, v1]: node[u].edge) {
            if (c == c1) {
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
    }
    node[u].end = 1;
}

int find(const string& s) {
    int u = 0;

    for (char c: s) {
        int v = -1;
        for (auto& [c1, v1]: node[u].edge) {
            if (c == c1) {
                v = v1; break;
            }
        }
        if (v == -1) return 0;
        u = v;
    }

    if (!node[u].end) return 0;
    if (node[u].rep) return 2;
    node[u].rep = 1;
    return 1;
}

int main() {
    ios;
    node.emplace_back();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s);
    }
    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        switch(find(s)) {
            case 0: cout << "WRONG"; break;
            case 2: cout << "REPEAT"; break;
            case 1: cout << "OK"; break;
        }
        if (m) cout << "\n";
    }
    return 0;
}