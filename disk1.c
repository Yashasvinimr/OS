#include <stdio.h>
#include <math.h>


void FCFS(int arr[],int head, int n)
{
    int seek_count = 0;
      int cur_track, distance;

    for(int i=0;i<n;i++)
       {
        cur_track = arr[i];
        distance = fabs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }

    printf("Total number of seek operations: %d\n",seek_count);
    printf("Seek Sequence is\n");

      for (int i = 0; i < n; i++) {
        printf("%d\n",arr[i]);
    }
}
void CSCAN(int arr[],int head, int n, int range)
{
    int headm=0,i,dir,temp,seek_count=0;
    printf("Enter the direction, upward/right=1, downward/left=-1");
    scanf("%d",&dir);
    if(dir==1)
    {
        for(i=0;i<n;i++)
        {
            if(arr[i]<head)
            {
                seek_count++;
                continue;
            }
            else if(i==seek_count)
                headm=headm+(arr[i]-head);
            else
                headm=headm+(arr[i]-arr[i-1]);
        }
        headm=headm+(range-arr[i-1]);
        for(i=seek_count-1;i>0;i--)
        {
            headm+=(arr[i]-arr[i-1]);
        }
        headm+=(arr[i]-0);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(arr[i]>head)
            break;
            else
            seek_count++;
        }
        headm+=(head-arr[seek_count-1]);
        for(i=seek_count-1;i>0;i--)
        {
            headm+=(arr[i]-arr[i-1]);
        }
        headm+=(arr[0]-0);
        for(i=seek_count;i<n-1;i++)
        {
            headm+=(arr[i+1]-arr[i]);
        }
        headm=headm+(range-arr[i]);

    }
    printf("CSCAN-Total head movement=%d",headm);
     printf("Seek Sequence is\n");

          for (int i = 0; i < n; i++) {
            printf("%d\n",arr[i]);
        }
}
void SCAN(int arr[],int head, int n, int range)
{
int headm=0,i,dir,temp,cnt=0;
printf("Enter the direction, upward/right=1, downward/left=-1");
scanf("%d",&dir);
if(dir==1)
{
for(i=0;i<n;i++)
{
if(arr[i]<head)
{
cnt++;
continue;
}
else if(i==cnt)
headm=headm+(arr[i]-head);
else
headm=headm+(arr[i]-arr[i-1]);
}
headm=headm+(range-arr[i-1]);
headm+=(range-arr[cnt-1]);
for(i=cnt-1;i>0;i--)
{
headm+=(arr[i]-arr[i-1]);
}
}
else
{
for(i=0;i<n;i++)
{
if(arr[i]>head)
break;
else
cnt++;
}
headm+=(head-arr[cnt-1]);
for(i=cnt-1;i>0;i--)
{
headm+=(arr[i]-arr[i-1]);
}
headm+=(arr[0]-0);
headm+=(arr[cnt]-0);
for(i=cnt;i<n-1;i++)
{
headm+=(arr[i+1]-arr[i]);
}
}
printf("SCAN-Total head movement=%d",headm);
printf("Seek Sequence is\n");

          for (int i = 0; i < n; i++) {
            printf("%d\n",arr[i]);
        }

}
int main()
{
    int arr[30], head, ch, size, move,n,i,range ;
    printf("1.FCFS 2.SCAN 3.C-Scan\n");
    scanf("%d",&ch);
    printf("Enter the number of disks:\n");
    scanf("%d",&n);
    printf("Enter the sequence:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the head:\n");
    scanf("%d",&head);
    switch(ch)
    {
        case 1:FCFS(arr,head,n);
                break;
        case 2:printf("Enter the range:\n");
                scanf("%d", &range);
                CSCAN(arr,head,n,range);
                break;
        case 3:printf("Enter the range:\n");
                scanf("%d", &range);
                SCAN(arr, head,n,range);
                break;
        case 4:exit(0);
        break;
        default:("Invalid choice");
                break;

    }


    return 0;
}
