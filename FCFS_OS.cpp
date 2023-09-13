#include<stdio.h>

int wt[50],at[50],id[50],tt[50];

/*void sort(int at[],int bt[],int id[],int n)
{
int i,j,t,min=99999,ind;
for(i=0;i<n;i++)
{
    for(j=i;j<n;j++)
    {
        if(at[i]<min)
        {min=at[j];ind=j;}
    }
    t=at[i];at[i]=at[ind];at[ind]=t;
    t=bt[i];bt[i]=bt[ind];bt[ind]=t;
    t=id[i];id[i]=id[ind];id[ind]=t;
min=999999;
}
}*/

void fcfs(int bt[],int n,int wt[],int at[])
{
int i,j,t,min=99999,ind;
for(i=0;i<n;i++)
{
    for(j=i;j<n;j++)
    {
        if(at[j]<min)
        {min=at[j];ind=j;}
    }
    t=at[i];at[i]=at[ind];at[ind]=t;
    t=bt[i];bt[i]=bt[ind];bt[ind]=t;
    t=id[i];id[i]=id[ind];id[ind]=t;
min=999999;
}
t=0;
for(i=0;i<n;i++)
{
    for(j=0;j<i;j++)
        t+=bt[j];
    wt[i]=t-at[i];
    t=0;
}
for(i=0;i<n;i++)
tt[i]=wt[i]+bt[i];
printf("\nPro\tAT\tBT\tWT\tTT\n");
for(i=0;i<n;i++)
printf("\nP%d\t%d\t%d\t%d\t%d",id[i],at[i],bt[i],wt[i],tt[i]);
printf("\n");
}

int main()
{
    int n,i;
    printf("\nEnter the no. of processes : ");
    scanf("%d",&n);
    int bt[n];
    printf("\nEnter the burst time : ");
    for(i=0;i<n;i++){
    scanf("%d",&bt[i]);
    id[i]=i+1;
    }
    printf("\nEnter the arrival time : ");
    for(i=0;i<n;i++)
    scanf("%d",&at[i]);
    fcfs(bt,n,wt,at);
    return 0;
}