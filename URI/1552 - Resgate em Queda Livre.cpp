#include <bits/stdc++.h>
using namespace std;

# define vt vector
# define pque priority_queue 
typedef long long ll;typedef long double lld;typedef string str;typedef pair<double, double> dd;
typedef vt<int> vi;typedef vt<vt<int>> vvi;typedef vt<double> vd;typedef vt<ll> vll;typedef pair<int,int> ii;
typedef vt<lld> vld;typedef vt<char> vc;typedef vt<str> vs;typedef vt<ii> vii;typedef vt<vii> vvii;
# define f(i,a,b,c) for(ll i=a;i<b;i+=c)
# define fd(i,a,b,c) for(ll i=a;i>=b;i-=c)
# define w(x) while(x--)
# define ctoi(a) (a-'0')
# define pb push_back
# define eb emplace_back
# define lb lower_bound
# define ub upper_bound
# define ts to_string
# define len(x) x.length()
# define be(x) x.begin(), x.end()   
# define rbe(x) x.rbegin(), x.rend()    
# define bb(x, y) binary_search(be(x), y)
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second
# define mdc(a, b) __gcd(a, b)

const int MAX = 1e5, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9+7;

struct a{
    double u, v, w;
};
struct point{
    double x, y;
};
bool comp(a x, a y){return x.w<y.w;}

vt<a> aresta;
point par[mV];
int pai[mV];
int t, n, m, op;

//union-find
int id(int u){
    return (pai[u]==u) ? u : pai[u] = id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    if(u == v)return;
    pai[u] = v;
}
//
double mst(){
    double re=0;
    sort(be(aresta), comp);
    f(i,0,aresta.size(),1){
        double u = id(aresta[i].u), v = id(aresta[i].v), w = aresta[i].w;
        if(u!=v){
            re+=w;
            join(u, v);
        }
    }
    return re/100;
}

int u, v;
int main(){_(2)
    cin>>t;
    w(t){
        cin>>n;
        f(i,1,n+1,1){
            cin>>par[i].x>>par[i].y;
            pai[i] = i;
            f(j,1,i,1){
                aresta.pb({i, j, hypot(par[i].x-par[j].x, par[i].y-par[j].y)});
            }
        }
        cout<<mst()<<'\n';
        aresta.clear();
    }
return 0;}
