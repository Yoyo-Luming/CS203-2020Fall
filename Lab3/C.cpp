#include<iostream>
#include<algorithm>

using namespace std;

int c,n,counti=0,counts=0;

void Swap(int *elem1,int *elem2){
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void Selection(int *array,int l){
	for(int i=0;i<l;i++){
		int min = i;
		for(int j=i+1;j<l;j++){
			counts++;
			if(array[min] > array[j]){
				min = j;
			}
		}
		if(min != i){
		 	Swap(array+min,array+i);
		 	counts++;
		}
		
	}
}

void Insert(int arr[],int l){
	int i,j,key,gan=0;
	for(i=1;i<l;i++){
		key = arr[i];
		if(arr[i] < arr[i-1]){
			counti++;
		}
		for(j = i;j > 0;j--){
			counti++;
			if(arr[j-1] > arr[j]){
				Swap(arr+j-1,arr+j);
				counti++;
			}else{
				break;
			}
		}
		counti--;
	}
}

int main(){
	cin >> c;
	for(int i=0;i<c;i++){
		counti = counts = 0;
		cin >> n;
		int num1[n];
		int num2[n];
		for(int j=0;j<n;j++){
			cin>> num1[j];
			num2[j] = num1[j];
		}
		Selection(num1,n);
		Insert(num2,n);
		for(int j=0;j<n;j++){
			cout << num2[j]<< " ";
		}
		cout<<endl;
		if(counti <= counts){
			cout <<  "Insertion Sort wins!"<<endl;
		}else{
			cout << "Selection Sort wins!" << endl;
		}
	}
}
