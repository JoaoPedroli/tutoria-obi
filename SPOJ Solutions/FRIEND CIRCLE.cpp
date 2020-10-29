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

int t, n;
str x, y;
map<str, str> pai;
map<str, int> tam;

str id(str u){
    if(u==pai[u])return pai[u];
    return pai[u] = id(pai[u]);
}
void join(str u, str v){
    u = id(u), v = id(v);
    if(u==v)return;
    if(tam[x]<tam[y])swap(x, y);
    pai[v] = u, tam[u]+=tam[v];
}

int main(){_(1)
    cin>>t;
    w(t){
        cin>>n;
        w(n){
            cin>>x>>y;
            if(pai.find(x)==pai.end())pai[x] = x, tam[x] = 1;
            if(pai.find(y)==pai.end())pai[y] = y, tam[y] = 1;
            join(x, y);
            cout<<tam[id(x)]<<'\n';
        }
        pai.clear(), tam.clear();
    }
return 0;}
