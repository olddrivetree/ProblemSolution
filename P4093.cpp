#include <bits/stdc++.h>
using namespace std;
struct Node{
  int id, Mx, Mn, val, f;
};

const int N=3e5+1;
int n, m, v[N];
Node a[N];

int c[N];
void add(int x, int v){
  if(x==0)c[x]=max(c[x], v);
  else for(;x<=100001;x+=(x&-x))c[x]=max(c[x], v);
}
int Ask(int x){
  int res=0;
  for(;x;x-=(x&-x))res=max(res, c[x]);
  return max(res, c[0]);
}

bool cmp1(Node x, Node y){return x.val<y.val;}
bool cmp2(Node x, Node y){return x.Mn<y.Mn;}
bool cmp3(Node x, Node y){return x.id<y.id;}

void CDQ(int l, int r){
  if(l>=r)return;
  int Mid=l+r>>1;
  CDQ(l, Mid);
  for(int i=0; i<=100001; i++) c[i]=0;
  sort(a+l, a+Mid+1, cmp1);
  sort(a+Mid+1, a+r+1, cmp2);
  int j=l;
  for(int i=Mid+1; i<=r; i++){
    while(j<=Mid&&a[j].val<=a[i].Mn)add(a[j].Mx, a[j].f), j++;
    a[i].f=max(a[i].f, Ask(a[i].val)+1);
  }
  sort(a+Mid+1, a+r+1, cmp3);
  CDQ(Mid+1, r);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>a[i].val, a[i].id=i, a[i].Mn=a[i].Mx=a[i].val;
  for(int i=1; i<=m; i++){
    int x, v;     cin>>x>>v;
    a[x].Mn=min(a[x].Mn, v);
    a[x].Mx=max(a[x].Mx, v);
  }
  CDQ(0, n);
  int ans=0;
  for(int i=1; i<=n; i++)
    ans=max(ans, a[i].f);
  cout<<ans<<endl;
  return 0;
}