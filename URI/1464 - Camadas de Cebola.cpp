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

#define sz(x) ((int) (x).size())
const int MAX = 1e3+7, mV = 1<<20, mV2 = 1<<10, mV3 = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9+7;

struct vetor
{
    double x, y;
    vetor operator +(vetor q) const {
        return {x + q.x, y + q.y};
    }
    vetor operator -(vetor q) const {
        return {x - q.x, y - q.y};
    }
    double operator ~() const {
        return hypot(x, y);
    }
    double operator *(vetor q) const {
        return x*q.x + y*q.y;
    }
    double operator ^(vetor q) const {
        return x*q.y - y*q.x;
    }
    int operator <(vetor q) const {
        return (x<q.x || (x == q.x && y < q.y));
    }
    int operator !=(vetor q) const {
        return x!=q.x&&y!=q.y;
    }
    int operator ==(vetor q) const {
        return x==q.x&&y==q.y;
    }
};

void print(vetor v)
{
    cout<<v.x<<' '<<v.y<<'\n';
}

double distance(vetor p1, vetor p2) 
{ 
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int cw(vetor a, vetor b, vetor c)
{
    return (((b-a)^(c-b)) < 0);
}

int ccw(vetor a, vetor b, vetor c)
{
    return (((b-a)^(c-b)) > 0);
}

int n, re;
vetor p;
vt<vetor>cima, baixo, convex_hull;
set<vetor>pontos;

void ch(set<vetor> pontos){
    if(sz(pontos)<3)return;
    ++re;

    for(auto v:pontos){
        while(sz(cima)>1 && cw(cima.back(), v, cima[sz(cima)-2]))
            cima.pop_back();
        while(sz(baixo)>1 && ccw(baixo.back(), v, baixo[sz(baixo)-2]))
            baixo.pop_back();
        cima.pb(v), baixo.pb(v);
    }
    for(vetor v:cima)pontos.erase(v); //limpa envoltória de cima
    fd(i,sz(baixo)-2,1,1)pontos.erase(baixo[i]); //limpa envoltória de baixo
    // for(auto it:pontos){
    //     print(it);
    // }
    // cout<<'\n';
    convex_hull.clear(), cima.clear(), baixo.clear(), ch(pontos);
}

int main(){_(0)
    while(cin>>n&&n){
        f(i,0,n,1){
            cin >> p.x >> p.y;
            pontos.insert(p);
        }
        ch(pontos), cout<<(!(re%2)?"Do not take this onion to the lab!\n":"Take this onion to the lab!\n"), pontos.clear(), re=0;
    }
return 0;}
