#include<iostream>

using namespace std;

int n,x,y,i,j;

void merge(int num1[],int num2[], int x, int y, int temp[]){
        int i = 0;
        int j = 0;
        int t =0;

        while (i <= x && j<= y){
            if(num1[i] <= num2[j]){
                temp[t] = num1[i];
                t++;
                i++;
            }else {
                temp[t] = num2[j];
                t++;
                j++;
            }
        }

        while (i <= x){
            temp[t] = num1[i];
            t++; 
            i++;
        }

        while (j <= y){
            temp[t] = num2[j];
            t++;
            j++;
        }
    }

int main(){
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		int num1[x],num2[y],num[x+y];
		for(j=0;j<x;j++){
            cin >> num1[j];
        }
        for(j=0;j<y;j++){
           cin >> num2[j];
        }
        merge(num1,num2,x-1,y-1,num);
        for(j=0;j<x+y;j++){
           cout << num[j]<< " ";
        }
        cout << endl;
	}
	
}
