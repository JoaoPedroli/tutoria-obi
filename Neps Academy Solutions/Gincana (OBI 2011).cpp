#include <bits/stdc++.h>
using namespace std;

typedef long long ll;typedef long double lld;typedef string str;typedef pair<double, double> dd;
typedef vector<int> vi;typedef vector<vector<int>> vvi;typedef vector<double> vd;typedef vector<ll> vll;
typedef vector<lld> vld;typedef vector<char> vc;typedef vector<str> vs;typedef pair<int,int> ii;
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
# define _(x) cout.precision(x);cout.setf(ios::fixed);
# define ft first
# define se second

int n, k, ou, x, y, pai[1001];
set<int> ns;

int id(int u){
    if(u==pai[u])return pai[u];
    return (pai[u] = id(pai[u]));
}

void join(int u, int v){
    u = id(u), v = id(v);
    pai[v] = u;
}

int main(){_(1)
    cin>>n>>k;
    f(i,1,n+1,1){
        pai[i]=i;
    }
    f(i,0,k,1){
        cin>>x>>y;
        join(x,y);
    }
    f(i,1,n+1,1)
        ns.insert(id(i));
    cout<<ns.size()<<'\n';
return 0;}
