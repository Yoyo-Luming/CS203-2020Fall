#include<iostream>
#include<cstdio>

using namespace std;

int a[100010],b[100010];
long long count;

void merge(int x,int y){
    if(x == y)  
		return;
    int mid=(x+y)/2,i=x,j=mid+1,k=x;
    merge(x,mid);
	merge(mid+1,y);
    while(i<=mid && j<=y){
    	if(a[i] <= a[j]){
    		b[k++] = a[i++];
    	}
    	else{
    		b[k++] = a[j++];
			count+=mid-i+1;
    	}
    }
    while(j <= y){
    	b[k++] = a[j++];
    }
    while(i <= mid){
    	b[k++] = a[i++];
    }
    for(int l=x;l<=y;l++){
    	a[l] = b[l];
    }
} 

int main() {
    int tc;
	cin >> tc;
	for(int j=0;j<tc;j++){
		count = 0;
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
		     cin >> a[i];
		}
		merge(1,n);
		cout << count <<endl;
	}
	return 0;
}
