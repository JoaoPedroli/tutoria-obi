#include <bits/stdc++.h>
using namespace std;

#define vt vector
typedef long long ll; typedef long double ld; typedef pair<int, int> ii;
typedef pair<int, ii> iii; typedef vt<int> vi; typedef vt<vi> vvi;
typedef vt<ld> vd; typedef vt<string> vs; typedef vt<ii> vii;
typedef vt<vt<ii>> vvii; typedef vt<ll> vll;

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

int n;
vvi adj, dist;
priority_queue<iii, gr(iii)> pq;

void dijkstra(int i, int j) {
  dist[i][j] = 0;
  pq.push({ dist[i][j], { i, j } });

  while(!pq.empty()) {
    int d = pq.top().F;
    i = pq.top().S.F, j = pq.top().S.S;
    pq.pop();

    if(d > dist[i][j]) continue;

    if(i+1 < n && adj[i+1][j] + dist[i][j] < dist[i+1][j]) {
      dist[i+1][j] = adj[i+1][j] + dist[i][j];
      pq.push({ dist[i+1][j], { i+1, j } });
    }
    if(i-1 >= 0 && adj[i-1][j] + dist[i][j] < dist[i-1][j]) {
      dist[i-1][j] = adj[i-1][j] + dist[i][j];
      pq.push({ dist[i-1][j], { i-1, j } });
    }
    if(j+1 < n && adj[i][j+1] + dist[i][j] < dist[i][j+1]) {
      dist[i][j+1] = adj[i][j+1] + dist[i][j];
      pq.push({ dist[i][j+1], { i, j+1 } });
    }
    if(j-1 >= 0 && adj[i][j-1] + dist[i][j] < dist[i][j-1]) {
      dist[i][j-1] = adj[i][j-1] + dist[i][j];
      pq.push({ dist[i][j-1], { i, j-1 } });
    }
  }

}

int main() {

  cin>>n;
  adj = vvi(n+2, vi(n+2)), dist = vvi(n+2, vi(n+2, INF));

  F0R(i, n)
    F0R(j, n)
      cin>>adj[i][j];

  dijkstra(0, 0);

  cout<<dist[n-1][n-1]<<'\n';

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
