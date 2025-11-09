#include <bits/stdc++.h>
using namespace std;

struct treenode {
    int data;
    treenode* left;
    treenode* right;
    treenode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
    treenode(int val, treenode* left) {
        data = val;
        this->left = left;
        right = NULL;
    }
    treenode(int val, treenode* left, treenode* right) {
        data = val;
        this->left = left;
        this->right = right;
    }
};

treenode* buildtree(int n ){
   
    if(n==0){
        return NULL;
    }
    int rootvalue;
    cin>>rootvalue;
    if(rootvalue == -1){
        return NULL;
    }
    treenode * root = new treenode(rootvalue);
    treenode* qarr[10001];
    int start = 0 ; int end = 0 ;
    qarr[end] = root;
    end++;
    for(int i = 1; i<n;){
        treenode * currentnode = qarr[start];
        start ++;
        int leftvalue ;
        cin>>leftvalue;
        if(leftvalue!=-1){
            currentnode->left = new treenode(leftvalue);
            qarr[end] = currentnode->left;
            end++;
            i++;
        }
        if(i>=n){
            break;
        }
        int rightvalue ;
        cin>>rightvalue;
        if(rightvalue!=-1){
            currentnode->right = new treenode(rightvalue);
            qarr[end] = currentnode->right;
            end++;
            i++;
        }
       
    }
    return root;
}
void mirror_tree(treenode * root){
    if(root==NULL){
        return;
    }
    treenode * temp ;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror_tree(root->left);
    mirror_tree(root->right);
}
void levelorder(treenode* root,int n ) {
    if (root == NULL) {
        return;
    }
    treenode* qarr[10001];
    int start = 0;
    int end = 0;
    qarr[end] = root;
    end++;    
    int nonnull= 0;
    while(start < end && nonnull < n){
        if(qarr[start]== NULL){
            cout<<-1<<" ";
            start++;
            continue;
        }
        qarr[end]= qarr[start]->left;
        end++;
        qarr[end] = qarr[start]->right;
        end++;

        cout<<qarr[start]->data<<" ";
        start++;
        nonnull++;
    }
}
int main (){
    int n ; cin>>n;
    treenode * root = buildtree(n);

    mirror_tree(root);
    levelorder(root,n);
    cout<<endl;
}






