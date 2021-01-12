#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define MAXN 500005

using namespace std;
 
vector<pair<ll, ll> >mp[MAXN];
 
struct node {
    ll w, u, id;
    node(){}
    node(ll uu, ll idd, ll ww) : u(uu), id(idd), w(ww){}
    bool operator < (const node &a)const {
        return w > a.w;
    }
};
 
ll ans[MAXN], qq[MAXN];
 
inline ll read() {
    char ch = getchar();
    ll x = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
 
inline ll mymax(ll x,ll y){return x>y?x:y;}
 
void init(int n){
    for(ll i = 0; i <= n+1; ++i){
        mp[i].clear();
	} 	
} 

int main() {
    ll T, n, m, a, b, c, Q;
    T = read();
    while(T--) {
    	n = read();
    	m = read();
    	Q = read();
    	init(n);
        for(ll i = 1; i <= m; ++i) {
            a = read();
			b = read();
			c = read(); 
            mp[a].push_back(make_pair(c, b));
        }
        for(ll i = 1; i <= n; ++i) {
            sort(mp[i].begin(), mp[i].end());
        }
        ll maxx = 0;
        for(ll i = 0; i < Q; ++i) {
        	qq[i] = read();
            maxx = mymax(maxx, qq[i]);
        }
        priority_queue<node>q;
        for(ll i = 1; i <= n; ++i) {
            if(mp[i].size()){
            	q.push(node(i, 0, mp[i][0].first));
			}
        }
        ll cnt = 0;
        while(!q.empty()) {
            node tmp = q.top();
            q.pop();
            ll u = tmp.u, id = tmp.id, w = tmp.w;
            ans[++cnt] = w;
            if(cnt == maxx){
            	break;
			} 
            if(id < (ll)mp[u].size() - 1) {
                q.push(node(u, id + 1, w - mp[u][id].first + mp[u][id + 1].first));
            }
            ll v = mp[u][id].second;
            if(mp[v].size()){
            	q.push(node(v, 0, w + mp[v][0].first));	
			}
        }
        for(ll i = 0; i < Q; ++i){
        	printf("%lld\n", ans[qq[i]]);
		} 
    }
    return 0;
}
/*
1
2 2 2
1 2 1
2 1 2
3
4
*/
