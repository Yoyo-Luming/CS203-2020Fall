#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int MAXN = 1e6 + 7;
int a[MAXN], pos[MAXN];
int s[MAXN], t[MAXN];
int pre[MAXN], nxt[MAXN];
int n, k, len = 0;

void erase(int x) {
    int pp = pre[x], nn = nxt[x];
    if (pre[x])
        nxt[pre[x]] = nn;
    if (nxt[x] <= n)
        pre[nxt[x]] = pp;
    pre[x] = nxt[x] = 0;
}

inline int read() {
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int* maxInWindows(int result[], int num[], int size, int numsize, int left) {
    len = 0;
    if (size < 1 || numsize < size) {
        return result;
    }
    deque<int> qmax;
    for (int i = 0; i < numsize; ++i) {
        while (!qmax.empty() && num[qmax.back() + left] <= num[i + left]) {
            qmax.pop_back();
        }
        qmax.push_back(i);
        if (qmax.front() == i - size) {
            qmax.pop_front();
        }
        if (i >= size - 1) {
            result[len++] = num[qmax.front() + left];
        }
    }
    return result;
}

int main() {
    int T = read();
    while (T--) {
        n = read();
        k = read();

        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            pos[a[i]] = i;
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }
        LL ans = 0;
        for (int num = 1; num <= n - k + 1; ++num) {
            int numbers[200], left = 100, right = 100, p = pos[num], s0 = 0, t0 = 0, lar = 1;
            for (int d = p; d && s0 <= k; d = pre[d]) {
                s[++s0] = d;
                if (s0 > 0) {
                    numbers[--left] = a[d];
                }
            }
            for (int d = p; d != n + 1 && t0 <= k; d = nxt[d]) {
                t[++t0] = d;
                if (t0 > 1) {
                    numbers[right++] = a[d];
                }
            }
            s[++s0] = 0;
            t[++t0] = n + 1;

            if (t0 == k + 2) {
                right--;
            }
            if (s0 == k + 2) {
                left++;
            }
            int size = right - left;
            int temlar[size - k + 1];
            int* largest = maxInWindows(temlar, numbers, k, size, left);
            int index = len - 1;
            for (int i = 1; i <= s0 - 1; ++i) {
                if (k + 1 - i <= t0 - 1 && k + 1 - i >= 1) {
                    int temp = ((largest[index--] % mod * ((t[k + 1 - i + 1] - t[k + 1 - i]) % mod) % mod *
                                 (s[i] - s[i + 1] % mod)) %
                                mod * num % mod) %
                               mod;
                    ans += temp;
                }
            }
            erase(p);
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}
