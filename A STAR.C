#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX], heuristic[MAX], visited[MAX], n;

void aStar(int start, int goal) {
    int current = start;

    printf("Path: %d ", current);

    while (current != goal) {
        visited[current] = 1;
        int min = 999, next = -1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                int cost = graph[current][i] + heuristic[i];
                if (cost < min) {
                    min = cost;
                    next = i;
                }
            }
        }

        if (next == -1) {
            printf("\nNo path found");
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

    aStar(0, n - 1);
    return 0;
}