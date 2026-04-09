#include <stdio.h>
#include <limits.h>

int minimax(int depth, int nodeIndex, int isMax, int scores[], int height, int alpha, int beta) {
    if (depth == height)
        return scores[nodeIndex];

    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i, 0, scores, height, alpha, beta);
            if (val > best) best = val;
            if (best > alpha) alpha = best;
            if (beta <= alpha) break;
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int i = 0; i < 2; i++) {
            int val = minimax(depth + 1, nodeIndex * 2 + i, 1, scores, height, alpha, beta);
            if (val < best) best = val;
            if (best < beta) beta = best;
            if (beta <= alpha) break;
        }
        return best;
    }
}

int main() {
    int scores[] = {3, 5, 6, 9, 1, 2, 0, -1};
    int height = 3;

    printf("Optimal value: %d\n", minimax(0, 0, 1, scores, height, INT_MIN, INT_MAX));
    return 0;
}