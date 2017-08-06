#include<stdio.h>
#include<math.h>
int main()
{
    int a[20],b[20],c[20],d[20],i,k,m,f,n,j,r,p,x,y,z,ch,key,q,v,sum=0;
    printf("\n ENTER THE LENGTH OF DATA WORD :");
    scanf("%d",&k);
    printf("\n ENTER THE DATA WORD \n");
    for(i=1; i<=k; i++){
        scanf("%d",&a[i]);
    }
    m=1;
    while((k+m+1)>=pow(2,m)){
        m++;
    }
    printf("\n Value of m is : %d",m);
    n=k+m;
    j=1; r=0;
    for(i=1; i<=n; i++){
        p=pow(2,r);
        if(i==p){
            b[i]=0;
            r++;
        }
        else{
            b[i]=a[j];
            j++;
        }
    }
    printf("\n INTERMEDIATE CODE WORD IS \n");
    for(i=1; i<=n; i++)
        printf("%d",b[i]);
    p=0;
    for(i=1; i<=m; i++)
    {
        x=pow(2,p); r=1;
        for(j=x; j<=n; j=j+(x*2)){
            for(y=j; y<(j+x); y++){
                c[r]=b[y];
                r++;
            }
        }
        z=0;
        for(y=1; y<=(r-1); y++)
        {
            if(c[y]==1) z++;
        }
        if(z%2==0)
            b[x]=0;
        else
            b[x]=1;
        for(y=1; y<=20; y++)
            c[y]=0;
        p++;
    }
    printf("\n\n THE HAMMING CODE IS \n");
    for(i=n; i>=1; i--)
        printf("%d",b[i]);
    while(1){
        printf("\n\n PRESS 1 TO ALTER A BIT 0 to EXIT \n\n");
        scanf("%d",&ch);
        if(ch==1){
            printf("\n ENTER THE BIT YOU WANT TO CHANGE \n");
            scanf("%d",&key);
            key=n-key+1;
            for(i=1; i<=n; i++){
                if(i==key){
                    if(b[key]==1) b[key]=0;
                    else b[key]=1;
                    break;
                }
            }
            printf("\n THE NEW CODE IS \n\n");
            for(i=n; i>=1; i--)
                printf("%d",b[i]);
        }
        else
            break;
    }
    p=0; q=0;
    for(i=1; i<=m; i++)
    {
        x=pow(2,p); r=1;
        for(j=x; j<=n; j=j+(x*2)){
            for(y=j; y<(j+x); y++){
                c[r]=b[y];
                r++;
            }
        }
        z=0;
        for(y=1; y<=(r-1); y++)
        {
            if(c[y]==1) z++;
        }
        v=z%2;
        d[q]=v;
        sum=sum+(v*pow(2,q));
        q++;
        for(y=1; y<=20; y++)
            c[y]=0;
        p++;
    }
    if(sum==0)
        printf("\n\n NO ERROR FOUND....... \n\n");
    else
        printf("\n\n ERROR AT POSITION %d",n-sum+1);
    for(i=n;i>=1;i--)
    {
        if(i==sum)
        {
            if(b[i]==0) b[i]=1;
            else
                b[i]=0;
        }
    }
    printf("\n THE CORRECTED CODE IS \n\n");
    for(i=n; i>=1; i--)
        printf("%d",b[i]);
    printf("\n");
    return 0;
}
