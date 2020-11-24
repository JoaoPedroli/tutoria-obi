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

#define lsb(x) ((x)&(-x))
const int MAX = 1e3+7, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9+7;

int ns[mV], ftr[mV] = {0};
int n;

void update(int i, int val){
    while(i<=n){
        ftr[i]+=val;
        i += lsb(i);
    }
}

int query(int i){
    int re = 0;
    while(i>0){
        re += ftr[i];
        i -= lsb(i);
    }
    return re;
}

ll re;
int main(){_(0)
    cin >> n;

    f(i,1,n+1,1)cin>>ns[i];
    fd(i,n,1,1){
        re += query(ns[i]);
        update(ns[i], 1);
    }

    cout<<re<<'\n';
return 0;}
