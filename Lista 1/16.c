#include <stdio.h>
#define MAX_AIRPORTS 1000

int main() {
    int a, v, x, y, i, max_traffic;
    int airports[MAX_AIRPORTS] = {0};

    int test_case = 1;
    while (1) {
        scanf("%d %d", &a, &v);
        if (a == 0 && v == 0) break;
        max_traffic = 0;
        for (i = 0; i < v; i++) {
            scanf("%d %d", &x, &y);
            airports[x-1]++;
            airports[y-1]++;
        }
        for (i = 0; i < a; i++) {
            if (airports[i] > max_traffic) {
                max_traffic = airports[i];
            }
        }
        printf("Teste %d\n", test_case++);
        for (i = 0; i < a; i++) {
            if (airports[i] == max_traffic) {
                printf("%d ", i+1);
            }
        }
        printf("\n\n");
        for (i = 0; i < a; i++) {
            airports[i] = 0;
        }
    }
    return 0;
}
