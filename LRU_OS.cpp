#include<stdio.h>
#include<string.h>
int stack[10];

void printst(int stack[],int n,int pos[])
{
    printf("\n( ");
    for(int i=0;i<n;i++)
    printf("%d ",stack[i]);
    printf(")\n ");

    for(int i=0;i<n;i++)
    printf("%d  ",pos[i]);
}

int check(int val,int stack[],int n)
{
    for(int j=0;j<n;j++)
    {
        if(stack[j]==val)
        return 0;
    }
    return 1;
}

int main()
{
    int n,st[50],i,j,ind;
    printf("\nEnter the no. of frames : ");
    scanf("%d",&n);
    int len=12,pos[n];
    printf("\nEnter the Refernce String : ");
    for(i=0;i<len;i++)
    scanf("%d",&st[i]);
    int pf=0,t,ind1;
    for(i=0;i<n;i++)
    stack[i]=st[i];
    pf=n;
    printst(stack,n,pos);
    for(i=n;i>=1;i--)
    pos[n-i]=i;
    for(i=n;i<len;i++)
    {
        if(check(st[i],stack,n))
        {
            for(j=0;j<n;j++)
            {
                if(pos[j]==n)
                ind=j;
            }
            for(j=0;j<n;j++)
            pos[j]=pos[j]+1;
            stack[ind]=st[i];pf++;pos[ind]=1;
            printst(stack,n,pos);
        }
        else
        {   
            for(j=0;j<n;j++)
            {
                if(stack[j]==st[i])
                {
                    ind=pos[j];
                    ind1=j;
                }
            }
            for(j=0;j<n;j++)
            {
                if(pos[j]<ind)
                pos[j]+=1;
            }
            pos[ind1]=1;
            printst(stack,n,pos);
        }
    }
    printf("\nPagr Fault = %d",pf);
    return 0;
}
//0 2 1 6 4 0 1 0 3 1 2 1 --8
//1 2 3 4 1 2 5 1 2 3 4 5 --10 