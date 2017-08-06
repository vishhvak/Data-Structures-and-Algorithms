#include<stdio.h>
#include<math.h>

int sender(int b[10],int k)
{
    int checksum,sum=0,i;
    printf("\n****SENDER****\n");
    for(i=0;i<k;i++)
        sum+=b[i];
    printf("SUM IS: %d",sum);
    checksum=~sum;//complement operator
    printf("\nSENDER's CHECKSUM IS:%d",checksum);
    return checksum;
}

int receiver(int c[10],int k,int scheck)
{
    int checksum,sum=0,i;
    printf("\n\n****RECEIVER****\n");
    for(i=0;i<k;i++)
        sum += c[i];
    printf(" RECEIVER SUM IS:%d",sum);
    sum=sum+scheck;
    checksum=~sum;
    printf("\nRECEIVER's CHECKSUM IS:%d",checksum);
    return checksum;
}

int main()
{
    int a[10],b[10],i,m,scheck,rcheck;
    printf("\nENTER NUMBER OF BITS:");
    scanf("%d",&m);
    printf("\nENTER THE DATA TO BE TRANSMITTED:");
    for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    scheck=sender(a,m);
    printf("\n\nENTER THE RECIEVED DATA:");
    for(i=0;i<m;i++)
        scanf("%d",&b[i]);
    rcheck=receiver(b,m,scheck);
    if(rcheck==0)
        printf("\n\nNO ERROR IN TRANSMISSION\n\n");
    else
        printf("\n\nERROR DETECTED\n");
    return 0;
}
