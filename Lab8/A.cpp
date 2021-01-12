#pragma GCC optimize(3, "Ofast", "inline")
#include<iostream>
#include<queue>
#include<vector> 
#define nullptr NULL

using namespace std;

struct Node {
    int value;
    Node* fa;
    Node* left;
    Node* right;
    Node(int value):
        value(value), left(nullptr), right(nullptr), fa(nullptr) {}
};

bool isCBT(Node* head) {
    if (head == nullptr) {
        return true;
    }
    std::queue<Node*> qcbt;
    qcbt.push(head);
    Node* front = nullptr;
    while (front = qcbt.front()) {  // not ==, return we first encount nullptr
        qcbt.push(front->left);
        qcbt.push(front->right);
        qcbt.pop();
    }
    while(!qcbt.empty()) {
        if (qcbt.front() != nullptr) {  // if we encount a not nullptr, return fase
            return false;
        }
        qcbt.pop();
    }
    return true;    // if pass the check, is CBT!
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
	int T = read();
	for(int k=0;k<T;k++){
		int n = read(), num[n], cnt[n], dif[n], fa, son, flag = 0, temp = 1;
		Node* nodes[n];
		Node* root;
		for(int i=0;i<n;++i){
			num[i] = read();
			cnt[i] = 0;
			nodes[i] = new Node(num[i]);
		}
		for(int i=0;i<n-1;++i){
			fa = read();
			son = read();
			dif[i] = num[fa-1]- num[son-1];
			++cnt[fa-1];
			nodes[son-1]->fa = nodes[fa-1];
			if(cnt[fa-1]==1){
				nodes[fa-1]->left = nodes[son-1];
			}else if(cnt[fa-1]==2){
				nodes[fa-1]->right = nodes[son-1];
			}else{
				flag = 1;
			}
		}
		if(flag==0){
			for(int i=0;i<n;i++){
				if(nodes[i]->fa==nullptr){
					root = nodes[i];
					break;
				}
			}
			if(!isCBT(root)){
				flag =1;
				goto ne;
			}
			for(int i=0;i<n-1;++i){
				if(dif[i] > 0){
					temp = 1;
					break;
				}
				if(dif[i] < 0){
					temp = -1;
					break;
				}
			}
			for(int i=0;i<n-1;++i){
				if(dif[i]*temp<0){
					flag = 1;
					break;
				}
			}			
		}
		ne:if(flag==0){
			printf("Case #%d: YES\n",k+1);
		}else{
			printf("Case #%d: NO\n",k+1);
		}
	}
}


