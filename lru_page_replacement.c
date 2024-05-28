//LRU
#include <stdio.h>
int main() {
    int n, i = 0, j = 0, f, c = 0, k = 0, c1 = 0, r = 0, t = 0;
    printf("Enter the no. of pages: ");
    scanf("%d", &n);
    int p[20], q[20], b[20], c2[20];
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Enter the no. of frames: ");
    scanf("%d", &f);
    for (i = 0; i < n; i++) {
        c1 = 0;
        for (j = 0; j < f; j++) {
            if (p[i] == q[j]) { // check if page p[i] is already present in any frame
                c1++;
                printf("%d (Hit)\t", p[i]);
                break;
            }
        }
        if (c1 == 0) { // page is not present in any frame, replace it
            printf("%d (Miss)\t", p[i]);
            c++;
            if (k < f) {
                q[k] = p[i]; // add page p[i] to frame at k index
                k++;
            } else {
                for (r = 0; r < f; r++) {
                    c2[r] = 0;
                    for (j = i - 1; j >= 0; j--) {
                        if (q[r] != p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for (r = 0; r < f; r++)
                    b[r] = c2[r];
                for (r = 0; r < f; r++) {
                    if (c2[r] == b[0])
                        q[r] = p[i];
                }
            }
        }
        // Display current state of frames after processing each page
        for (j = 0; j < k; j++)
            printf("%d ", q[j]);
        printf("\n");
    }
    printf("\nThe no. of page faults: %d\n", c);
    return 0;
}
