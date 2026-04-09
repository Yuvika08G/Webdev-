#include <stdio.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX], n;

int DLS(int node, int goal, int depth) {
    if (node == goal)
        return 1;

    if (depth <= 0)
        return 0;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (DLS(i, goal, depth - 1))
                return 1;
        }
    }
    return 0;
}

void IDDFS(int start, int goal) {
    for (int depth = 0; depth < n; depth++) {
        if (DLS(start, goal, depth)) {
            printf("Goal found at depth %d\n", depth);
            return;
        }
    }
    printf("Goal not found\n");
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    IDDFS(0, n - 1);
    return 0;
}