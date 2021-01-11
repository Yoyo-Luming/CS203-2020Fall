#pragma GCC optimize(3,"Ofast","inline")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define ll long long

using namespace std;
 
const int INF = 0x3fffffff;
const int N = 100100;
 
struct Node{
    int pos,id;
    Node*pre,*next;
}node[N];
 
vector<int>num;
set<int>st;
int tick[N];
 
void Delete(int u)
{
    Node*p = node[u].pre;
    p->next = node[u].next;
    node[u].next->pre = p;
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

inline void print(int x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
 
int main()
{
    int ca =read();
    for(int tem=0;tem<ca;tem++){
    	memset(node,0,sizeof(node));
        memset(tick,0,sizeof(tick));
        st.clear();
        num.clear();
        int n,p;
        n = read();
        node[0].pos = 0;
        node[0].id = 0;
        node[0].next = &node[1];
        node[0].pre = NULL;
        for( int i = 1 ; i <= n ; ++i ){
        	node[i].pos=read();
            node[i].id = i;
            node[i].next = &node[i+1];
            node[i].pre  = &node[i-1];
        }
        node[n+1].pos = INF;
        node[n+1].id = n+1;
        node[n+1].pre = &node[n];
        node[n+1].next = NULL;
        tick[0] = tick[n+1] = 1;
        for( int i = 1 ; i <= n ; ++i ){
            if(node[i].pos < node[i-1].pos || node[i].pos > node[i+1].pos){
                num.push_back(i);
                tick[i] = 1;
            }
        }
        int flag = 1;
        while(flag){
            st.clear();
            for( int i = 0 ; i < num.size() ; ++i ){
                int id1 = node[num[i]].pre->id;
                int id2 = node[num[i]].next->id;
                if(!tick[id1]) {
                	st.insert(id1);
				}
                if(!tick[id2]) {
                	st.insert(id2);
				}
                Delete(num[i]);
            }
            num.clear();
            for(set<int>::iterator it = st.begin() ; it != st.end() ; ++it){
                int p = *it;
                if(node[p].pos < node[p].pre->pos || node[p].pos > node[p].next->pos){
                    tick[p] = 1;
                    num.push_back(p);
                }
            }
            if(num.size() == 0){
            	flag = 0;
			} 
        }
        for( int i = 1 ; i <= n ; ++i ){
            if(tick[i] == 0){
            	num.push_back(node[i].pos);	
			} 
        }
        if(num.size() == 0){
            putchar('\n');
        }else{
            for( int i = 0 ; i < num.size() ; ++i ){
            	print(num[i]);
            	putchar(' ');
            }
            putchar('\n');
        }
    }
    return 0;
}
