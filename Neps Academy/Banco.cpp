#include <bits/stdc++.h>
using namespace std;

#define vt vector
typedef pair<int, int> ii;
typedef long long ll;
typedef vt<int> vi;
typedef vt<vt<int>> vvi;
typedef vt<string> vs;
typedef vt<ii> vii;

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
  f(i, s, s(a)) {
    if(i > s) cout<<' ';
    cout<<a[i];
  }
  cout<<'\n';
}
void log(vvi a, int s1 = 0, int s2 = 0) {
  f(i, s1, s(a)) {
    f(j, s2, s(a[i])) {
      if(j > s2) cout<<' ';
      cout<<a[i][j];
    }
    cout<<'\n';
  }
}

void CIN(vi &ns, int I, int s = 0) {
  ns = vi(I);
  f(i, s, I) {
  cin>>ns[i];
  }
}
void CIN(vvi &ns, int I, int J, int s1 = 0, int s2 = 0) {
  ns = vvi(I, vi(J));
  f(i, s1, I) {
    f(j, s2, J) {
      cin>>ns[i][j];
    }
  }
}

int c, n, t, d, tc, ic, sum = 0;
priority_queue<ii, vii, greater<ii>> pq;

int main() {_outputConfig(0);_fixAll(0);

  cin>>c>>n;
  f(i,1,c+1) {
    pq.push({0, i});
  }
  f(i,0,n) {
    cin>>t>>d;
    tc = pq.top().F, ic = pq.top().S;
    pq.pop();

    if(tc - t > 20) ++sum;

    pq.push({max(tc, t) + d, ic});
  }

  log(sum);

return 0;}
