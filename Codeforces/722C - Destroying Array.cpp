#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1e5+5;

int exist[MAX] = {0}, ns[MAX];
int p[MAX], sum[MAX];
vector<int> ans;

int id(int u) {
  return (p[u] == u ? p[u] : p[u] = id(p[u]));
}

void join(int u, int v) {
  u = id(u), v = id(v);
  p[u] = v, sum[v] += sum[u];
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(nullptr);

  int x, n; cin>>n;
  for(int i = 1; i <= n; ++i) {
    cin>>x;
    p[i] = i, sum[i] = x;
  }
  for(int i = 1; i <= n; ++i) {
    cin>>ns[i];
  }

  ans.emplace_back(0);
  for(int i = n; i >= 1; --i) {
    const int I = ns[i];
    exist[I] = 1;
    if(exist[I+1]) join(I, I+1);
    if(exist[I-1]) join(I, I-1);
    const int ma = max(ans.back(), sum[id(I)]);
    ans.push_back(ma);
  }
  for(int i = n-1; i >= 0; --i) {
    cout<<ans[i]<<'\n';
  }
}
