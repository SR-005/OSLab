#include<stdio.h>
//struct is easy for swapping this much data
struct process
{
    int id;
    int burstt;
    int waitt;
    int tatt;
};

int main()
{
    int i,j,num,burst=0;
    float avgwaitt,avgtat;
    printf("Enter the Total Number of Process: ");
    scanf("%d",&num);
    struct process p[num],temp;   //create temp for swapping purpose and p[num] : one for each process
    int chart[num+1];

    for(i=0;i<num;i++)                      //to prompt user for Burst Time and Store it in Struct because SHORTEST JOB FIRST is sorted based on BT
    {
        p[i].id=i+1;                    //give each process id
        printf("Enter the Burst Time of P%d: ",i+1);
        scanf("%d",&p[i].burstt);
    }

    //BUBBLE SORT 
    for(i=0;i<num;i++)
    {
        for(j=0;j<num-i-1;j++)
        {
            if(p[j].burstt>p[j+1].burstt)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    chart[0]=0;                     //first element for gantt chart is 0
    for(i=0;i<num;i++)
    {
        p[i].waitt=chart[i];        //waiting time will be the time last process ends in queue i.e, lastest data from chart
        chart[i+1]=chart[i]+p[i].burstt;    //next chart i.e, this process ending time will be already present value+burst time of this process
        p[i].tatt=p[i].waitt+p[i].burstt;   //turn around time will be waiting time+burst time
    }

    //PRINT ALL THE FIELDS
    printf("\n------------------------------\n");
    printf("PI\tBT\tWT\tTAT");
    printf("\n------------------------------\n");
    for(i=0;i<num;i++)
    {
        printf("P%d\t%d\t%d\t%d\n",p[i].id,p[i].burstt,p[i].waitt,p[i].tatt);
    }
    printf("\n------------------------------\n");


    //PRINT GANTT CHART
    printf("GANTT CHART");
    printf("\n------------------------------\n");
    for(i=0;i<num;i++)
    {
        printf("P%d\t",p[i].id);
    }
    printf("\n------------------------------\n");
    for(i=0;i<num;i++)
    {
        printf("\t%d",chart[i+1]);
    }

    //CALCULATE AVERAGE VALUES
    for(i=0;i<num;i++)
    {
        avgwaitt=avgwaitt+p[i].waitt;
        avgtat=avgtat+p[i].tatt;
    }

    printf("\n");
    printf("Average Waiting Time: %f\n",avgwaitt/num);
    printf("Average Turn Around Time: %f\n",avgtat/num);

}