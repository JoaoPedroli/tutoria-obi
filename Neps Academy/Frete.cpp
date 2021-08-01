#include <bits/stdc++.h>
using namespace std;

#define vt vector
typedef long long ll; typedef long double ld; typedef pair<int, int> ii;
typedef vt<int> vi; typedef vt<vi> vvi; typedef vt<ld> vd;
typedef vt<string> vs; typedef vt<ii> vii; typedef vt<vt<ii>> vvii;
typedef vt<ll> vll;

#define eb emplace_back
#define pb push_back
#define F0R(i, f) for(int i = 0; i < f; ++i)
#define FOR(i, s, f) for(int i = s; i < f; ++i)
#define F0D(i, s) for(int i = s; i >= 0; --i)
#define FOD(i, s, f) for(int i = s; i >= f; --i)
#define FR(x, ns) for(auto x : ns)
#define FR2(x, y, ns) for(auto [x, y] : ns)
#define w(x) while(x)
#define s(x) int(x.size())
#define sof(x) int(sizeof(x)/sizeof(x[0]))
#define b(x) x.begin()
#define e(x) x.end()
#define be(ns) b(ns), e(ns)
#define rbe(ns) ns.rbegin(), ns.rend()
#define gr(type) vt<type>, greater<type>
#define lb(ns, n) lower_bound(be(ns), n)
#define ub(ns, n) upper_bound(be(ns), n)
#define F first
#define S second
#define mdc(a, b) __gcd(a, b)

const int MAX = 1e3 + 2, mVI = 1<<20, mVJ = 1<<10, mVZ = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9 + 7;

int n, m;
int u, v, w;
vvii adj;
vi dist, ult;
priority_queue<ii, gr(ii)> pq;

void dijkstra(int s) {
  dist = vi(n+1, INF); /**/
  ult = vi(n+1, -1);

  dist[s] = 0; /**/
  pq.push({ dist[s], s });

  while(!pq.empty()) {
    int d = pq.top().F, u = pq.top().S;
    pq.pop();

    if(d > dist[u]) continue;

    FR2(v, w, adj[u]) {
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w, ult[v] = u;
        pq.push({ dist[v], v });
      }
    }
  }
}

int main() {

  cin>>n>>m;
  adj = vvii(n+1);

  F0R(i, m) {
    cin>>u>>v>>w;
    adj[u].eb(v, w), adj[v].eb(u, w);
  }

  dijkstra(1);

  cout<<dist[n]<<'\n';

return 0;}

/* ALERTAS:

  conflitos: [[
    FOR(i,0,n) {
      FOR(i,0,m) {
      }
    }

    ns[i] > ns[i] /// ns1[i] > ns2[i]
    ns[i] > ns[i] /// ns[i] > ns[j]
  ]]

  começos e limites de iterações: [[
    FOR(i,a,b) /// FOR(i,a,b+1)
    FOR(i,a,b) /// FOR(i,a-1,b)
  ]]

*/
