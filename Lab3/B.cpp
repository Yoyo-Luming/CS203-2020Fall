#include<iostream>
#include <cstdio>

using namespace std;

int nums[5000005],k;

inline int read(){	 
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    } return x*f;
}

void qsort(int left, int right)
{
	int i=left,j=right,mid=nums[(left+right)/2];
	do
	{
		while(nums[j]>mid)
			j--;
		while(nums[i]<mid)
			i++;
		if(i<=j)
		{
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}
	}
	while(i<=j);
	if(k<=j) qsort(left,j);
	else if(i<=k) qsort(i,right);
	else 
	{
		printf("%d",nums[j]);
		return;
	}
}

int main()
{
	int n;
	n = read();
	k = read();
	for(int i=0;i<n;i++)
		nums[i] = read();
	qsort(0,n-1);
}
