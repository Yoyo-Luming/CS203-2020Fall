#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 300010

using namespace std;

struct data {
    int x, y;
    bool operator<(const data a) const { return x < a.x; }
} a[MAXN];

int mou[MAXN], lp[MAXN], rp[MAXN], lf[MAXN], mystack[MAXN], top, cnt, root[MAXN], ls[MAXN * 20],
    rs[MAXN * 20], si[MAXN * 20], tot;

void insert(int val, int l, int r, int x, int &y) {
    y = ++tot, si[y] = si[x] + 1;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    if (val <= mid) {
        rs[y] = rs[x];
        insert(val, l, mid, ls[x], ls[y]);
    } else {
        ls[y] = ls[x];
        insert(val, mid + 1, r, rs[x], rs[y]);
    }
}

int query(int index1, int index2, int l, int r, int x, int y) {
    if (index1 <= l && r <= index2) {
        return si[y] - si[x];
    }
    int mid = (l + r) / 2, result = 0;
    if (index2 > mid) {
        result = result + query(index1, index2, mid + 1, r, rs[x], rs[y]);
    }
    if (index1 <= mid) {
        result = result + query(index1, index2, l, mid, ls[x], ls[y]);
    }
    return result;
}

inline const int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void write(int x)
{
    if(x>9) 
		write(x/10);
    putchar(x%10+'0');
}

int main() {
    register int n, q, l, r, ans = 0;
    n = read();
    q = read();
    for (int i = 1; i <= n; i++) {
        mou[i] = read();
    }
    mou[0] = mou[n + 1] = 1 << 30;
    for (int i = 1; i <= n; i++) {
        while (mou[mystack[top]] <= mou[i]) {
            top--;
        }
        lp[i] = mystack[top];
        mystack[++top] = i;
    }

    top = 0;
    mystack[0] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (mou[mystack[top]] <= mou[i]) {
            top--;
        }
        rp[i] = mystack[top];
        mystack[++top] = i;
    }

    top = 0;
    mystack[0] = 0;
    for (int i = 1; i <= n; i++) {
        while (mou[mystack[top]] < mou[i]) {
            top--;
        }
        lf[i] = mystack[top];
        mystack[++top] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (lp[i] && rp[i] <= n && lp[i] == lf[i]) {
            a[++cnt].x = lp[i];
            a[cnt].y = rp[i];
        }
    }

    sort(a + 1, a + cnt + 1);
    int j = 1;
    for (int i = 1; i <= n; i++) {
        root[i] = root[i - 1];
        while (j <= cnt && a[j].x == i) {
            insert(a[j].y, 1, n, root[i], root[i]);
            j++;
        }
    }
    
    for (int i = 1; i <= q; i++) {
        l = read();
        r = read();
        ans = query(l, r, 1, n, root[l - 1], root[r]) + r - l;
        write(ans);
        putchar('\n');
    }
    return 0;
}
/*
3 2
2 1 2
1 1
1 3
*/
