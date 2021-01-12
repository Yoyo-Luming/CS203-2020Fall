#pragma GCC optimize(3, "Ofast", "inline")
#include<iostream>
#include<vector> 
#include<cmath>
#include<queue>
#define MAXN 1000000
#define ll long long

using namespace std;

class KthLargest {
public:
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    ll size;

    KthLargest(ll k, vector<ll> nums) {
        size=k;
        for(ll i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    ll add(ll val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};


ll val(ll index){
	ll temp = index, sum=0;
	while(temp>0){
		sum += temp%10;
		temp /= 10;
	}	
	return index+sum;
}

inline void write(ll x)
{
    if(x>9) 
		write(x/10);
    putchar(x%10+'0');
}

inline int mymin(int x,int y){return x<y?x:y;}

int main(){
	ios::sync_with_stdio(false);
	ll n, k, s, temp=MAXN;
	cin >> n >> k >> s;
	vector<ll> datas;
	ll i=1;
    for(;i<=k;++i){
    	ll num = val(i+s);
    	datas.push_back(num);
    	temp = mymin(temp,num);
    	if(i%100 == 0){
    		s = temp;
    		write(s);
			putchar(' ');
		}
	}
	KthLargest *findk = new KthLargest(k, datas);
	for(;i<=n;++i){
		if(i%100 != 0){
			findk->add(val(i+s));
		}else{
			s = findk->add(val(i+s));
			write(s);
			putchar(' ');
		}
	}
}
// 1926 8 17 
// 2000 300 0
