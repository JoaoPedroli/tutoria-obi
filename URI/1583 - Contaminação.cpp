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

const int MAX = 51;
vs ns;
vvi memo;
int n,m;

void dfs(int i, int j){
    if(i==n||i==-1||j==m||j==-1)return;
    if(memo[i][j] or ns[i][j]=='X')return;

    memo[i][j] = 1, ns[i][j] = 'T', dfs(i+1, j), dfs(i-1, j), dfs(i,j-1), dfs(i, j+1);
}

int main(){_(0)
    ns = vs(MAX);
    while(cin>>n>>m&&n||m){
        memo = vvi(n+1, vi(m+1));
        f(i,0,n,1){
            cin>>ns[i];
        }
        f(i,0,n,1){
            f(j,0,len(ns[i]),1){
                if(ns[i][j]=='T' and !memo[i][j])dfs(i+1, j), dfs(i-1, j), dfs(i,j-1), dfs(i, j+1);
            }
        }
        f(i,0,n,1){
            for(char v:ns[i]){
                cout<<v;
            }
            cout<<'\n';
        }
        cout<<'\n';
    }

return 0;}
