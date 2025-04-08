#include<stdio.h>
#include<stdlib.h>

void main()
{
    int ini,space,size,i,j,seekcount,distance,temp,copyc,direction;
    printf("Enter the Disk Space: ");
    scanf("%d",&space);
    printf("Enter the Total Number of Disk Requests: ");
    scanf("%d",&size);
    int arr[size],new[size+2];
    for(i=0;i<size;i++)
    {
        printf("Enter the Disk Request's: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter the Initial Head Position: ");
    scanf("%d",&ini);

    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    new[0]=0;
    new[size+1]=space-1;
    for(i=0;i<size;i++)
    {
        new[i+1]=arr[i];
    }

    i=0;
    while(new[i]<ini)
    {
        i++;
    }
    copyc=i;

    do
    {
        distance=abs(ini+new[i]);
        seekcount=seekcount+distance;
        ini=new[i];
        printf("%d ",new[i]);
        i=(i+1)%(size+2);
    }
    while (i!=copyc);
    printf("Total SeekCount : %d",seekcount);
}
