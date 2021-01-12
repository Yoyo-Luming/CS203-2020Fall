#pragma GCC optimize(3, "Ofast", "inline")
#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
#include<queue>
#define MAXN 1000005
#define ll long long

using namespace std;

struct data {
    ll power, time;
    bool operator<(const data a) const { return time > a.time || (time == a.time && power < a.power); }
} player[MAXN];

inline ll read() {
    char ch = getchar();
    ll x = 0, f = 1;
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

int main(){
	int T = read();
	while(T--){
		ll n=read(), cur=0, sum=0;
		for(int i=0;i<n;++i){
			player[i].power=read();
		}
		for(int i=0;i<n;++i){
			player[i].time=read();
		}
		sort(player,player+n);
		priority_queue< int ,vector< int >,less< int > >q;
		ll i = player[0].time; 
		for(;i>0;){
			while(player[cur].time==i){
				q.push(player[cur].power);
				++cur;
			}
			if(q.size()>0){
				sum +=q.top();
				q.pop();
			}
			i--;
		}
		printf("%lld\n",sum);
	}
}
/*
3
3
2 1 3
1 1 2
4
50 10 20 30
2 1 2 1
7
20 2 10 100 8 5 50
1 1 3 2 2 20 10

1
7
20 2 10 100 8 5 50
1 1 3 2 2 20 10

1
4
1000 22 1 7
1 1 1 1

1
4
1 2 3 4
1 2 3 4

1 
4
4 3 2 1
1 2 3 4 
*/

