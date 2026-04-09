#include <stdio.h>
#include <math.h>

int minimax(int depth, int nodeIndex, int isMax, int scores[], int height) {
    if (depth == height)
        return scores[nodeIndex];

    if (isMax)
        return fmax(
            minimax(depth + 1, nodeIndex * 2, 0, scores, height),
            minimax(depth + 1, nodeIndex * 2 + 1, 0, scores, height)
        );
    else
        return fmin(
            minimax(depth + 1, nodeIndex * 2, 1, scores, height),
            minimax(depth + 1, nodeIndex * 2 + 1, 1, scores, height)
        );
}

int main() {
    int scores[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = sizeof(scores)/sizeof(scores[0]);
    int height = log2(n);

    printf("Optimal value: %d\n", minimax(0, 0, 1, scores, height));
    return 0;
}