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
# define ts to_string
# define len(x) x.length()
# define be(x) x.begin(), x.end()
# define rbe(x) x.rbegin(), x.rend()
# define bb(x, y) binary_search(be(x), y)
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second
# define mdc(a, b) __gcd(a, b)
#define esq(x) x*2
#define dir(x) x*2+1

const int MAX = 0, mV = 1<<20, INF = 0x3f3f3f3f, OUT = -INF;

int ns[mV], tprod[mV];
int n, soma;

int comp(int x, int y){
    return x*y;
}

int fast(int x){
    return (x>0?1:(x==0?0:-1));
}

void build(int u, int i, int j){
    if (i==j){
        tprod[u] = fast(ns[i]);
        return;
    }

    int mid = (i+j)/2;
    build(esq(u), i, mid);
    build(dir(u), mid+1, j);

    tprod[u] = comp(tprod[esq(u)], tprod[dir(u)]);
}

void update(int u, int i, int j, int idx, int val){
    if (i==j){
        tprod[u] = fast(val);
        return;
    }

    int mid = (i+j)/2;

    if (i<=idx && idx<=mid) update(esq(u), i, mid, idx, val);
    if (mid<idx && idx<=j) update(dir(u), mid+1, j, idx, val);

    tprod[u] = comp(tprod[esq(u)], tprod[dir(u)]);
}

int query(int u, int i, int j, int l, int r){
    if (l<=i && j<=r){
        return tprod[u];
    }
    if (j<l || r<i){
        return OUT;
    }

    int mid = (i+j)/2;

    int ans_esq = query(esq(u), i, mid, l, r);
    int ans_dir = query(dir(u), mid+1, j, l, r);

    if (ans_esq == OUT) return ans_dir; 
    if (ans_dir == OUT) return ans_esq; 

    return comp(ans_esq, ans_dir); 
}

int m, a, b, re;
char op;
int main(){_(0)
    while(cin>>n>>m){
        f(i,1,n+1,1){   
            cin>>ns[i];
        }

        build(1, 1, n);

        w(m){
            cin>>op>>a>>b;
            if(op == 'C'){
                update(1, 1, n, a, b);
            }else{
                re=query(1, 1, n, a, b);
                cout<<(re>0?'+':(re==0?'0':'-'));
            }
        }
        cout<<'\n';
    }
return 0;}
