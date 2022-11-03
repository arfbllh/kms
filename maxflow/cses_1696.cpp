#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define ff first
#define ss second
#define endl "\n"
#define pb(x) push_back(x)
#define pp() pop_back()
#define inf LONG_MAX
#define dvg(x) cout<<#x<<" "<<x<<endl;
#define dvg2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dvgv(x) cout<<#x<<" { "; for(auto i : x) {cout<<i<<" ";} cout<<"}"<<endl;
#define dvgp(x) cout<<#x" {"<<x.ff<<", "<<x.ss<<"}"<<endl;
int dx[] {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int const N = 1e3 + 10;
int const bias = 500;
int n, k;
vector<int> g[N], mt(N), used(N);

bool try_kuhn(int u)
{
    for(int v : g[u]){
        if(!mt[v]){
            mt[v] = u;
            return true;
        }
        else if(used[v]) continue;
        else{
            used[v] = 1;
            if(try_kuhn(mt[v])){
                mt[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
  fastio();
   
  int n, m, k;
  cin>>n>>m>>k;
  for(int i = 1; i <= k; i++){
    int a, b;
    cin>>a>>b;
    g[a].push_back(b);
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    used = vector<int>(n);
    if(try_kuhn(i)) {
        ans++;
    }
  }
  cout<<ans<<endl;
  for(int i = 1; i <= m; i++){
    if(mt[i]) cout<<mt[i]<<" "<<i<<endl;
  }
  
}
