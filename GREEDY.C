#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], heuristic[MAX], visited[MAX], n;

void greedy(int start, int goal) {
    int current = start;

    printf("Path: %d ", current);

    while (current != goal) {
        visited[current] = 1;
        int min = 999, next = -1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                if (heuristic[i] < min) {
                    min = heuristic[i];
                    next = i;
                }
            }
        }

        if (next == -1) {
            printf("\nNo path");
            return;
        }

        current = next;
        printf("%d ", current);
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter heuristic values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &heuristic[i]);

    greedy(0, n - 1);
    return 0;
}