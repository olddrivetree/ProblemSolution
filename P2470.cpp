#include <bits/stdc++.h>
using namespace std;
int f[111][111][2];
char s[111];
int n;
bool check(int l, int r){
  int Mid=l+r>>1;
  for(int i=1; i<=Mid-l+1; i++)
    if(s[l+i-1]!=s[Mid+i])return false;
  return true;
}
int main(){
  scanf("%s", s+1);
  n=strlen(s+1);
  for(int Len=1; Len<=n; Len++){
    for(int i=1; i+Len-1<=n; i++){
      int j=i+Len-1;
      f[i][j][0]=f[i][j][1]=j-i+1;
      for(int k=i; k<j; k++)
        f[i][j][1]=min(f[i][j][1], min(f[i][k][0], f[i][k][1])+1+min(f[k+1][j][1], f[k+1][j][0])),
        f[i][j][0]=min(f[i][j][0], f[i][k][0]+j-k);
      if((j-i+1)%2==0&&check(i, j)) f[i][j][0]=f[i][i+j>>1][0]+1;
    }
  }
  cout<<min(f[1][n][0], f[1][n][1])<<'\n';
  return 0;
}