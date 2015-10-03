#include<bits/stdc++.h>
using namespace std;
/*struct two
{
    int num,wei;
}a[1010];
bool cmpnum(two a,two b)
{
    return a.num<b.num;
}
bool cmpwei(two a,two b)
{
    return a.wei<b.wei;
}*/
int a[500010],c[500010],f[500010],px[5010];
void update(int s,int dt)
{
    while (s<=500)
    {
        c[s]=max(c[s],dt);
        s+=s & (-s);
    }
}
int getmax(int s)
{
    int ans=0;
    while (s)
    {
        ans=max(ans,c[s]);
        s-=s & (-s);
    }
    return ans;
}
int main()
{
    int n,t;scanf("%d%d",&n,&t);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        for (int j=1;j<=3000;j++) a[i+j*n]=a[i];
    }
    f[1]=1;update(a[1],1);
    for (int i=2;i<=3000*n;i++)
    {
        f[i]=getmax(a[i])+1;
        update(a[i],f[i]);
    }
    for (int i=1;i<=3000;i++)
    {
        px[i]=px[i-1];
        for (int j=(i-1)*n+1;j<=i*n;j++) px[i]=max(px[i],f[j]);
    }
    if (t<=3000) printf("%d\n",px[t]);else printf("%d\n",px[3000]+(px[3000]-px[2999])*(t-3000));
}
