#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

struct state {
    int u, v; ll w;
    state(int x, int y, ll a): u(x), v(y), w(a) {}
};

struct UnionFold {
    private:
        vector<int> parent, size;
        int count;
    public:
        UnionFold(int n): count(n), parent(n + 1, 0), size(n + 1, 1) {
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        bool merge(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ) return 0;
            if (size[rootP] > size[rootQ]) {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            } else {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            count--;
            return 1;
        }
        int cnt() { return count; }
};

ll solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] % k;
    }
    sort(range(a));
    vector<state> p;
    const ll INF = 1LL << 60;
    ll ans = 0, cnt = 0;
    UnionFold b(n);
    for (int i = 0; i < n; i++) {
        int l = lower_bound(range(a), k - a[i]) - a.begin();
        int r = upper_bound(range(a), k - a[i]) - a.begin();
        for (int j = l; j < r; j++) {
            if (i == j) continue;
            if (b.merge(i, j)) cnt++;
        }
    }
    if (cnt == n - 1) return 0;

    multiset<pair<ll, int>> st;
    for (int i = 0; i < n; i++)
        st.insert({a[i], i});

    int comp_cnt = b.cnt();     // 当前连通分量数量
    while (comp_cnt > 1) {
        vector<vector<int>> group(n);

        // 找到每个连通分量所有的节点
        for (int i = 0; i < n; i++)
            group[b.find(i)].push_back(i);

        vector<state> best(n, {-1, -1, (ll)4e18});

        for (int root = 0; root < n; root++) {
            if (group[root].empty()) continue;

            // 删除当前连通分量自带的边
            for (int& u: group[root])
                st.erase(st.find({a[u], u}));

            for (int& u: group[root]) {
                if (st.empty()) continue;

                ll need = k - a[u];
                auto it = st.lower_bound({need, -1});
                if (it == st.end()) it = st.begin();

                const int& v = it->second;
                ll w = (a[u] + a[v]) % k;
                if (w < best[root].w)
                    best[root] = {u, v, w};
            }
            for (int& u: group[root]) {
                st.insert({a[u], u});
            }
        }
        for (int root = 0; root < n; root++) {
            if (best[root].u == -1) continue;
            auto& [u, v, w] = best[root];
            if (b.merge(u, v)) {
                ans += w;
                comp_cnt--;
            }
        }
    }
    return ans;
}

int main() {
    ios;
    int t; cin >> t;
    while (t--) {
        cout << solve();
        if (t) cout << "\n";
    }
    return 0;
}