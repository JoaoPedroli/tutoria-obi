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

const int MAX = 101, mV = 1<<20, mM = 105, INF = 0x3f3f3f3f, OUT = -INF, MOD = 1e9+7, OUT2 = -1;

struct vetor
{
    double x, y;
    vetor operator +(vetor q) const{
        return {x + q.x, y + q.y};
    }
    vetor operator -(vetor q) const{
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
};

int sign(double x)
{
    return (x>0 ? 1 : (x < 0 ? -1 : 0));
}

ll orientation(vetor a,vetor b,vetor m)
{  
    return ((b.x - a.x)*(m.y - a.y)-(m.x - a.x)*(b.y - a.y));  
}

int in_seg(vetor a,vetor b,vetor m)
{  
    return min(a.x,b.x) <= m.x && m.x <= max(a.x,b.x) 
           &&
           min(a.y,b.y) <= m.y && m.y <= max(a.y,b.y);
}  

int intersection_seg(vetor x1,vetor y1,vetor x2, vetor y2)
{  
    ll o1,o2,o3,o4;
    o1 = orientation(x2,y2,x1), o2 = orientation(x2,y2,y1), o3 = orientation(x1,y1,x2), o4 = orientation(x1,y1,y2);  
    if((o1*o2 < 0) && (o3*o4 < 0))return 1;

    if(!o1&&in_seg(x2,y2,x1))return 1;  
    if(!o2&&in_seg(x2,y2,y1))return 1;  
    if(!o3&&in_seg(x1,y1,x2))return 1;  
    if(!o4&&in_seg(x1,y1,y2))return 1;  
    return 0;    
}  

int t, n, re;
double x1, x2, yy1, y2;
vt<pair<vetor , vetor>> ns;

int main(){_(0)
    cin>>t;
    w(t){
        cin>>n;
        re=0, ns = vt<pair<vetor , vetor>>(n+1);
        f(i,0,n,1){
            cin>>x1>>yy1>>x2>>y2;
            ns[i] = pair<vetor , vetor>{ {x1, yy1} , {x2, y2} };
        }
        f(i,0,n,1)
            f(j,0,n,1)
                if(i!=j)
                    if(intersection_seg(ns[i].ft, ns[i].se, ns[j].ft, ns[j].se)){
                        ++re;break;
                    }
        cout<<n-re<<'\n';
    }
return 0;}
