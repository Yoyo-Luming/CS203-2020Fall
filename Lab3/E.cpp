#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

struct Orcs{
	ll hp,at;
}a[200005];


ll n,p,q,j,k;
ll ans=0,sum =0;

ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}


void Merge(ll left, ll mid, ll right) {
	Orcs temp[right - left + 1];	
	ll firstSectionIndex = left;			
	ll secondSectionIndex = mid + 1;
	ll tempIndex = 0;	
	ll jud = 0;
	while (firstSectionIndex <= mid && secondSectionIndex <= right) {	
		if ((a[firstSectionIndex].hp-a[firstSectionIndex].at) >= 
		(a[secondSectionIndex].hp-a[secondSectionIndex].at))
			temp[tempIndex++] = a[firstSectionIndex++];
		else
			temp[tempIndex++] = a[secondSectionIndex++];
	}

	while (firstSectionIndex <= mid)
		temp[tempIndex++] = a[firstSectionIndex++];

	while (secondSectionIndex <= right)
		temp[tempIndex++] = a[secondSectionIndex++];

	for (int j = 0; j < tempIndex; ++j){
		a[left + j] = temp[j];
	}

}


void MergeSort(ll left, ll right) {
	if (left >= right)
		return;
	
	ll mid = (left + right) / 2;

	MergeSort(left, mid);		
	MergeSort(mid + 1, right);	

	Merge(left, mid, right);	
}


int main(){
	n = read_ll();
	p = read_ll();
	q = read_ll();
	for(ll i=1;i<=n;i++){
		a[i].hp = read_ll();
		a[i].at = read_ll();
	}
	MergeSort(1,n);
	ll temp = 1;
	while(p){
		temp = temp*2;
		p--;
	}
	for(int i=1;i<=q;i++){
		sum = sum + max(a[i].hp,a[i].at);
	}
	for(int i=q+1;i<=n;i++){
		sum = sum + a[i].at;
	}
	ans = sum;
	for(int i=1;i<=q;i++){
		ans = max(ans,sum-max(a[i].at,a[i].hp)+max(a[i].hp*temp,a[i].at));
	}
	if(q != 0){
		for(int i = q+1;i<=n;i++){
			ans = max(ans,sum-a[i].at+max(a[i].hp*temp,a[i].at)-max(a[q].hp,a[q].at)+a[q].at);
		}
	}
	cout << ans;
	return 0;
}
