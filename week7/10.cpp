#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

const int MAXN = 100005;

// Factorials and inverse factorials
ll fac[MAXN], invfac[MAXN];

// Static adjacency list using raw arrays
int head[MAXN], child[MAXN], nextChild[MAXN], tot;
int sz[MAXN];
ll dp[MAXN];

// Fast modular exponentiation
ll powmod(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// Add child v to parent u
void addChild(int u, int v){
    child[tot] = v;
    nextChild[tot] = head[u];
    head[u] = tot++;
}

// DFS to compute subtree sizes and number of sequences
void dfs(int u){
    dp[u] = 1;
    sz[u] = 1;
    int sumChildren = 0;

    for(int i = head[u]; i != -1; i = nextChild[i]){
        int v = child[i];
        dfs(v);
        dp[u] = dp[u] * dp[v] % MOD;
        sumChildren += sz[v];
    }

    if(sumChildren > 0){
        dp[u] = dp[u] * fac[sumChildren] % MOD;
        for(int i = head[u]; i != -1; i = nextChild[i]){
            int v = child[i];
            dp[u] = dp[u] * invfac[sz[v]] % MOD;
        }
    }

    sz[u] += sumChildren;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // factorials
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = fac[i-1] * i % MOD;
    for(int i = 0; i <= n; i++) invfac[i] = powmod(fac[i], MOD-2);

    int ConArray[MAXN];
    for(int i = 0; i < n; i++) cin >> ConArray[i];

    // initialize adjacency list
    memset(head, -1, sizeof(int) * n);
    tot = 0;

    for(int i = 1; i < n; i++){
        int p = ConArray[i];
        if(p < 0 || p >= n){
            cerr << "Invalid parent index at node " << i << "\n";
            return 1;
        }
        addChild(p, i);
    }

    dfs(0);

    cout << dp[0] << "\n";

    return 0;
}
