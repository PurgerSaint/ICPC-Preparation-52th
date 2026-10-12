#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct UnionFold {
    private:
        int count;
        vector<int> size, parent;
    public:
        UnionFold(int n): count(n), size(n + 1, 1), parent(n + 1, 0) {
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool merge(int p, int q) {
            int rootP = find(p), rootQ = find(q);
            if (rootP == rootQ) return 0;
            if (size[rootP] > size[rootQ]) {
                size[rootP] += size[rootQ];
                parent[rootQ] = rootP;
            } else {
                size[rootQ] += size[rootP];
                parent[rootP] = rootQ;
            }
            count--;
            return 1;
        }
};

struct state {
    int u, v;
    ll w;
};

int main() {
    ios;
    int n; cin >> n;
    vector<ll> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<state> e;
    
    for (int i = 1; i < n; i++)
        e.push_back({i, i + 1, gcd(p[i], p[i + 1])});

    vector<pair<int, ll>> curL;
    for (int i = 1; i <= n; i++) {
        vector<pair<int, ll>> nxtL;
        nxtL.push_back({i, p[i]});

        for (auto& [j, w]: curL) {
            ll g = gcd(w, p[i]);
            if (g != nxtL.back().second)
                nxtL.push_back({j, g});
        }
        for (auto& [u, w]: nxtL) {
            if (u < i)
                e.push_back({i, u, w});
        }
        curL = nxtL;
    }

    vector<pair<int, ll>> curR;
    for (int i = n; i >= 1; i--) {
        vector<pair<int, ll>> nxtR;
        nxtR.push_back({i, p[i]});

        for (auto& [j, w]: curR) {
            ll g = gcd(w, p[i]);
            if (g != nxtR.back().second)
                nxtR.push_back({j, g});
        }
        for (auto& [u, w]: nxtR) {
            if (u > i)
                e.push_back({i, u, w});
        }
        curR = nxtR;
    }

    sort(range(e), [](state& a, state& b){
        return a.w < b.w;
    });
    UnionFold b(n);
    ll ans = 0, cnt = 0, t = -1;
    for (auto& [u, v, w]: e) {
        if (b.merge(u, v)) {
            ans += w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    cout << ans;
    return 0;
}