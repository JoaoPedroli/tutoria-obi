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

const int MAX = 1e3+1, mV = 1<<20, mM = 105, INF = 0x3f3f3f3f, OUT = -INF, MOD = 1e9+7;
ll inv_mod(ll a, ll b){return a>1 ? b-inv_mod(b%a, a)*b/a : 1;}

str p;
ll fat[mV], re, ns[256];

int main(){_(0)
    fat[0] = 1;
    f(i,1,100124,1){
        fat[i] = (fat[i-1]*i)%MOD;
    }
    while(cin>>p){
        re = fat[len(p)]; //calculo 1 anagrama
        f(i,0,len(p),1){
            ++ns[p[i]];
        }
        f(i,'A','Z'+1,1){
            re = (re * inv_mod(fat[ns[i]], MOD))%MOD; //calculo 2 anagrama
            ns[i] = 0;
        }
        cout<<re<<'\n';
    }
return 0;}
