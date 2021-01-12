//#pragma GCC optimize(3, "Ofast", "inline")
#include<iostream>
#include<vector> 
#include<cmath>
#include<queue>
#define MAXN 8589934592
#define ll long long

using namespace std;

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

inline int mymin(int x,int y){return x<y?x:y;}

int main(){
	int n = read(), type;
	ll sum=0;
	vector <ll> adopters, pets;
	for(int i=0;i<n;++i){
		ll temp = MAXN;
		int index = -1;
		type = read();
		if(type==0){
			if(pets.size()>0){
				ll a = read();
				for(int j=0;j<pets.size();++j){
					ll dif = abs(a-pets[j]);
					if(dif<temp){
						index = j;
						temp = dif;
					}else if(dif == temp && index!=-1){
						if(pets[index]>pets[j]){
							index=j;
						}
					} 
				}
				pets.erase(pets.begin()+index);
				sum+=temp;
			}else{
				adopters.push_back(read());
			}
		}else{
			if(adopters.size()>0){
				ll a = read();
				for(int j=0;j<adopters.size();++j){
					ll dif = abs(a-adopters[j]);
					if(dif<temp){
						index = j;
						temp = dif;
					}else if(dif == temp && index!=-1){
						if(adopters[index]>adopters[j]){
							index=j;
						}
					} 
				}
				adopters.erase(adopters.begin()+index);
				sum+=temp;				
			}else{
				pets.push_back(read());
			}
		}
	}
	cout << sum;
}
