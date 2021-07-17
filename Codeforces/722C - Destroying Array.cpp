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

void log() { cout<<'\n'; }
void log(int a) { cout<<a<<'\n'; }
void log(vi a, int s = 0) {
  cout<<a[s];
  f(i, s+1, s(a))
    cout<<' '<<a[i];
  log();
}
void log(vvi a, int s1 = 0, int s2 = 0) {
  f(i, s1, s(a)) {
    cout<<a[s1][s2];
    f(j, s2+1, s(a[i]))
      cout<<' '<<a[i][j];
    log();
  }
}

void CIN(vi &ns, int I, int s = 0) {
  ns = vi(I);
  f(i, s, I)
    cin>>ns[i];
}
void CIN(vvi &ns, int I, int J, int s1 = 0, int s2 = 0) {
  ns = vvi(I, vi(J));
  f(i, s1, I)
    f(j, s2, J)
      cin>>ns[i][j];
}

int n, ns[mVI], p[mVI];
ll best, sum[mVI];
vi in;
vt<ll> out;

int id(int u) {
  return (p[u] == u) ? p[u] : p[u] = id(p[u]);
}

void join(int u, int v) {
  u = id(u), v = id(v);
  p[u] = v, sum[v] += sum[u];
}

int main() {_outputConfig(0);_fixAll(0);

  cin>>n;
  p[0] = -1, p[n+1] = -1;
  f(i,1,n+1) {
    cin>>ns[i];
    p[i] = -1, sum[i] = ns[i];
  }
  CIN(in, n);
  fd(i,n-1,1) {
    p[in[i]] = in[i];

    if(p[in[i]-1] != -1) join(in[i], in[i]-1);
    if(p[in[i]+1] != -1) join(in[i], in[i]+1);

    best = max(best, sum[id(in[i])]), out.pb(best);
  }
  fd(i,n-2,0) cout<<out[i]<<'\n';
  log(0);

return 0;}

/* ALERTAS:

  conflitos: [[
    f(i,0,n) {
      f(i,0,m) {
      }
    }

    ns[i] > ns[i] /// ns1[i] > ns2[i]
    ns[i] > ns[i] /// ns[i] > ns[j]
  ]]

  começos e limites de iterações: [[
    f(i,a,b) /// f(i,a,b+1)
    f(i,a,b) /// f(i,a-1,b)
  ]]

*/
