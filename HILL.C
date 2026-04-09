#include <stdio.h>

#define MAX 10

int heuristic[MAX], n;

void hillClimb() {
    int current = 0;

    while (1) {
        int next = current;

        for (int i = 0; i < n; i++) {
            if (heuristic[i] < heuristic[next]) {
                next = i;
            }
        }

        if (next == current)
            break;

        current = next;
    }

    printf("Optimal node: %d\n", current);
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter heuristic values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &heuristic[i]);

    hillClimb();
    return 0;
}