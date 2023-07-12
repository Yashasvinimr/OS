#include <stdio.h>

#define MAX_QUEUE_SIZE 100


typedef struct
{
    int processID;
    int arrivalTime;
    int burstTime;
    int priority;
} Process;


void executeProcess(Process process)
{
    printf("Executing Process %d\n", process.processID);
    for (int i = 1; i <= process.burstTime; i++)
    {
        printf("Process %d: %d/%d\n", process.processID, i, process.burstTime);
    }
    printf("Process %d executed\n", process.processID);
}

void scheduleFCFS(Process queue[], int size)
{
    for (int i = 0; i < size; i++)
    {
        executeProcess(queue[i]);
    }
}

int main()
{
    int numProcesses;
    Process processes[MAX_QUEUE_SIZE];
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    for (int i = 0; i < numProcesses; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("System(0)/User(1): ");
        scanf("%d", &processes[i].priority);
        processes[i].processID = i + 1;
    }
    Process systemQueue[MAX_QUEUE_SIZE];
    int systemQueueSize = 0;
    Process userQueue[MAX_QUEUE_SIZE];
    int userQueueSize = 0;

    for (int i = 0; i < numProcesses; i++)
    {
        if (processes[i].priority == 0)
        {
            systemQueue[systemQueueSize++] = processes[i];
        } else
        {
            userQueue[userQueueSize++] = processes[i];
        }
    }
    printf("System Queue:\n");
    scheduleFCFS(systemQueue, systemQueueSize);
    printf("User Queue:\n");
    scheduleFCFS(userQueue, userQueueSize);

    return 0;
}
