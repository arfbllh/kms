#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define endl "\n"
#define pb(x) push_back(x)
#define pp() pop_back()
#define inf INT32_MAX
#define dvg(x) cout<<#x<<" "<<x<<endl;
#define dvg2(x, y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define dvgv(x) cout<<#x<<" { "; for(auto i : x) {cout<<i<<" ";} cout<<"}"<<endl;
#define dvgp(x) cout<<#x" {"<<x.ff<<", "<<x.ss<<"}"<<endl;


int const N = 1e3 + 10;
vector<int> parent(N);
vector<int> g[N];
ll capacity[N][N], ej[N][N];
ll bfs(int s, int t)
{
  fill(parent.begin(), parent.end(), -1);
  
  queue<pll> q;
  q.push({s, inf});
  while(!q.empty()){
    int cur = q.front().ff;
    ll flow = q.front().ss;
    q.pop();
    for(int u = 1; u <= t; u++){
      if(parent[u] == -1 && capacity[cur][u]){
        parent[u] = cur;
        ll new_flow = min(flow, capacity[cur][u]);
        if(u == t){
          return new_flow;
        }
        q.push(pii(u, new_flow));
      }
    }
  }
  return 0;
}
int vis[N];
void dfs(int s, int n)
{
  vis[s] = 1;
  for(int i = 1; i <= n; i++) 
    if(!vis[i] && capacity[s][i])
      dfs(i, n);
}

int main()
{
  fastio();
   
  int n, m;
  cin>>n>>m;

  for(int i = 0; i < m; i++){
    int a, b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    capacity[a][b] = capacity[b][a] = 1;
    ej[a][b] = 1;
  }
  ll flow = 0;
  while(ll new_flow = bfs(1, n)){
    flow += new_flow;
    int cur = n;
    while(cur != 1){
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  dfs(1, n);
  vector<pii> ans;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++) 
      if((!vis[i] && vis[j]) || (vis[i] && !vis[j]))
        if(ej[i][j]) ans.push_back({i, j});
  }
  cout<<ans.size()<<endl;
  for(pii i : ans) cout<<i.ff<<" "<<i.ss<<endl;;

}
