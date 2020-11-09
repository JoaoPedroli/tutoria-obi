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
#define esq(x) x*2
#define dir(x) x*2+1

const int MAX = 0, mV = 1<<20, INF = 0x3f3f3f3f, OUT = -INF;

vvii gr;
vi dist;
int t, n, m, s;

int dijkstra(int s, int a){
    dist = vi(n+1, INF);
    pque<ii, vii, greater<ii>>pq;

    dist[s] = 0, pq.push(ii(dist[s], s));

    while(!pq.empty()){
        ii topo = pq.top();pq.pop();
        int d = topo.ft, u = topo.se;

        if(d>dist[u])continue;
        if(u==a)return dist[a];

        for(auto [v, w]:gr[u]){
            if(dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
                pq.push(ii(dist[v], v));
            }
        }
    }
    return INF;
}
int u,v,w,a,re,in=0;
int main(){_(0)
    cin>>t;
    w(t){
        cin>>n>>m>>s>>a;
        gr = vvii(n+1);
        f(i,0,m,1){
            cin>>u>>v>>w;
            gr[u].eb(v, w), gr[v].eb(u, w);
        }
        cout<<"Case #"<<++in<<": ";
        re=dijkstra(s, a);
        if(re!=INF)cout<<re<<'\n';
        else cout<<"unreachable\n";
    }
return 0;}
