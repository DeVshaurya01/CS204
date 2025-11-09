#include <bits/stdc++.h>
using namespace std;
bool isinpath(int source , int destination , vector<vector<int>> &vec ,vector<bool>& path ){
    if(source == destination){
        return true;
    }
    path[source] = true ; 
    for(int u : vec[source]){
        
        if(!path[u]) {if(isinpath(u, destination ,vec, path)){
            return true;
        }}
    }
    // path[source] = false;
    return false;
}
int main (){
    int v, e;
    cin>>v>>e; 
    vector<vector<int>> vec(v+1);
    for(int i = 0 ; i<e;i++){
        int x, y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    int source , destination ; 
    cin>>source>>destination ;
    vector<bool> path(v+1,false);
    if(isinpath(source,destination,vec,path)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
