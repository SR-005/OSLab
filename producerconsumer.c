#include<stdlib.h>
#include<stdio.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return(++s);
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer Produces the Item %d",x);
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}


int main()
{
    int n;
    while(1)
    {
        printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
        printf("Enter your Choice: ");
        scanf("%d",&n);
        if(n==1)
        {
            if((mutex==1)&&(empty!=0))
            {
                producer();
            }
            else
            {
                printf("BUFFER IS FULL!!");
            }
        }
        else if(n==2)
        {
            if((mutex==1)&&(full!=0))
            {
                consumer();
            }
            else
            {
                printf("BUFFER IS EMPTY");
            }
        }
        else if(n==3)
        {
            exit(0);
            break;
        }
        else
        {
            printf("INVALID OPTION");
        }
    }    
}

