#pragma GCC optimize(3, "Ofast", "inline")
#include<iostream>
#include<vector> 
#include<algorithm>
#include<cmath>
#define MAXN 200005

using namespace std;

struct student{
	int juan;
	int index;
};

int Cur =1;
student Heap[MAXN];

void Insert(student a)     
{
	Heap[Cur]= a;    
	int Temp_Cur = Cur;
	while (Temp_Cur > 1)  
	{
		int Root = Temp_Cur / 2;   
		if (Heap[Root].juan < a.juan){
			student temp = Heap[Root];
			Heap[Root] = Heap[Temp_Cur];
			Heap[Temp_Cur] = temp;
		}else{
			break;
		}   
		Temp_Cur = Root;     
	}
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

int main(){
	int T = read();
	while(T--){
		int n = read();
		Cur = 1;
		student students[n];
		
		long long sum[60];
		for(int i=0;i<32;++i){
			sum[i] = pow(2,i)-1;
		}
		for(int i=0;i<n;++i){
			students[i].index = i+1;
			students[i].juan = read();
			if(i!=0){
				Cur++;
				Insert(students[i]);
			}else{
				Heap[1] = students[0];
			}
		}
		int q = read();
		for(int i=1;i<=n;++i){
			if(Heap[i].index==q){
				for(int j=0;j<100;++j){
					if(sum[j]<i && sum[j+1]>=i){
						printf("%d %d\n",j+1,i-sum[j]);
						break;
				 	}
				}
				break;
			}
		}
	}
}
/*
3
2
2 1
1
3
1 2 3
2
5
3 1 2 2 3
4

1
5
3 1 2 2 3
4

*/
