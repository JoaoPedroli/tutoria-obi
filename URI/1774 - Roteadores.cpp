#include <bits/stdc++.h>
using namespace std;

# define vt vector
typedef long long ll;typedef long double lld;typedef string str;typedef pair<double, double> dd;
typedef vt<int> vi;typedef vt<vt<int>> vvi;typedef vt<double> vd;typedef vt<ll> vll;
typedef vt<lld> vld;typedef vt<char> vc;typedef vt<str> vs;typedef pair<int,int> ii;typedef vt<vt<ii>> vvii;
# define f(i,a,b,c) for(ll i=a;i<b;i+=c)
# define fd(i,a,b,c) for(ll i=a;i>=b;i-=c)
# define w(x) while(x--)
# define ctoi(a) (a-'0')
# define pb push_back
# define eb emplace_back
# define lb lower_bound
# define ub upper_bound
# define len(x) x.length()
# define be(x) x.begin(), x.end()
# define rbe(x) x.rbegin(), x.rend()
# define bb binary_search
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second

const int MAX = 1<<20, MAXN = 1<<20, MAXM  = 1<<17;

int n,m,r,re;
int pai[MAXN];

//union-find ---------------------
int id(int u){
    if(pai[u]==u)return pai[u];
    return pai[u] = id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    pai[v] = u;
}
//union-find ---------------------

struct aresta{
    int u, v, w;
};
aresta arestas[MAXM];

bool comp(aresta a, aresta b){return a.w < b.w;}

int u, v, w;
int mst(){
    re = 0;
    sort(arestas, arestas+m, comp);
    for(int i=0, j=0; i<m && j<n-1; ++i){
        u = arestas[i].u, v = arestas[i].v, w = arestas[i].w;
        if(id(u)!=id(v)){
            ++j, re+=w;
            join(u, v);
        }
    }
    return re;
}

int main(){_(0)
    cin>>n>>m;
    f(i,0,n+1,1)pai[i] = i;
    f(i,0,m,1){
        cin>>u>>v>>w;
        arestas[i] = {u, v, w};
    }
    cout<<mst()<<'\n';
return 0;}
