//FIFO Page replacement
#include<stdio.h>
int main() {
    int i=0, j=0, n, f, k, avail, fcount = 0;
    int page[50], frame[10];
    printf("ENTER THE NUMBER OF PAGES: ");
    scanf("%d", &n);
    printf("\nENTER THE PAGE NUMBER: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }
    printf("\nENTER THE NUMBER OF FRAMES: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) 
        frame[i] = -1;
    printf("\nPage No.\tPage Frames\tHit/Miss\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t", page[i]);
        avail = 0;
        for(k = 0; k < f; k++) {
            if(frame[k] == page[i]) 
                avail = 1;
        }
        if(avail == 1) {
            printf("\t");
            for(k = 0; k < f; k++)
                printf("%d\t", frame[k]);
            printf("Hit\n");
        } 
        else {
            frame[j] = page[i];
            j = (j + 1) % f;
            fcount++;
            printf("\t");
            for(k = 0; k < f; k++) 
                printf("%d\t", frame[k]);
            printf("Miss\n");
        }
    }
    printf("\nPage Faults: %d\n", fcount);
    return 0;
}
