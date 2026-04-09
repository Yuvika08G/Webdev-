#include <stdio.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX], cost[MAX], visited[MAX], n;

void ucs(int start) {
    for (int i = 0; i < n; i++)
        cost[i] = INT_MAX;

    cost[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u;

        for (int i = 0; i < n; i++)
            if (!visited[i] && cost[i] <= min) {
                min = cost[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] &&
                cost[u] + graph[u][v] < cost[v]) {
                cost[v] = cost[u] + graph[u][v];
            }
    }

    printf("Costs:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", cost[i]);
}

int main() {
    printf("Enter nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    ucs(0);
    return 0;
}