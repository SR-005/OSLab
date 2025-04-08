#include<stdio.h>

int main()
{
    int i,j,k,pageno,frameno,current,count,free,fault=0,farthest,findex;
    printf("Enter the Number of Frames: ");
    scanf("%d",&frameno);
    printf("Enter the Total Number of Pages: ");
    scanf("%d",&pageno);
    int page[pageno],frame[frameno];

    for(i=0;i<pageno;i++)
    {
        printf("Enter the Reference String: ");
        scanf("%d",&page[i]);
    }
    for(i=0;i<frameno;i++)
    {
        frame[i]=-1;
    }

    for(i=0;i<pageno;i++)
    {
        printf("Reference String: %d\n",page[i]);
        current=page[i];
        count=0;

        for(j=0;j<frameno;j++)
        {
            if(frame[j]==current)
            {
                count=1;
                break;
            }
        }

        if(count==0)
        {
            free=0;
            for(j=0;j<frameno;j++)
            {
                if(frame[j]==-1)
                {
                    frame[j]=current;
                    free=1;
                    break;
                }
            }

            if(free==0)
            {
                farthest=-1,findex=-1;
                for(j=0;j<frameno;j++)
                {
                    for(k=i+1;k<pageno;k++)
                    {
                        if(page[k]==frame[j])
                        {
                            break;
                        }
                    }

                    if(k>farthest)
                    {
                        farthest=k;
                        findex=j;
                    }
                }
                frame[findex]=current;
            }
            fault++;
        }
        for(k=0;k<frameno;k++)
        {
            printf("%d ",frame[k]);
        }
        printf("\n");
    }
    printf("Total Number of Page Faults: %d",fault);
}
