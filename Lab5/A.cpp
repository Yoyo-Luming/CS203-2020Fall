#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define M 400000

typedef struct Stack {
    char element[M];
    int top;
}Stack;

void InitStack(Stack *s)
{
    s->top = -1;
}

int PushStack(Stack *s, char ch)
{
    if(s->top == M-1) {
        return 0;
    }
    s->top++;
    s->element[s->top] = ch;
    return 1;
}

int PopStack(Stack *s, char *ch)
{
    if(s->top == -1) {
        return 0;
    }
    *ch = s->element[s->top];
    s->top--;
    return 1;
}

int GetTop(Stack *s, char *ch)
{
    if(s->top == -1) {
        return 0;
    }
    *ch = s->element[s->top];
    return 1;
}

int IsEmpty(Stack *s)
{
    if(s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int MatchBracket(char ch1, char ch2)
{
    if(ch1 == '(' && ch2 == ')') {
        return 1;
    }
    if(ch1 == '[' && ch2 == ']') {
        return 1;
    }
    if(ch1 == '{' && ch2 == '}') {
        return 1;
    }
    return 0;
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

int main()
{
	int T = read();
	while(T--){
		int n= read();
		if(n%2==1){
			printf("NO\n");
			continue;
		} 
	    Stack s;
	    char str[M] = {0}, ch;
	    int i,jud=0;
	
	    InitStack(&s);
	    fscanf(stdin, "%s", str);
	    for(i = 0; str[i] != 0; i++) {
	        switch(str[i]) {
	            case '(':
	            case '[':
	            case '{':
	                PushStack(&s, str[i]);
	                break;
	            case ')':
	            case ']':
	            case '}':
	                if(IsEmpty(&s)) {
	                    printf("NO\n");
	                    ++jud;
	                    goto ne3;
	                } else {
	                    GetTop(&s, &ch);
	                    if(MatchBracket(ch , str[i])) {
	                        PopStack(&s, &ch);
	                    } else{
	                        printf("NO\n");
	                        ++jud;
	                        goto ne3;
	                    }
	                }
	        }
	    }
	    ne3:;
	    if(jud==0){
		    if(IsEmpty(&s)) {
		        printf("YES\n");
		    } else {    
		        printf("NO\n");
		    }
		}
	}
    return 0;
}
