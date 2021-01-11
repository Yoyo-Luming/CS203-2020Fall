#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include<stdio.h>
#include<stdlib.h>

struct SeqQueue{
	int data[100000];
	int size;
	int max;
	int front;
	int tail;
};

SeqQueue* Init_SeqQueue(){
	SeqQueue* myqueue = (SeqQueue*)malloc(sizeof(SeqQueue));
	myqueue->size=0;
	return myqueue;
}
void Push_SeqQueue(SeqQueue* myqueue, int data){
	if(myqueue == NULL ){
		return;
	}
	myqueue->data[myqueue->size] = data;
	myqueue->size++; 
}
 
int Front_SeqQueue(SeqQueue* myqueue){
	if(myqueue ==NULL || myqueue->size ==0){
		return -1;
	}
	return myqueue->data[0];
}

void Pop_SeqQueue(SeqQueue* myqueue){
	if(myqueue->size ==0){
		return;
	}
	for(int i=0;i<myqueue->size - 1;i++){
		myqueue->data[i] = myqueue->data[i+1];
	}
	myqueue->size--;
}

int Back_SeqQueue(SeqQueue* myqueue){
	if(myqueue ==NULL || myqueue->size ==0){
		return -1;
	}
	return myqueue->data[myqueue->size-1];
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
	SeqQueue* myqueue = Init_SeqQueue();
	int T = read();
	
	for(int i=0;i<T;i++){
		char c = getchar();
		while(c != 'E' && c != 'A' && c!='D'){
			c = getchar();
		}
		if(c =='E'){
			Push_SeqQueue(myqueue,read());
		}else if(c == 'A'){
			printf("%d\n",Front_SeqQueue(myqueue));
		}else {
			Pop_SeqQueue(myqueue);
		}
	}
	while(myqueue->size>0){
			printf("%d ",Front_SeqQueue(myqueue));
			Pop_SeqQueue(myqueue);
		}
	return 0;
}
