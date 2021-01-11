#include<iostream>
#include<stdlib.h>
#include <cstdio>
#define ll long long

using namespace std;

struct line{
	ll point1,point2;
}a[500005];

ll n,x1,x2;

ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}

void Merge( ll left, ll mid, ll right) {
	line temp[right - left + 1];	
	ll firstSectionIndex = left;			
	ll secondSectionIndex = mid + 1;
	ll tempIndex = 0;	

	while (firstSectionIndex <= mid && secondSectionIndex <= right) {	
		if (a[firstSectionIndex].point1 <= a[secondSectionIndex].point1)
			temp[tempIndex++] = a[firstSectionIndex++];
		else
			temp[tempIndex++] = a[secondSectionIndex++];
	}

	while (firstSectionIndex <= mid)
		temp[tempIndex++] = a[firstSectionIndex++];

	while (secondSectionIndex <= right)
		temp[tempIndex++] = a[secondSectionIndex++];

	for (int j = 0; j < tempIndex; ++j)		
		a[left + j] = temp[j];

}

void MergeSort( ll left, ll right) {
	if (left >= right)
		return;
	
	ll mid = (left + right) / 2;

	MergeSort( left, mid);		
	MergeSort(mid + 1, right);	

	Merge(left, mid, right);	
}

int main(){
	n = read_ll();
	x1 = read_ll();
	x2 = read_ll();
	for(int i=0;i<n;i++){
		ll k,b;
		k = read_ll();
		b = read_ll();
		a[i].point1 = k*x1+b;
		a[i].point2 = k*x2+b;
	}
	MergeSort(0,n-1);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n-1;j++){
			if(a[i].point1 == a[j].point1){
				if(a[i].point2 > a[j].point2){
					line temp = a[j];
					a[j] = a[i];
					a[i] = temp;
				}
			}else{
				break;
			}
		}
	}
	int jud = 0;
	for(ll i=1;i<n;i++){
		if(a[i].point2 < a[i-1].point2 ){
			jud++;
			break;
		}
	}
	if(jud == 1){
		cout << "YES";
	}else{
		cout << "NO";
	}
}

