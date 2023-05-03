#include <bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n, a[N];
struct node{
  int x, y, id;
}w[N];
int c[N];
void ins(int x, int v){
  for(;x<=n; x+=(x&-x))
    c[x]=max(c[x], v);
}
int q(int x){
  int r=0;
  for(;x;x-=(x&-x))
    r=max(r, c[x]);
  return r;
}
int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
    scanf("%d", &a[i]), w[i]={i-a[i], a[i], i};
  sort(w+1, w+n+1, [=](node x, node y){return x.x!=y.x?x.x<y.x:x.id<y.id;});
  int ans=0;
  for(int i=1; i<=n; i++){
    if(w[i].x<0)continue;
    int x=q(w[i].y-1)+1;
    ans=max(ans, x);
    ins(w[i].y, x);
  }
  cout<<ans<<endl;
  return 0;
}