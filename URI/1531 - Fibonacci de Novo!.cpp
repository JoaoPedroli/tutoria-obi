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
# define len(x) x.length()
# define be(x) x.begin(), x.end()
# define rbe(x) x.rbegin(), x.rend()
# define bb binary_search
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second

//const int MAXM  = 2e4+1, INF = INT_MAX;

int pp(long m) {
    vector<long> v{1, 1};
    
    while(true) {
        long t = (v[v.size() - 1] + v[v.size() - 2]) % m;
        v.pb(t);
        
        if (t == 0 && v.size() % 2 == 0
        &&
        equal(v.begin(), v.begin() + v.size() / 2, v.begin() + v.size() / 2, v.end()))
            return v.size() / 2;

    }
    return v.size() / 2;
}

ll n, m, a, b, c, d, MOD;

void fib(ll n,ll ans[]){
    if(n == 0){
        ans[0] = 0, ans[1] = 1;
        return;
    }
    
    fib(n/2,ans), a = ans[0], b = ans[1], c = 2*b - a;
    
    if(c < 0)c += MOD;

    c = (a * c) % MOD, d = (a*a + b*b) % MOD;
    
    if(n%2 == 0)
        ans[0] = c, ans[1] = d;
    else
        ans[0] = d, ans[1] = c+d;
}

int main(){_(0)
    while(cin>>n>>m){
        ll ans[2] = {0};
        MOD = pp(m), fib(n, ans), MOD = m, fib(ans[0], ans);
        cout<<ans[0]<<'\n';
    }
return 0;}
