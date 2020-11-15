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
# define esq(x) x*2
# define dir(x) x*2+1

const int MAX = 1e3+1, mV = 1<<20, mM = 105, INF = 0x3f3f3f3f, OUT = -INF;

int n, m;
int u, v, w;
vvi gr, grj;
vi ordem, memo;

void dfs1(int n){
    memo[n] = 1;
    for(int v:gr[n]){
        if(!memo[v])dfs1(v);
    }
    ordem.eb(n);
}
void dfs2(int n){
    memo[n] = 1;
    for(int v:grj[n]){
        if(!memo[v])dfs2(v);
    }
}
int scc(){
    int re = 0;

    memo = vi(n+1, 0);
    f(i,1,n+1,1)
        if(!memo[i])dfs1(i);

    memo = vi(n+1, 0);
    fd(i,n-1,0,1){
        if(!memo[ordem[i]]){
            dfs2(ordem[i]);
            ++re;
        }
    }

    ordem.clear();
    return re;
}

int main(){_(0)
    while(cin>>n>>m&&n||m){
        gr = vvi(n+1), grj = vvi(n+1);
        w(m){
            cin>>u>>v>>w;
            gr[u].eb(v), grj[v].eb(u);
            if(w==2)gr[v].eb(u), grj[u].eb(v);
        }
        cout<<((scc()==1)?1:0)<<'\n';
    }
return 0;}
