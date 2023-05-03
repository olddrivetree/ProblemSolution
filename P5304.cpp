#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PII pair<ll,int>
const int MAXN=1e5+11, MAXM=5e5+11;
const ll INF=1e17;
int n, m, T, K, KK[MAXN];
int h[MAXN], nt[MAXM<<1], to[MAXM<<1], cnt;
ll dist[MAXN], W[MAXM<<1];
bool vis[MAXN];
void init(){
  for(int i=1; i<=n; i++) h[i]=0;
  cnt=0;
}
void link(int u, int v, ll w){
  nt[++cnt]=h[u], h[u]=cnt, to[cnt]=v, W[cnt]=w;
}
ll dijkstra(ll ith, bool type){
  priority_queue<PII,vector<PII>,greater<PII>> q;
  for(int i=1; i<=n; i++) dist[i]=INF, vis[i]=0;
  for(int i=1; i<=K; i++)
    if(type==1&&(i&(1ll<<ith))>0||type==0&&(i&(1ll<<ith))==0)
      q.push({0, KK[i]}), dist[KK[i]]=0;
  while(!q.empty()){
    int u=q.top().second; q.pop();
    if(vis[u])continue;
    vis[u]=1;
    for(int i=h[u]; i; i=nt[i]){
      int v=to[i];
      if(dist[v]>dist[u]+W[i]){
        dist[v]=dist[u]+W[i];
        q.push({dist[v], v});
      }
    }
  }
  ll ans=INF;
  for(int i=1; i<=K; i++)
    if(type==0&&(i&(1ll<<ith))>0||type==1&&(i&(1ll<<ith))==0)
      ans=min(ans, dist[KK[i]]);
  return ans;
}
void solve(){
  scanf("%d %d %d", &n, &m, &K), init();
  for(int i=1, x, y, z; i<=m; i++)
    scanf("%d %d %d", &x, &y, &z), link(x, y, z);
  for(int i=1; i<=K; i++)scanf("%d", &KK[i]);
  ll ans=INF;
  for(int i=0; (1ll<<i)<=K; i++) ans=min({ans, dijkstra(i, 0), dijkstra(i, 1)});
  printf("%lld\n", ans);
}
int main(){
  scanf("%d", &T);
  while(T--)solve();
  return 0;
}