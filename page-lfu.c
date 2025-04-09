#include<stdio.h>
#include<stdlib.h>

int main()
{
    int frameno,pageno,i,j,k,count,fault=0,minfreq;
    printf("Enter the Number of Frames: ");
    scanf("%d",&frameno);
    printf("Enter the Total Number of Pages: ");
    scanf("%d",&pageno);

    int page[pageno],frame[frameno],freq[frameno];
    for(i=0;i<pageno;i++)
    {
        printf("Enter the Reference: ");
        scanf("%d",&page[i]);
    }

    for(i=0;i<frameno;i++)
    {
        frame[i]=-1;
        freq[i]=0;
    }

    for(i=0;i<pageno;i++)
    {
        printf("Reference String: %d\n",page[i]);
        count=0;
        for(j=0;j<frameno;j++)
        {
            if(frame[j]==page[i])
            {
                freq[j]++;
                count=1;
                break;
            }
        }

        if(count==0)
        {
            minfreq=0;
            for(j=1;j<frameno;j++)
            {
                if(freq[j]<freq[minfreq])
                {
                    minfreq=j;
                }
            }
            frame[minfreq]=page[i];
            freq[minfreq]=1;
            fault++;
        }
        for(k=0;k<frameno;k++)
        {
            printf("%d ",frame[k]);
        }
        printf("\n");
    }
    printf("Total Number of Fault: %d",fault);
}