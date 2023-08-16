
#define MAX_REQUESTS 100

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int absDiff(int a, int b) {
    return (a > b) ? a - b : b - a;
}

void sstf(int requests[], int n, int start) {
    int totalSeek = 0;
    int current = start;
    int visited[MAX_REQUESTS] = {0};

    printf("SSTF Disk Scheduling:\n");

    for (int i = 0; i < n; i++) {
        int minDist = __INT_MAX__;
        int nextIndex = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = absDiff(current, requests[j]);
                if (distance < minDist) {
                    minDist = distance;
                    nextIndex = j;
                }
            }
        }

        visited[nextIndex] = 1;
        totalSeek += minDist;
        printf("Move from %d to %d\n", current, requests[nextIndex]);
        current = requests[nextIndex];
    }

    printf("Total Seek Distance: %d\n", totalSeek);
}

void look(int requests[], int n, int start, int direction) {
    int totalSeek = 0;
    int current = start;

    sort(requests, n);

    printf("LOOK Disk Scheduling:\n");

    if (direction == 1) { // Upward direction
        for (int i = 0; i < n; i++) {
            if (requests[i] >= current) {
                totalSeek += absDiff(current, requests[i]);
                printf("Move from %d to %d\n", current, requests[i]);
                current = requests[i];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] < current) {
                totalSeek += absDiff(current, requests[i]);
                printf("Move from %d to %d\n", current, requests[i]);
                current = requests[i];
            }
        }
    } else { // Downward direction
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] <= current) {
                totalSeek += absDiff(current, requests[i]);
                printf("Move from %d to %d\n", current, requests[i]);
                current = requests[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (requests[i] > current) {
                totalSeek += absDiff(current, requests[i]);
                printf("Move from %d to %d\n", current, requests[i]);
                current = requests[i];
            }
        }
    }

    printf("Total Seek Distance: %d\n", totalSeek);
}

void cLook(int requests[], int n, int start) {
    int totalSeek = 0;
    int current = start;

    sort(requests, n);

    printf("C-LOOK Disk Scheduling:\n");

    int index = 0;
    while (index < n && requests[index] <= current)
        index++;

    for (int i = index; i < n; i++) {
        totalSeek += absDiff(current, requests[i]);
        printf("Move from %d to %d\n", current, requests[i]);
        current = requests[i];
    }

    for (int i = 0; i < index; i++) {
        totalSeek += absDiff(current, requests[i]);
        printf("Move from %d to %d\n", current, requests[i]);
        current = requests[i];
    }

    printf("Total Seek Distance: %d\n", totalSeek);
}

int main() {
    int requests[MAX_REQUESTS];
    int n, start, direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    if (n > MAX_REQUESTS) {
        printf("Maximum number of requests exceeded.\n");
        return 1;
    }

    printf("Enter the requests: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter the starting position: ");
    scanf("%d", &start);

    printf("Enter the direction (1 for upward, 0 for downward): ");
    scanf("%d", &direction);

    int choice;
    printf("Choose Disk Scheduling Algorithm:\n");
    printf("1. SSTF\n2. LOOK\n3. C-LOOK\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sstf(requests, n, start);
            break;
        case 2:
            look(requests, n, start, direction);
            break;
        case 3:
            cLook(requests, n, start);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
