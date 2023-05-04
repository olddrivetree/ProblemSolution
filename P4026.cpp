#include <bits/stdc++.h>
using namespace std;
const int Cost[]={0, 100, 50, 20, 10, 5, 1};
int X1, X2, X3, A[8], B[8], C[8];
int f[7][1010][1010], n, E1, E2, E3;
int main(){
  cin>>X1>>X2>>X3;
  E1=X3-X1, E2=X1-X2, E3=X2-X3;

  cin>>A[1]>>A[2]>>A[3]>>A[4]>>A[5]>>A[6];
  E1+=A[1]*100+A[2]*50+A[3]*20+A[4]*10+A[5]*5+A[6]*1;

  cin>>B[1]>>B[2]>>B[3]>>B[4]>>B[5]>>B[6];
  E2+=B[1]*100+B[2]*50+B[3]*20+B[4]*10+B[5]*5+B[6]*1;

  cin>>C[1]>>C[2]>>C[3]>>C[4]>>C[5]>>C[6];
  E3+=C[1]*100+C[2]*50+C[3]*20+C[4]*10+C[5]*5+C[6]*1;

  n=E1+E2+E3;
  memset(f, 63, sizeof f);
  int inf=f[0][0][0];
  f[0][E1-(X3-X1)][E2-(X1-X2)]=0;
  for(int i=1; i<=6; i++)
  for(int j=0; j<=n; j++)
  for(int k=0; k+j<=n; k++){
    if(f[i-1][j][k]==inf)continue;
    for(int k1=0; k1<=A[i]+B[i]+C[i]; k1++)
    for(int k2=0; k2+k1<=A[i]+B[i]+C[i]; k2++){
      int nx=j+(k1-A[i])*Cost[i];
      int ny=k+(k2-B[i])*Cost[i];
      if(nx<0||ny<0||nx+ny>n)continue;
      int k3=A[i]+B[i]+C[i]-k1-k2;
      f[i][nx][ny]=min(f[i][nx][ny], f[i-1][j][k]+(abs(A[i]-k1)+abs(B[i]-k2)+abs(C[i]-k3))/2);
    }
  }

  int ans=inf;
  for(int i=0; i<=6; i++)
    ans=min(ans, f[i][E1][E2]);
  if(ans==inf)puts("impossible");
  else cout<<ans<<'\n';
  return 0;
}