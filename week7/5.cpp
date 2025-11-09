
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

treenode* buildtree(){
    int n ;
    cin>>n;
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
bool search(treenode * root, int target){
    if(target <0){
        return false;
    }
    if(root == NULL){
        return false;
    }
    if((target-root->data == 0) && (root->left == NULL) && (root->right == NULL)){
        return true;
    }
    return search(root->left , target-root->data) || search(root->right,target - root->data);

}
int main(){
    treenode * root = buildtree();
    int target ;cin>>target;
    if(search(root,target)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}