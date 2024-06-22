#include<stdio.h>
struct process
{
    int ID,AT,BT,CT,TAT,WT;
};

struct process bubble(struct process a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j].AT>a[j+1].AT)
            {
                struct process temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

        }
    }
}

int main()
{
    int n;
    float ATAT=0,AWT=0;
    printf("enter no of processes\t");
    scanf("%d",&n);

    struct process P[n];

    printf("enter ID, AT, BT OF PROCESSES \n");
    for(int i=0;i<n;i++)
    {
        printf("for process %d\n",i);
        scanf("%d %d %d",&P[i].ID,&P[i].AT,&P[i].BT);
    }
    bubble(P,n);
    P[0].CT=P[0].AT+P[0].BT;
    int time=P[0].CT;
    P[0].TAT=P[0].CT-P[0].AT;
    P[0].WT=P[0].TAT-P[0].BT;
    for(int i=1;i<n;i++)
    {
        if(time<P[i].AT)
        {
            time=P[i].AT;
        }
        time+=P[i].BT;
        P[i].CT=time;
        P[i].TAT=P[i].CT-P[i].AT;
        P[i].WT=P[i].TAT-P[i].BT;
    }
     for(int i=0;i<n;i++)
    {
        ATAT+=P[i].TAT;
        AWT+=P[i].WT;
    }
    ATAT=ATAT/n;
    AWT=AWT/n;
     printf("procid\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  \t%d\t%d\t%d\t%d\t%d\n",P[i].ID,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
    }
    printf("average TAT=%.2f\naverage wt=%.2f\n",ATAT,AWT);

}