#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define range(a) a.begin(), a.end()
#define ios ios::sync_with_stdio(false);cin.tie(0);

ll ans;
string s;
const int MAXN = 5e5 + 5;
int f[MAXN], cnt[MAXN], deep[MAXN];
int top = 1;
int trie[MAXN][26];

void insert() {
    int u = 0;
    for (char c: s) {
        int v = c - 'a';
        if (trie[u][v] == 0) {
            trie[u][v] = top;
            deep[top] = deep[u] + 1;
            top++;
        }
        u = trie[u][v];
        cnt[u]++;
        int val = f[cnt[u]];
        f[cnt[u]] = max(f[cnt[u]], deep[u]);
        if (val < deep[u]) {
            ans -= (cnt[u] ^ val);
            ans += (cnt[u] ^ deep[u]);
        }
    }
}

int main() {
    ios;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        insert();
        ans += i;
        cout << ans << (i < n ? "\n" : "");
    }
    return 0;
}