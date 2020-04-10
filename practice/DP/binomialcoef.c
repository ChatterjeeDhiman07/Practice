#include<stdio.h>

int ncr(int n, int k)
{
    int c[n+1][k+1];
    int i,j;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(j==0||j==i)
                c[i][j]=1;
            else
            {
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
            
        }
    }
    return c[n][k];
}

int main()
{
    int a,b,res;
    printf("Enter a,b:\n");
    scanf("%d%d",&a,&b);

    res= (a>b)?ncr(a,b):0;

    if(res!=0)
        printf("%dC%d is %d\n",a,b,res);
    else
    {
        printf("Can't calculate\n");
    }
    
return 0;

}