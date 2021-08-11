#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct presente {
  ll id, vol;
};

ll t, n, m, v1, v2, v3;
presente ns[100006];

bool comp1(presente a, presente b) {
  if(a.vol != b.vol) return a.vol > b.vol;
  return a.id < b.id;
}

bool comp2(presente a, presente b) {
  return a.id < b.id;
}

int main() {
  scanf("%lld", &t);
  while(t--) {
    scanf("%lld %lld", &n, &m);
    
    for(ll i=0;i<n;++i) {
      scanf("%lld %lld %lld %lld", &ns[i].id, &v1, &v2, &v3);
      ns[i].vol = v1*v2*v3;
    }
    sort(ns, ns+n, comp1), sort(ns, ns+m, comp2);
    printf("%lld", ns[0].id);
    for(ll i=1;i<m;++i) {
      printf(" %lld", ns[i].id);
    }
    printf("\n");
  }
}
