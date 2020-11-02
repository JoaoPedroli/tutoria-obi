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

//const int MAX = 1<<20, MAXN = 1<<20, MAXM  = 1<<17;
const int MAX = 1e6+1;

int n,m,ou,pos=0,fam=n;
ll re=0;
int pai[MAX];

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
aresta arestas[MAX];

bool comp(aresta a, aresta b){return a.w < b.w;}

int u, v, w;
void mst(){
    sort(arestas, arestas+pos, comp);
    for(int i=0; i<pos; ++i){
        u = arestas[i].u, v = arestas[i].v, w = arestas[i].w;
        if(id(u)!=id(v)){
            re+=w, --fam;
            join(u, v);
        }
    }
}

int main(){_(0)
    cin>>n;
    f(i,1,n,1){
        cin>>ou;
        pai[i] = i;
        w(ou){
            u = i;
            cin>>v>>w;
            arestas[pos++] = {u, v, w};
        }
    }
    mst();
    cout<<n+fam<<' '<<re<<'\n';
return 0;}
