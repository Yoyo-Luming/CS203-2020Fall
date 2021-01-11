#include<iostream>
#include<cstdio>

using namespace std;

class MyLinkedList {
public:
   
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(NULL){}
    };

    MyLinkedList() {
        myHead = new LinkedNode(0); 
        size = 0;
    }

    int get(int index) {
        if (index > (size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = myHead->next;
        while(index--){ 
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = myHead;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = myHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size || index < 0) {
            return;
        }
        LinkedNode* cur = myHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }

    void printLinkedList() {
        LinkedNode* cur = myHead;
        cout << "current list:";
        while (cur->next != NULL) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int size;
    LinkedNode* myHead;

};

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
	MyLinkedList list;
	int n = read();
	int m = read();
	int pos,val;
	char c;
	for(int i=0;i<n;i++) {
		val = read();
		list.addAtTail(val);
	}
	
	for(int i=0;i<m;i++) {
		scanf("\n%c",&c);
		if(c == 'i') {
			pos = read() - 1;
			val = read();
			list.addAtIndex(pos,val);
		} else if (c == 'q') {
			pos = read() - 1;
			val = list.get(pos);
			if(val != -1) {
				cout << val<< endl;
				//printf("%d\n",val);
			}
		} else if( c == 'r') {
			pos = read() - 1;
			list.deleteAtIndex(pos);
		}
		//list.printLinkedList();
	}
	return 0;
}

