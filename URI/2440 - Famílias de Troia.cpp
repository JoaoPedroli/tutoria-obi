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

vvi gr;
vi memo;
int n, m, a, b, re=0;

void dfs(int i){
    if(memo[i])return;
    memo[i]=1;
    for(int v:gr[i]){
        dfs(v);
    }
}
int main(){_(1)
    cin>>n>>m;
    gr = vvi(n+1), memo = vi(n+1);
    f(i,0,m,1){
        cin>>a>>b;
        gr[a].eb(b), gr[b].eb(a);
    }
    f(i,1,n+1,1){
        if(!memo[i]){
            dfs(i);
            ++re;
        }
    }
    cout<<re<<'\n';
return 0;}
