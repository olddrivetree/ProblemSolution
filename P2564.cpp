#include <bits/stdc++.h>
using namespace std;
struct Node{
  int color, pos;
};
const int N=1e6+11;
int n, k, ans=0x3f3f3f3f, m, cnt[N], tmp;
Node a[N];
int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin>>n>>k;
  for(int i=1; i<=k; i++){
    int tt; cin>>tt;
    for(int j=1; j<=tt; j++){
      int x; cin>>x; a[++m]={i, x};
    }
  }
  sort(a+1, a+n+1, [](Node x, Node y){return x.pos<y.pos;});
  for(int i=1, l=1; i<=n; i++){
    if(++cnt[a[i].color]==1)tmp++;
    while(l<i)
      if(cnt[a[l].color]>1)cnt[a[l].color]--, l++;
      else break;
    if(tmp==k){ans=min(ans, a[i].pos-a[l].pos);}
  }
  cout<<ans<<endl;
  return 0;
}