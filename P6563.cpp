#include <bits/stdc++.h>
using namespace std;
const int N=7101;
int T, n, pos, que[N];
long long a[N], f[N][N];
int main(){
  scanf("%d", &T);
  while(T--){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
      scanf("%lld", &a[i]), f[i][i]=0;
    for(int r=2; r<=n; r++){
      int Head=1, Tail=1; que[1]=pos=r;
      for(int l=r-1; l; l--){
        if(l==r-1){f[l][r]=a[l];continue;}
        while(pos>l&&f[l][pos-1]>f[pos][r])pos--;
        f[l][r]=f[l][pos]+a[pos];
        while(Head<=Tail&&que[Head]>=pos)Head++;
        if(Head<=Tail)f[l][r]=min(f[l][r], f[que[Head]+1][r]+a[que[Head]]);
        while(Head<=Tail&&f[que[Tail]+1][r]+a[que[Tail]]>=f[l+1][r]+a[l])Tail--;
        que[++Tail]=l;
      }
    }
    cout<<f[1][n]<<endl;
  }
  return 0;
}