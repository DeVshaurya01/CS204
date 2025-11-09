#include <bits/stdc++.h>
using namespace std;

struct Node {
    int d; Node *l,*r;
    Node(int x):d(x),l(NULL),r(NULL){}
};

// Queue using raw array
struct Queue {
    Node* arr[20005]; int f=0,r=0;
    void push(Node* x){ arr[r++]=x; }
    Node* pop(){ return arr[f++]; }
    bool empty(){ return f==r; }
};

// Build tree from level-order input (including -1)
Node* build(int a[], int n) {
    if(n==0 || a[0]==-1) return NULL;
    Node* root=new Node(a[0]);
    Queue q; q.push(root);
    int i=1;
    while(!q.empty()) {
        Node* cur=q.pop();
        if(i<n && a[i]!=-1){ cur->l=new Node(a[i]); q.push(cur->l);} i++;
        if(i<n && a[i]!=-1){ cur->r=new Node(a[i]); q.push(cur->r);} i++;
        if(i>=n) break;
    }
    return root;
}

// Returns height if balanced, else -1
int check(Node* r){
    if(!r) return 0;
    int L=check(r->l); if(L==-1) return -1;
    int R=check(r->r); if(R==-1) return -1;
    if(abs(L-R)>1) return -1;
    return max(L,R)+1;
}

int main(){
    int n; cin>>n;
    int a[20005]; // raw array
    int cnt=0;
    while(cnt<20005 && cnt<n+100){ // read enough numbers including -1s
        string s;
        if(!(cin>>s)) break;
        stringstream ss(s); int x; ss>>x;
        a[cnt++]=x;
    }

    Node* root=build(a,cnt);
    cout<<(check(root)!=-1?"YES":"NO");
}
