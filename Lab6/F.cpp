#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long

using namespace std;

const int N=500010;

int ex[N];
char s[N],a[N],b[N];
int has[N];  
	
void getnxt(int next[],char *str){
    int i=0,j,pos=1,len=strlen(str);
    next[0]=len;
    while(str[i]==str[i+1]&&i+1<len)i++;
	next[1]=i;
	for(i=2;i<len;i++){
	    if(next[i-pos]+i<next[pos]+pos){
	    	next[i]=next[i-pos];	        	
		}else{
	        j=next[pos]+pos-i;
	        if(j<0)j=0;
	        while(i+j<len&&str[j]==str[j+i])j++;
	        next[i]=j;
	        pos=i;
	    }
	}
}

void Exkmp(int next[],char *s1,char *s2){
    int i=0,j,pos=0,len=strlen(s1),l2=strlen(s2);
    getnxt(next,s2);
    while(s1[i]==s2[i]&&i<l2&&i<len)i++;
    ex[0]=i;
    for(i=1;i<len;i++){
        if(next[i-pos]+i<ex[pos]+pos){
        	ex[i]=next[i-pos];        	
		}else{
            j=ex[pos]+pos-i;
            if(j<0)j=0;
            while(i+j<len&&j<l2&&s1[j+i]==s2[j])j++;
            ex[i]=j;
            pos=i;
        }
    }

}

int main(){
	int next[N];
	for(int i=0;i<26;i++){
		cin >> s[i];
	}
	cin >> a;
    int len = strlen(a);
    for(int i=0;s[i];i++){
        has[s[i]] = i+'a';    	
	}
    memset(b,0,sizeof(b));
    for(int i=0;a[i];i++){
        b[i] = has[a[i]];         	
	} 
    Exkmp(next,a,b);
    int ans = len; 
    for(int i=0;i<len;i++){
        if(i+ex[i]>=len && i>=ex[i]){
            ans = i;
            break;
        }
    }
    cout << ans; 
    return 0;
}
/*
b c d e f g h i j k l m n o p q r s t u v w x y z a
bcdeabc
q w e r t y u i o p a s d f g h j k l z x c v b n m
qwertabcde
*/
