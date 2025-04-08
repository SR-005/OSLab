#include<stdio.h>

int main()
{
    int i,j,k,count,frameno,pageno,fault=0;
    printf("Enter the No. of Frames: ");
    scanf("%d",&frameno);
    printf("Enter the No. of Pages: ");
    scanf("%d",&pageno);
    int frame[frameno],page[pageno];

    for(i=0;i<pageno;i++)
    {
        printf("Enter Reference String: ");
        scanf("%d",&page[i]);
    }
    for(i=0;i<frameno;i++)
    {
        frame[i]=-1;
    }

    for(i=0;i<pageno;i++)
    {
        printf("Reference String: %d\n",page[i]);
        count=0;
        for(j=0;j<frameno;j++)
        {
            if(frame[j]==page[i])
            {
                count=1;
                break;
            }
        }

        if(count==0)
        {
            frame[fault%frameno]=page[i];
            fault++;
        }
        for(k=0;k<frameno;k++)
        {
            printf("%d ",frame[k]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d",fault);
}