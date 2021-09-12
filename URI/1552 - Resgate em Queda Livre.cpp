#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define vt vector
#define eb emplace_back
#define pb push_back
#define f(i, s, f) for(int i = s; i < f; ++i)
#define fd(i, s, f) for(int i = s; i >= f; --i)
#define r(x, ns) for(auto& x : ns)
#define s(x) int(x.size())
#define be(ns) ns.begin(), ns.end()
#define rbe(ns) ns.rbegin(), ns.rend()
#define gr(type) vt<type>, greater<type>
#define F first
#define S second

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int MAX = 502;

int t, n, p[MAX], u, v;
double w, ans;
ii points[MAX];

struct aresta { int u, v; double w; };
bool comp(aresta a, aresta b) { return a.w < b.w; }
vt<aresta> ns;

int id(int u) { return (p[u] == u) ? p[u] : p[u] = id(p[u]); }

void join(int u, int v) { p[u] = v; }

double mst() {
  ans = 0.0;
  sort(be(ns), comp);
  f(i,0,s(ns)) {
    u = id(ns[i].u), v = id(ns[i].v), w = ns[i].w;

    if(u != v) ans += w, join(u, v);
  }
  return ans / 100.0;
}

int main() {
  cin>>t;
  while(t--) {
    cin>>n;
    f(i,1,n+1) {
      cin>>points[i].F>>points[i].S;
      p[i] = i;
      f(j,1,i) {
        ns.pb({ i, j, hypot(points[i].F - points[j].F, points[i].S - points[j].S) });
      }
    }
    cout<<fixed<<setprecision(2)<<mst()<<'\n';
    ns.clear();
  }
}
