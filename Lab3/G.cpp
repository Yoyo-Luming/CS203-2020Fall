#include<iostream>
#include <cstdio>
#define ll long long

using namespace std;

ll n,m,k,a[500000],ans,b[500000],sum;

ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}

void Merge(ll* numbers, ll left, ll mid, ll right) {
	ll* temp = new ll[right - left + 1];	
	ll fistSectionIndex = left;			
	ll secondSectionIndex = mid + 1;
	ll tempIndex = 0;	

	while (fistSectionIndex <= mid && secondSectionIndex <= right) {	
		if (numbers[fistSectionIndex] <= numbers[secondSectionIndex])
			temp[tempIndex++] = numbers[fistSectionIndex++];
		else
			temp[tempIndex++] = numbers[secondSectionIndex++];
	}

	while (fistSectionIndex <= mid)
		temp[tempIndex++] = numbers[fistSectionIndex++];

	while (secondSectionIndex <= right)
		temp[tempIndex++] = numbers[secondSectionIndex++];

	for (int j = 0; j < tempIndex; ++j)		
		numbers[left + j] = temp[j];

	delete[] temp;
}


void MergeSort(ll* numbers, ll left, ll right) {
	if (numbers == NULL ||  left >= right)
		return;
	
	ll mid = (left + right) / 2;

	MergeSort(numbers, left, mid);		
	MergeSort(numbers, mid + 1, right);	

	Merge(numbers, left, mid, right);	
}

int main(){
	n = read_ll();
	m = read_ll();
	for(int i=1;i<=n;i++){
		a[i] = read_ll();
		b[i] = b[i-1] + a[i];
	}
	
	MergeSort(b,1,n-1);
	for(int i=1;i<m;i++)
		sum = sum +b[i];
		
	printf("%lld",b[n]*m - sum);
}

