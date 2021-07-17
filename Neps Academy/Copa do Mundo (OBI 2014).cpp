#include <bits/stdc++.h>
using namespace std;

#define vt vector
typedef pair<int, int> ii; typedef long long ll; typedef vt<int> vi;
typedef vt<vi> vvi; typedef vt<string> vs; typedef vt<ii> vii;

#define _outputConfig(a) if(a) ios::sync_with_stdio(0);cin.tie(0)
#define _fixAll(x) if(x >= 0) cout.precision(x);cout.setf(ios::fixed)
#define eb emplace_back
#define pb push_back
#define f(a, b, c) for(int a = b; a < c; ++a)
#define fd(a, b, c) for(int a = b; a >= c; --a)
#define w(a) while(a--)
#define s(a) int(a.size())
#define l(a) a.length()
#define be(ns) ns.begin(), ns.end()
#define rbe(ns) ns.rbegin(), ns.rend()
#define F first
#define S second
#define mdc(a, b) __gcd(a, b)

const int MAX = 1e3 + 2, mVI = 1<<20, mVJ = 1<<10, mVZ = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9 + 7;

int n, f, r, ans, p[mVI];

int id(int u) { return (p[u] == u) ? p[u] : p[u] = id(p[u]); }

void join(int u, int v) { p[v] = u; }

struct aresta { int u, v, w; };
aresta ferrovias[mVI], rodovias[mVI];

bool comp(aresta a, aresta b) { return a.w < b.w; }

int u, v, w;
int fmst() {
  ans = 0;
  sort(ferrovias, ferrovias+f, comp);
  f(i,0,f) {
    u = id(ferrovias[i].u), v = id(ferrovias[i].v), w = ferrovias[i].w;

    if(u != v) ans += w, join(u, v);
  }
  return ans;
}

int rmst() {
  ans = 0;
  sort(rodovias, rodovias+r, comp);
  f(i,0,r) {
    u = id(rodovias[i].u), v = id(rodovias[i].v), w = rodovias[i].w;

    if(u != v) ans += w, join(u, v);
  }
  return ans;
}

int main() {_outputConfig(0);_fixAll(0);

  cin>>n>>f>>r;
  f(i,0,n+1) p[i] = i;
  f(i,0,f) cin>>ferrovias[i].u>>ferrovias[i].v>>ferrovias[i].w;
  f(i,0,r) cin>>rodovias[i].u>>rodovias[i].v>>rodovias[i].w;
  cout<<fmst() + rmst()<<'\n';

return 0;}
