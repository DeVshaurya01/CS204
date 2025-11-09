#include <bits/stdc++.h>
using namespace std;

struct Node{
    int d; Node *l,*r;
    Node(int x):d(x),l(NULL),r(NULL){}
};

// Build tree from preorder and inorder
Node* build(int pre[], int in[], int preS, int preE, int inS, int inE){
    if(preS>preE || inS>inE) return NULL;
    Node* root = new Node(pre[preS]);
    int idx = inS;
    while(idx<=inE && in[idx]!=pre[preS]) idx++; // find root in inorder
    int leftCount = idx - inS;
    root->l = build(pre, in, preS+1, preS+leftCount, inS, idx-1);
    root->r = build(pre, in, preS+leftCount+1, preE, idx+1, inE);
    return root;
}

void postorder(Node* r){
    if(!r) return;
    postorder(r->l);
    postorder(r->r);
    cout<<r->d<<" ";
}

int main(){
    int n; cin>>n;
    int pre[10005], in[10005];
    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>in[i];

    Node* root = build(pre, in, 0, n-1, 0, n-1);
    postorder(root);
}
