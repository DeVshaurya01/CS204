#include <bits/stdc++.h>
using namespace std;

struct Node {
    int d; Node *l,*r;
    Node(int x):d(x),l(NULL),r(NULL){}
};

// Raw-array queue
struct Queue {
    Node* arr[20005]; int f=0,r=0;
    void push(Node* x){ arr[r++]=x; }
    Node* pop(){ return arr[f++]; }
    bool empty(){ return f==r; }
};

// Build tree from level order (including -1)
Node* build(int a[], int sz){
    if(sz==0 || a[0]==-1) return NULL;
    Node* root=new Node(a[0]);
    Queue q; q.push(root);
    int i=1;
    while(!q.empty() && i<sz){
        Node* cur=q.pop();
        if(i<sz && a[i]!=-1){ cur->l=new Node(a[i]); q.push(cur->l);} i++;
        if(i<sz && a[i]!=-1){ cur->r=new Node(a[i]); q.push(cur->r);} i++;
    }
    return root;
}

// Compute diameter in one pass
int diameter(Node* r, int &res){
    if(!r) return 0;
    int L=diameter(r->l,res);
    int R=diameter(r->r,res);
    res = max(res,L+R);
    return max(L,R)+1;
}

int main(){
    int n; cin>>n;
    int a[20005];
    int cnt=0;
    while(cnt<n*2){ // read enough numbers including possible -1s
        if(!(cin>>a[cnt])) break;
        cnt++;
    }

    Node* root = build(a,cnt);
    int res=0;
    diameter(root,res);
    cout<<res;
}
