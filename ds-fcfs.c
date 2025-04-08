#include<stdio.h>
#include<math.h>

int main()
{
    int size,head,i,currentreq,distance,scount;
    printf("Enter the No. of Disk Request: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the Initial Head Position: ");
    scanf("%d",&head);
    for(i=0;i<size;i++)
    {
        printf("Enter the Disk Request Tracks: ");
        scanf("%d",&arr[i]);
    }

    printf("REQUEST ARRAY: ");
    for(i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }

    printf("SEEK SEQUESNCE: ");
    for(i=0;i<size;i++)
    {
        currentreq=arr[i];
        distance=fabs(head-currentreq);
        scount=scount+distance;
        head=currentreq;
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Total No. of Seek Operations: %d\n",scount);
    
}

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size,space,copy,copyc,ini,seekcount,i,j,temp,direction,distance;
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
    copy=ini;

    //bubble sort the array
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

    //set up new with start and end boundaries
    new[0]=0;
    new[size+1]=space-1;
    for(i=0;i<size;i++)
    {
        new[i+1]=arr[i];
    }

    while(1)
    {
        printf("\n1. RIGHT\n2. LEFFT\n3. EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d",&direction);

        if(direction==1)
        {
            ini=copy;                         //reset initial
            seekcount=0;                     //reset seekcount if already used
            i=0;                             //reset i for counting
            while(new[i]<ini)               //count the number of disk request's larger than inital request
            {
                i++;
            }
            copyc=i;                        //save the count

            //find seekcount of larger requests
            for(i=copyc;i<size+2;i++)       
            {
                distance=abs(ini-new[i]);
                seekcount=seekcount+distance;
                ini=new[i];
                printf("%d ",new[i]);
            }
            
            //find seekcount of rest
            for(i=copyc-1;i>0;i--);
            {
                distance=abs(ini-new[i]);
                seekcount=seekcount+distance;
                ini=new[i];
                printf("%d ",new[i]);
            }

            printf("\nTotal Seek Count: %d",seekcount);
        }

        else if(direction==2)
        {
            seekcount=0;                             //reset seekcount if already used
            ini=copy;                                //reset initial
            i=0;
            while(new[i]<ini)               //count the number of disk request's larger than inital request
            {
                i++;
            }
            copyc=i;                        //save the count

            //find seekcount of smaller
            for(i=copyc-1;i>=0;i--);
            {
                distance=abs(ini-new[i]);
                seekcount=seekcount+distance;
                ini=new[i];
                printf("%d ",new[i]);
            }

            //find seek count of rest
            for(i=copyc;i<size+1;i++)
            {
                distance=abs(ini-new[i]);
                seekcount=seekcount+distance;
                ini=new[i];
                printf("%d ",new[i]);
            }

            printf("\nTotal Seek Count: %d",seekcount);
        }
        
        else if(direction==3)
        {
            printf("\nEXITING OPERATION....\n");
        }

        else
        {
            printf("\nINVALID OPERATION!!\n");
        }
    }
}