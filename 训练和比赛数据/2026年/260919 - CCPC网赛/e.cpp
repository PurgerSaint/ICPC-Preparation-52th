#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ios ios::sync_with_stdio(false);cin.tie(0);
#define range(a) a.begin(), a.end()

vector<int> num;
vector<int> mx_tree, mn_tree;

int mx(int& l, int& r) {
    return num[l] > num[r] ? l : r;
}

int mn(int& l, int& r) {
    return num[l] < num[r] ? l : r;
}

void push_up(int p) {
    mx_tree[p] = mx(mx_tree[p << 1], mx_tree[p << 1 | 1]);
    mn_tree[p] = mn(mn_tree[p << 1], mn_tree[p << 1 | 1]);
}

void build(int p, int l, int r) {
    if (l == r) {
        mn_tree[p] = mx_tree[p] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

void update(int p, int l, int r, int pos) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(p << 1, l, mid, pos);
    else update(p << 1 | 1, mid + 1, r, pos);
    push_up(p);
}

int query_mx(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mx_tree[p];
    int mid = (l + r) >> 1;
    int ans = -1;
    if (ql <= mid) ans = query_mx(p << 1, l, mid, ql, qr);
    if (mid < qr) {
        int rep = query_mx(p << 1 | 1, mid + 1, r, ql, qr);
        if (ans == -1 || num[rep] > num[ans]) ans = rep;
    }
    return ans;
}

int query_mn(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mn_tree[p];
    int mid = (l + r) >> 1;
    int ans = -1;
    if (ql <= mid) ans = query_mn(p << 1, l, mid, ql, qr);
    if (mid < qr) {
        int rep = query_mn(p << 1 | 1, mid + 1, r, ql, qr);
        if (ans == -1 || num[rep] < num[ans]) ans = rep;
    }
    return ans;
}

int main() {
    ios;
    int n, q; cin >> n >> q;
    num = vector<int>(n + 1);
    mx_tree = mn_tree = vector<int>(n * 4 + 1, 0);
    for (int i = 1; i <= n; i++) cin >> num[i];
    build(1, 1, n);
    while (q--) {
        int l, r; cin >> l >> r;
        int mx_loc = query_mx(1, 1, n, l, r), mn_loc = query_mn(1, 1, n, l, r);
        // cout << "===" << mx << " " << mn << "\n";
        swap(num[mx_loc], num[mn_loc]);
        update(1, 1, n, mn_loc);
        update(1, 1, n, mx_loc);
    }
    for (int i = 1; i <= n; i++)
        cout << num[i] << (i < n ? " " : "");
    return 0;
}