#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define mod(t, m) ((t) % (m) + (m)) % (m)
#define range(a) a.begin(), a.end()

struct state {
    int x, i;
    int a; ll b;
    int loc;
};

int main() {
    ios;
    int n, q; ll k; cin >> n >> k >> q;
    vector<pair<int, int>> mission(n + 1);
    for (int i = 1; i <= n; i++) {
        auto& [a, b] = mission[i];
        cin >> a >> b;
    }
    vector<state> query(q);
    for (int j = 0; j < q; j++) {
        auto& [x, i, a, b, loc] = query[j];
        cin >> x >> i;
        loc = j;
    }
    sort(range(query), [](state& x, state& y){
        if (x.x == y.x) return x.loc < y.loc;
        return x.x < y.x;
    });
    int now = 1; ll hour = 0;
    for (auto& [x, i, a, b, loc]: query) {
        if (x < now) now = x, hour = 0;
        auto& [array_time, work_time] = mission[i];
        if (array_time > hour) hour = array_time;
        hour += work_time;
        if (hour > k) {
            now += hour / k;
            hour = hour % k;
        }
        a = now, b = hour;
        cout << "finish:" << loc << " day:" << a << " time:" << b << "\n";
        if (hour == k) {
            now++, hour = 0;
        }
    }
    sort(range(query), [](state& x, state& y){ return x.loc < y.loc; });
    for (auto it = query.begin(); it != query.end(); it++) {
        auto& [x, i, a, b, loc] = *it;
        cout << a << " " << b << (it + 1 != query.end() ? "\n" : "");
    }
    return 0;
}