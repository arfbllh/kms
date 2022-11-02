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


int const N = 1e3 + 10;
vector<int> parent(N);
vector<int> g[N];
ll capacity[N][N];
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

int main()
{
  fastio();
   
  int n, m;
  cin>>n>>m;

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin>>a>>b>>c;
    g[a].push_back(b);
    capacity[a][b] += c;
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
  cout<<flow<<endl;

}
