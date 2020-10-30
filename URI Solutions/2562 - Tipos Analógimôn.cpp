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

const int MAX = 1001;
int n, m, x, y, me, ma=1, pai[MAX], tam[MAX];

int id(int u){
    if(u==pai[u])return pai[u];
    return pai[u] = id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    if(u==v)return;
    if(tam[u]>tam[v])swap(u, v);
    pai[v] = u, tam[u]+=tam[v];
}

int main(){_(1)
    while(cin>>n>>m){
        f(i,1,n+1,1){
            pai[i] = i, tam[i] = 1;
        }
        f(i,0,m,1){
            cin>>x>>y;
            join(x, y);
        }
        cin>>x;
        cout<<tam[id(x)]<<'\n';
    }
return 0;}
