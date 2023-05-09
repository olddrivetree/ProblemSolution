#include <bits/stdc++.h>
using namespace std;
const int N=4e6+11;
int n, fa[N], col[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x, int y){x=find(x), y=find(y); if(x!=y)fa[x]=y;}
int h[N], nt[N<<1], to[N<<1], cnt;
void link(int u, int v){
  nt[++cnt]=h[u], h[u]=cnt, to[cnt]=v;
}
int a[N], f[N];
int main(){
#ifdef LOCAL
  freopen("text.in","r",stdin);
  freopen("text.out","w",stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin>>n;
  int m=2*n+1;
  for(int i=1; i<=n; i++)fa[i]=i;
  for(int i=1; i<=n; i++) cin>>a[i*2];
  for(int i=1; i<n; i++) cin>>a[i*2+1];
  for(int i=2, mid=0, r=0; i<m; i++){
    f[i]=(i<=r?min(f[(mid<<1)-i],r-i+1):1);
    while(f[i]-1<a[i]){
      f[i]++;
      if(!(i-f[i]+1&1))merge(i-f[i]+1>>1,i+f[i]-1>>1);
    }
    link(i-f[i]>>1,i+f[i]>>1), link(i+f[i]>>1,i-f[i]>>1);
    if(i+f[i]-1>r)mid=i,r=i+f[i]-1;
  }
  for(int i=1; i<=n; i++)if(!col[find(i)]){
    static int vis[33];
    memset(vis, 0, sizeof vis);
    for(int j=h[i]; j; j=nt[j])vis[col[find(to[j])]]=1;
    for(int j=1; j<=26&&!col[find(i)]; j++)
      vis[j]==0&&(col[find(i)]=j);
  }
  for(int i=1; i<=n; i++)
    cout<<(char)(col[find(i)]+'a'-1);
  cout<<'\n';
  return 0;
}