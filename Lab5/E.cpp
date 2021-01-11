#pragma GCC optimize(3, "Ofast", "inline")
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <map>
#include <queue>
#define ll long long

using namespace std;

struct E1 {
    int a, b, c;
    E1(int x, int y, int z) : a(x), b(y), c(z) {}
    bool operator<(const E1 &m) const {
        if (b == m.b) {
            return c < m.c;
        } else {
            return b < m.b;
        }
    }
};

inline const int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

map<int, int> mymap;
priority_queue<E1> que;
int cishu = 0;

void push(int x) {
    mymap[x] = mymap[x] + 1;
    que.push(E1(x, mymap[x], cishu++));
}

int pop() {
    E1 temp = que.top();
    int ans = temp.a;
    mymap[ans] = mymap[ans] - 1;
    que.pop();
    return ans;
}

int main() {
    char c,temp;
    int num;
    while (1) {
    	int j=0;
    	c = getchar();
    	temp = c;
    	while((c >= 'a' && c <= 'z' )|| c=='-'){
    		c = getchar();
		} 
//		printf("str:");
//		for(int k=0;k<j;k++){
//			putchar(str[k]);
//		}
//		printf("\n");
        if (temp == 'p') {
            num = read();
            push(num);
        } else if (temp == 'e') {
            if (que.size() > 0) {
                printf("%d\n", pop());
            } else {
                printf("pa\n");
            }
        } else {
            break;
        }
    }
}
