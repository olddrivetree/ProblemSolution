#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define lc ((k)<<(1))
#define rc ((k)<<(1)|(1))
#define Mid (((l)+(r))>>(1))

const int N=1e6+1;

int L[N], R[N];
ll a[N], sum[N];

void rbuild(int k, int l, int r){
  if(l==r){sum[k]=sqrt(sum[k]);return;}
  rbuild(lc, l, Mid);
  rbuild(rc, Mid+1, r);
  sum[k]=sum[lc]+sum[rc];
}

void modify(int k, int l, int r, int x, int y){
  if(sum[k]==r-l+1)return;
  if(l>=x&&r<=y){rbuild(k, l, r);return;}
  if(x<=Mid) modify(lc, l, Mid, x, y);
  if(y>Mid)  modify(rc, Mid+1, r, x, y);
  sum[k]=sum[lc]+sum[rc];
}

void build(int k, int l, int r){
  if(l==r){sum[k]=a[l];return;}
  build(lc, l, Mid), build(rc, Mid+1, r);
  sum[k]=sum[lc]+sum[rc];
}

ll Ask(int k, int l, int r, int x, int y){
  if(l>=x&&r<=y)return sum[k];
  ll tmp=0;
  if(x<=Mid) tmp+=Ask(lc, l, Mid, x, y);
  if(y>Mid)  tmp+=Ask(rc, Mid+1, r, x, y);
  return tmp;
}

int n, m, cases;
int main(){
#ifdef LOCAL
  freopen("text.in", "r", stdin);
  freopen("text.out", "w", stdout);
#endif

  while(scanf("%d", &n)==1){
    printf("Case #%d:\n", ++cases);
    for(int i=1; i<=n; i++)
      scanf("%lld", &a[i]);
    build(1, 1, n);
    scanf("%d", &m);
    for(int i=1, x, y, op; i<=m; i++){
      scanf("%d %d %d", &op, &x, &y);
      if(x>y)swap(x, y);
      if(op==0)modify(1, 1, n, x, y);
      else printf("%lld\n", Ask(1, 1, n, x, y));
    }
    putchar('\n');
  }
  return 0;
}