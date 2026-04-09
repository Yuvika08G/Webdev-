#include <stdio.h>

#define N 4
#define COLORS 3

int graph[N][N] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
};

int solution[N];

int isSafe(int v, int c) {
    for (int i = 0; i < N; i++) {
        if (graph[v][i] && solution[i] == c)
            return 0;
    }
    return 1;
}

int solveCSP(int v) {
    if (v == N)
        return 1;

    for (int c = 1; c <= COLORS; c++) {
        if (isSafe(v, c)) {
            solution[v] = c;

            if (solveCSP(v + 1))
                return 1;

            solution[v] = 0;
        }
    }
    return 0;
}

int main() {
    if (solveCSP(0)) {
        printf("Solution:\n");
        for (int i = 0; i < N; i++)
            printf("Var %d -> %d\n", i, solution[i]);
    } else {
        printf("No solution\n");
    }

    return 0;
}