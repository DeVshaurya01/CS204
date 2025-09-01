#include <bits/stdc++.h>
using namespace std;

struct Node{
    string name; long long t;
    Node* next;
    Node(string nm,long long tt):name(nm),t(tt),next(NULL){}
};

Node* append(Node* head,string nm,long long tt){
    Node* n=new Node(nm,tt);
    if(!head){ n->next=n; return n; }
    Node* tail=head; while(tail->next!=head) tail=tail->next;
    tail->next=n; n->next=head; return head;
}

int main(){
    int k; cin>>k;
    Node* head=NULL;
    for(int i=0;i<k;i++){ string nm; long long tt; cin>>nm>>tt; head=append(head,nm,tt); }
    if(!head) return 0;
    Node* p=head; Node* tail=head; while(tail->next!=head) tail=tail->next;
    bool first=true;
    while(p->next!=p){
        p->t-=5;
        if(p->t<=0){
            if(!first) cout<<" ";
            cout<<p->name; first=false;
            if(p==head) head=p->next;
            tail->next=p->next;
            Node* del=p; p=p->next; delete del;
        } else { tail=p; p=p->next; }
    }
    if(!first) cout<<" ";
    cout<<p->name<<"\n";
}