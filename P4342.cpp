#include <bits/stdc++.h>
using namespace std;
const int N=101;
char c[N]; int a[N], n, f[N][N], g[N][N];
int main(){
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>c[i]>>a[i];
  for(int i=n+1; i<=2*n; i++)
    c[i]=c[i-n], a[i]=a[i-n];
  memset(f, -63, sizeof f);
  memset(g, 63, sizeof g);
  for(int i=1; i<=2*n; i++)
    f[i][i]=g[i][i]=a[i];
  for(int L=2; L<=n; L++){
    for(int i=1; i+L-1<=2*n; i++){
      int j=i+L-1;
      for(int k=i; k<j; k++){
        if(c[k+1]=='t') f[i][j]=max(f[i][j], f[i][k]+f[k+1][j]), g[i][j]=min(g[i][j], g[i][k]+g[k+1][j]);
        else{
          f[i][j]=max({f[i][j], f[i][k]*f[k+1][j], f[i][k]*g[k+1][j], g[i][k]*f[k+1][j], g[i][k]*g[k+1][j]});
          g[i][j]=min({g[i][j], f[i][k]*f[k+1][j], f[i][k]*g[k+1][j], g[i][k]*f[k+1][j], g[i][k]*g[k+1][j]});
        }
      }
    }
  }
  int ans=-0x3f3f3f3f;
  for(int i=1; i<=n; i++) ans=max(ans, f[i][i+n-1]);
  cout<<ans<<endl;
  for(int i=1; i<=n; i++) if(ans==f[i][i+n-1])cout<<i<<" ";
  cout<<endl;
  return 0;
}