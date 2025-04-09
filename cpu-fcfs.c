#include<stdio.h>
int main()
{
    int i,num,burst;
    float avgwaitt=0,avgtat=0;
    printf("Enter the Total Number of Process: ");
    scanf("%d",&num);
    int arrivalt[num],burstt[num],waitt[num],tatt[num],chart[num];
    chart[0]=0;             //gantt chart start's with 0
    for(i=0;i<num;i++)
    {
        printf("Enter the Arrival Time of P%d: ",i+1);
        scanf("%d",&arrivalt[i]);
        printf("Enter the Burst Time of P%d: ",i+1);
        scanf("%d",&burstt[i]);

        burst=burst+burstt[i];                      //preparation of ending time of current process
        chart[i+1]=burst;                           //adding it to chart

        if(i==0)                                //if first iteration
        {
            waitt[i]=0;
        }
        else
        {
            waitt[i]=chart[i]-arrivalt[i];      //calculate waiting time
        }

        tatt[i]=waitt[i]+burstt[i];         //turnaroundtime
    }

    //Display all Values- Arrival,Burst,Waitinh,TurnAround
    printf("\n-----------------------------\n");
    printf("PI\tAT\tBT\tWT\tTAT");
    printf("\n-----------------------------\n");
    for(i=0;i<num;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,arrivalt[i],burstt[i],waitt[i],tatt[i]);
    }
    //DISPLAY GANTT CHART 
    printf("\nGANTT CHART");
    printf("\n-----------------------------\n");
    //Print Process Names
    for(i=0;i<num;i++)
    {
        printf("P%d\t",i+1);
    }
    printf("\n-----------------------------\n");
    //Print Gantt Chart Values
    for(i=0;i<num;i++)
    {
        printf("\t%d",chart[i+1]);
    }

    //CALCULATE AVERAGE VALUES 
    for(i=0;i<num;i++)
    {
        avgwaitt=avgwaitt+waitt[i];             //adding the sum off all values and storing it in same variable
        avgtat=avgtat+tatt[i];
    }

    avgwaitt=avgwaitt/num;                      //average=sum/total
    avgtat=avgtat/num;
    printf("\nAverage Waiting Time: %f",avgwaitt);
    printf("\nAverage Waiting Time: %f",avgtat);
}
