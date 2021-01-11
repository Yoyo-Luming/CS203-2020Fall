#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>

using namespace std;

int T,n,i,j;
char c;
bool flag;
struct node
{
    char c;
    node *next,*prev;
    node() : c(0), next(0), prev(0){};
    node(char x) : c(x), next(0), prev(0){};
};
node *head, *EOL, *cur_Node,*s = new node();

void del_Node(){
    if (cur_Node == EOL) {
    	return;
	}
    cur_Node->prev->next = cur_Node->next;
    cur_Node->next->prev = cur_Node->prev;
    cur_Node = cur_Node->next;
}

void add_Node(char x){
    if (flag)
    {
        if (cur_Node!=EOL){
            cur_Node->c=x;
        }else{
            s = cur_Node->prev;
            cur_Node->prev = new node(x);
            cur_Node->prev->next = cur_Node;
            s->next = cur_Node->prev;
            cur_Node->prev->prev = s;
            cur_Node = cur_Node->prev;
        }
    }else{
        s = cur_Node->prev;
        cur_Node->prev = new node(x);
        cur_Node->prev->next = cur_Node;
        s->next = cur_Node->prev;
        cur_Node->prev->prev = s;
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
    T = read();
    for(i=0;i<T;i++){
    	n = read();
    	EOL = new node();
        head = new node();
        head->next = EOL;
        EOL->prev = head;
        cur_Node = EOL;
        flag = 0;
        for (j=0;j<n;j++){
            c = getchar();
            if(c == 'x'){
            	del_Node();
                flag = 0;
			}else if(c == 'L'){
				if (cur_Node != EOL){
                    cur_Node = cur_Node->next;
                }
                flag = 0;
			}else if(c == 'H'){
				if (cur_Node->prev!=head){
                    cur_Node = cur_Node->prev;
                }
                flag = 0;
			}else if(c == 'I'){
				cur_Node = head->next;
                flag = 0;
			}else if(c == 'r'){
				flag = 1;
			}else{
				add_Node(c);
                flag = 0;
			}
        }
        for (node *k=head->next;k != EOL;k=k->next){
            putchar(k->c);
        }
        putchar('\n');
    }
}
