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
                v = v1;
                break;
            }
        }
        if (v != -1) {
            u = v;
            continue;
        }
        v = static_cast<int>(node.size());
        node.emplace_back();
        node[u].edge.emplace_back(c, v);
        u = v;
    }
    node[u].end = 1;
}

string lcp() {
    int u = 0;
    string ans = "";

    while (!node[u].end && node[u].edge.size() == 1) {
        auto& [c, v] = node[u].edge[0];
        ans += c;
        u = v;
    }

    return ans;
}

int dfs(int u) {
    int cnt = 0;
    for (auto& [c, v]: node[u].edge)
        cnt = max(cnt, dfs(v));
    return cnt + node[u].end;
}

int main() {
    ios;
    node.emplace_back();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        insert(s);
    }
    cout << dfs(0);
    return 0;
}