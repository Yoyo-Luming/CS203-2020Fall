#pragma GCC optimize(3, "Ofast", "inline")
#include <cstdio>
#include <algorithm>
#define li inline
#define gc getchar
#define pc putchar
#define R register
#define ri R int
#define rb R bool
#define rc R char
#define wr(n) write(n, false), pc('\n')
#define MAXN 300002

using namespace std;

struct data {
    int x, y;
    bool operator<(const data a) const { return x < a.x || (x == a.x && y > a.y); }
} happy[MAXN];

int mou[MAXN], lp[MAXN], rp[MAXN], lf[MAXN], mystack[MAXN], index[MAXN];

li int read() {
    ri x = 0, f = 0;
    rc ch = gc();
    while (ch < '0' || ch > '9') f |= ch == '-', ch = gc();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
    return x;
}

li void write(ri ans, rb bk) {
    if (ans == 0) {
        if (!bk)
            pc('0');
        return;
    }
    write(ans / 10, true);
    pc(ans % 10 ^ '0');
}

int main() {
    ri n, q, l, r, i, j = 1, ans = 0, top, cnt = 0, temp, exc;
    n = read();
    q = read();
    for (i = 1; i <= n; ++i) {
        mou[i] = read();
    }
    
    mou[0] = mou[n + 1] = 1 << 30;
    for (i = 1; i <= n; ++i) {
        while (mou[mystack[top]] <= mou[i]) {
            --top;
        }
        lp[i] = mystack[top];
        mystack[++top] = i;
    }

    top = 0;
    mystack[0] = n + 1;
    for (i = n; i >= 1; --i) {
        while (mou[mystack[top]] <= mou[i]) {
            --top;
        }
        rp[i] = mystack[top];
        mystack[++top] = i;
    }

    top = 0;
    mystack[0] = 0;
    for (i = 1; i <= n; ++i) {
        while (mou[mystack[top]] < mou[i]) {
            --top;
        }
        lf[i] = mystack[top];
        mystack[++top] = i;
    }

    for (i = 1; i <= n; ++i) {
        if (lp[i] && rp[i] <= n && lp[i] == lf[i]) {
            happy[++cnt].x = lp[i];
            happy[cnt].y = rp[i];
        }
    }

    sort(happy + 1, happy + cnt + 1);

    for (i = 1; i <= n; ++i) {
        index[i] += index[i - 1];
        while (happy[j].x == i && happy[j].y<=n) {
            ++index[i+1];
            ++j;
        }
    }

    for (int i = 1; i <= q; ++i) {
        l = read();
        r = read();
        ans = 0;
        for (j = index[l]; j <= index[r]; ++j) {
        	temp=j;
        	while(happy[temp].x==happy[temp-1].x &&temp>=0){
        		exc++;
        		temp--;
			}
            if (happy[j].y <= r&& happy[j].x >= l) {
                ans += index[happy[j].y-1]-index[happy[j].x]-exc;
                j = index[happy[j].y];
            }
            exc=0;
        }
        ans += r - l;
        wr(ans);
    }
    return 0;
}
/*
3 2
2 1 2
1 1
1 3

ans:
0
3

5 1
5 3 1 2 4
1 5

ans:
7

4 1
3 8 6 8
1 4

ans:
4

10 1
10 1 2 3 4 5 7 8 9 10
1 10

ans:
17
*/
