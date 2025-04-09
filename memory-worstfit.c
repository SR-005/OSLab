#include<stdio.h>

int main()
{
    int memory[50],process[50],fragment[50],a[50],alloc[50]={0};
    int i,j,memoryno,processno,highest,temp,windex;

    //PROMPT MEMORY BLOCK
    printf("Enter the Total Number of Memory Blocks: ");
    scanf("%d",&memoryno);
    for(i=0;i<memoryno;i++)
    {
        printf("Enter the Memory Block %d: ", i+1);
        scanf("%d",&memory[i]);
    }

    //PROMPT PROCESS
    printf("Enter the Total Number of Process: ");
    scanf("%d",&processno);
    for(i=0;i<processno;i++)
    {
        printf("Enter the Size of Process %d: ", i+1);
        scanf("%d",&process[i]);
        a[i]=-1;
    }

    for(i=0;i<processno;i++)
    {
        highest=-1,windex=-1;
        for(j=0;j<memoryno;j++)
        {
            if(alloc[j]==0)
            {
                temp=memory[j]-process[i];              //find fragmentation
                if(temp>=0&&temp>highest)               //check of it is the highest one ye
                {   
                    highest=temp;                          //if yes then save it has highest and save it's index
                    windex=j;
                }
            }
            
        }

        if(windex!=-1)                                  //confirm that if any valid position is found or not, if found....
        {
            a[i]=windex;                                //save the index
            fragment[i]=highest;                        //make the fragmentation permenant
            alloc[windex]=1;                            //set the memory block as allocated
        }
        else
        {
            fragment[i]=-1;                             
        }
    }

    printf("\nProcess No\tProcess Size\tBlock Number\tBlock Size\tFragment");
    for(i=0;i<=processno;i++)
    {
        if(a[i]!=-1)                                        //check if allocation has been done for every process, if not then print that process has not been allocated
        {
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,process[i],a[i]+1,memory[a[i]],fragment[i]);
        }
        else
        {
            printf("P%d Not Allocated",i+1);
        }
    }
}