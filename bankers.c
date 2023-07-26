
#include <stdio.h>
void algo(int alloc[20][20],int max[20][20], int avail[20], int n, int m)
{
    int i,j, k;
    int fin[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		fin[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (fin[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					fin[i] = 1;
				}
			}
		}
	}

	int flag = 1;

	for(int i=0;i<n;i++)
	{
	if(fin[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
	}

	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}
}

int main()
{

	int n, m, i, j, k,t, ch, alloc[20][20],  max[20][20], add[20];
	int avail[20];
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    printf("Enter the number of resources:\n");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        printf("Enter the allocated resources for each process P%d:\n",i);
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&alloc[i][j]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the max resources for each process P%d:\n",i);
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&max[i][j]);
            }
        }
    }
    printf("Enter the available resources:\n");
    for(j=0;j<m;j++)
    {
        scanf("%d", &avail[j]);
    }
    algo(alloc, max, avail,n, m);
    printf("Does any process want to request for additional resources 1 for yes 0 for no?\n");
    scanf("%d",&ch);
     if(ch==1)
    {
        printf("Enter the process number for which there is an additional request");
        scanf("%d",&t);
        printf("Enter the number of instances required for each resource");
        for(i=0;i<m;i++)
        {
            scanf("%d",&add[i]);
        }
        for(i=0;i<m;i++)
        {
            alloc[t][i]+=add[i];
        }
        if(max[t][0]<alloc[t][0]||max[t][1]<alloc[t][1]||max[t][2]<alloc[t][2])
            printf("It is not a valid request");
        else
        {

            for(i=0;i<m;i++)
        {
            avail[i]-=add[i];
        }
         algo(alloc, max, avail,n, m);
        }
    }
    else
         algo(alloc, max, avail,n, m);


	return (0);

}



