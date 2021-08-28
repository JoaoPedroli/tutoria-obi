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

const int mVI = 1<<20, mVJ = 1<<10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int MAX = 1e5+5;

int n, m, a, b, p[MAX], ns[MAX];
char c;

int id(int u) { return (p[u] == u ? p[u] : p[u] = id(p[u])); }

void join(int u, int v) { p[id(v)] = id(u); }

int main() {
  cin>>n>>m;
  f(i,0,n+1) p[i] = i;
  f(i,0,m) {
    cin>>c>>a>>b;
    if(c == 'F') join(a, b);
    else cout<<(id(a) == id(b) ? "S\n" : "N\n");
  }
}
