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

const int MAX = 1e5+1;
int pai[MAX], val[MAX];
int n, m, q, x, y, a, b, re, au;

int id(int u){
    if(u==pai[u])return pai[u];
    return pai[u] = id(pai[u]);
}
void join(int u, int v){
    u = id(u), v = id(v);
    pai[v] = u, val[u]+=val[v];
}

int main(){_(1)
    while(cin>>n>>m&&n||m){
        re=0;
        f(i,1,n+1,1){
            cin>>val[i];
            pai[i] = i;
        }
        f(i,0,m,1){
            cin>>q>>x>>y;
            if(q==1){
                join(x, y);
            }else{
                a = id(x), b = id(y), au = id(1);
                if(val[a]>val[b]&&au==a)++re;
                else if(val[b]>val[a]&&au==b)++re;
            }
        }
        cout<<re<<'\n';
    }
return 0;}
