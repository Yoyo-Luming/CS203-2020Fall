#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
 
const int MAX_N = 1000000 + 10;
const int N=2000, L=2000;

using namespace std;

struct Block_List {
    struct Node {
        char str[L];
        int next, size;
        void init(){
             memset(str, 0, sizeof(str));
             next = -1;
             size = 0;
        }
    }list[N];
    int head, tot;
 
    void init(char str[]){
         head = tot = 0;
         list[tot++].init();
         for (int i = 0, cur = head; str[i]; cur = list[cur].next){
             for (int j = 0; j < L && str[i]; j++, i++){
                 list[cur].str[j] = str[i];
                 list[cur].size++;
             }
             if (str[i]){
                list[tot].init();
                list[cur].next = tot++; 
             }
         } 
         for (int cur = head; cur != -1; cur = list[cur].next)
         if (list[cur].size == L) split(cur);
    }
    void split(int x){
         list[tot].init();
         for (int i = L / 2; i < L; i++){
             list[tot].str[i - L/2] = list[x].str[i];
             list[tot].size++;
             list[x].size--;
             list[x].str[i] = 0;
         }
         list[tot].next = list[x].next;
         list[x].next = tot++;
    }
    void insert(int pos, char val){
         int cur = head;
         while (pos - list[cur].size > 0 && list[cur].next != -1){
               pos -= list[cur].size;
               cur = list[cur].next; 
         }
         if (pos >= list[cur].size){
         	list[cur].str[list[cur].size] = val;
		 } else {
              for (int i = list[cur].size; i > pos; i--) list[cur].str[i] = list[cur].str[i - 1] ;
              list[cur].str[pos] = val;
         }
         list[cur].size++;
         if (list[cur].size == L) {
         	split(cur);
		 }
    }
    char find(int pos){
         int cur = head;
         while ( pos - list[cur].size > 0){
               pos -= list[cur].size;
               cur = list[cur].next;
         }
         return list[cur].str[pos - 1];
    }
}List;
char str[MAX_N];
int n;
 
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
 
int main() {
	int cc = read();
	for(int te=0;te<cc;te++){
	    scanf("%s", str);
	    n = read();
	    List.init(str);
	    for (int i = 0; i < n; i++){
	        int pos;
	        int op = read();
	        if (op == 1){
	           char S[2]; 
	           S[0] = getchar();
	           S[1] = getchar();
	           pos = read();
	           List.insert(pos - 1, S[0]);
	        } else {
	           pos = read();
	           putchar(List.find(pos));
	           putchar('\n');
	        }
	    } 
	}
    return 0;
}
