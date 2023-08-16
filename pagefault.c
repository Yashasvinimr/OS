#include <stdio.h>
#include <stdbool.h>


void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int findIndex(int arr[], int n, int element) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int findOptimal(int pages[], int n, int frames[], int start, int NUM_FRAMES) {
    int res = -1, farthest = start;
    for (int i = 0; i < NUM_FRAMES; i++) {
        int j;
        for (j = start; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void fifo(int pages[], int n, int NUM_FRAMES) {
    int frames[NUM_FRAMES];
    int frameIndex = 0;
    int pageFaults = 0;

    for (int i = 0; i < NUM_FRAMES; i++)
        frames[i] = -1;

    printf("FIFO Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        if (findIndex(frames, NUM_FRAMES, page) == -1) {
            frames[frameIndex] = page;
            frameIndex = (frameIndex + 1) % NUM_FRAMES;
            pageFaults++;
        }

        printf("Page %d -> ", page);
        printFrames(frames, NUM_FRAMES);
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

void lru(int pages[], int n, int NUM_FRAMES) {
    int frames[NUM_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < NUM_FRAMES; i++)
        frames[i] = -1;

    printf("LRU Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        if (findIndex(frames, NUM_FRAMES, page) == -1) {
            int emptyIndex = findIndex(frames, NUM_FRAMES, -1);
            if (emptyIndex != -1) {
                frames[emptyIndex] = page;
            } else {
                int lruIndex = i;
                for (int j = 0; j < NUM_FRAMES; j++) {
                    if (findIndex(pages, n, frames[j]) < lruIndex) {
                        lruIndex = findIndex(pages, n, frames[j]);
                    }
                }
                frames[lruIndex] = page;
            }
            pageFaults++;
        }

        printf("Page %d -> ", page);
        printFrames(frames, NUM_FRAMES);
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

void optimal(int pages[], int n, int NUM_FRAMES) {
    int frames[NUM_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < NUM_FRAMES; i++)
        frames[i] = -1;

    printf("Optimal Page Replacement:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        if (findIndex(frames, NUM_FRAMES, page) == -1) {
            int emptyIndex = findIndex(frames, NUM_FRAMES, -1);
            if (emptyIndex != -1) {
                frames[emptyIndex] = page;
            } else {
                int optimalIndex = findOptimal(pages, n, frames, i + 1, NUM_FRAMES);
                frames[optimalIndex] = page;
            }
            pageFaults++;
        }

        printf("Page %d -> ", page);
        printFrames(frames, NUM_FRAMES);
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[50],NUM_PAGES, NUM_FRAMES, i;

    int choice;
    printf("Enter the number of pages:\n");
    scanf("%d", &NUM_PAGES);
    printf("Enter the number of frames:\n");
    scanf("%d",&NUM_FRAMES);
    printf("Enter the pages:\n");
    for(i=0;i<NUM_PAGES;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("Choose Page Replacement Algorithm:\n");
    printf("1. FIFO\n2. LRU\n3. Optimal\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fifo(pages, NUM_PAGES, NUM_FRAMES);
            break;
        case 2:
            lru(pages, NUM_PAGES, NUM_FRAMES);
            break;
        case 3:
            optimal(pages, NUM_PAGES, NUM_FRAMES);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
