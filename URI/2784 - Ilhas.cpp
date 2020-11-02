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
# define len(x) x.length()
# define be(x) x.begin(), x.end()
# define rbe(x) x.rbegin(), x.rend()
# define bb binary_search
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second

const int MAX = 1<<10, MAXN = 101, MAXM  = 2e4+1, INF = 0x3f3f3f3f;

int n, m, s;
int u, v, w, ma=0, me = INF;
vvii gr;
vi dist, ult;   

void dijkstra(int s){
    dist = vi(n+1, INF), ult = vi(n+1, -1);
    pque<ii, vii, greater<ii>> pq;

    dist[s] = 0, pq.push(ii(dist[s], s));

    while(!pq.empty()){
        ii topo = pq.top();pq.pop();
        int d = topo.ft, u = topo.se;

        if(d > dist[u])continue;

        for(auto [v, w]:gr[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w, ult[v] = u;
                pq.push(ii(dist[v], v));
            }
        }
    }
}

int main(){_(0)
    cin>>n>>m;
    gr = vvii(n+1);
    f(i,0,m,1){
        cin>>u>>v>>w;
        gr[u].eb(v, w), gr[v].eb(u, w);
    }

    cin>>s;
    dijkstra(s);

    f(i,1,n+1,1){
        if(dist[i])me = min(me, dist[i]), ma = max(ma, dist[i]);
    }

    cout<<ma-me<<'\n';
    
return 0;}
