#include <bits/stdc++.h>
using namespace std;

struct Comp{
    string cname; vector<string> pax;
    Comp* prev; Comp* next;
    Comp(string nm):cname(nm),prev(NULL),next(NULL){}
};

Comp* append(Comp* head,Comp* node){
    if(!head) return node;
    Comp* tail=head; while(tail->next) tail=tail->next;
    tail->next=node; node->prev=tail; return head;
}

bool hasPassenger(Comp* c,const string& t){
    for(auto &p:c->pax) if(p==t) return true;
    return false;
}

Comp* findByName(Comp* head,const string& name){
    for(Comp* p=head;p;p=p->next) if(p->cname==name) return p;
    return NULL;
}

int main(){
    int n; cin>>n;
    Comp* head=NULL;
    for(int i=0;i<n;i++){
        string cname; cin>>cname;
        Comp* c=new Comp(cname);
        string tok;
        while(cin>>tok){ if(tok=="-1") break; c->pax.push_back(tok); }
        head=append(head,c);
    }
    string startName,target; cin>>startName>>target;
    if(!head){ cout<<-1<<"\n"; return 0; }
    Comp* start=findByName(head,startName);
    if(!start){ cout<<-1<<"\n"; return 0; }
    Comp* fwd=start; Comp* bwd=start;
    do{
        if(hasPassenger(fwd,target)){ cout<<fwd->cname<<"\n"; return 0; }
        if(fwd!=bwd && hasPassenger(bwd,target)){ cout<<bwd->cname<<"\n"; return 0; }
        fwd=fwd->next?fwd->next:head;
        bwd=bwd->prev?bwd->prev:({Comp* t=head; while(t->next) t=t->next; t;});
    }while(fwd!=start || bwd!=start);
    cout<<-1<<"\n";
}