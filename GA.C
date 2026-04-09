#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 6
#define GENERATIONS 10
#define MUTATION_RATE 0.1

// Fitness function: f(x) = x^2
int fitness(int x) {
    return x * x;
}

// Generate random number
int randRange(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Selection (tournament)
int selectParent(int population[]) {
    int i = rand() % POP_SIZE;
    int j = rand() % POP_SIZE;

    if (fitness(population[i]) > fitness(population[j]))
        return population[i];
    else
        return population[j];
}

// Crossover
int crossover(int p1, int p2) {
    // simple average crossover
    return (p1 + p2) / 2;
}

// Mutation
int mutate(int x) {
    if ((float)rand() / RAND_MAX < MUTATION_RATE) {
        x += randRange(-2, 2);
    }
    return x;
}

int main() {
    int population[POP_SIZE];

    srand(time(0));

    // Initialize population
    for (int i = 0; i < POP_SIZE; i++) {
        population[i] = randRange(0, 10);
    }

    // Evolution
    for (int gen = 0; gen < GENERATIONS; gen++) {
        printf("Generation %d: ", gen);

        for (int i = 0; i < POP_SIZE; i++) {
            printf("%d ", population[i]);
        }
        printf("\n");

        int newPop[POP_SIZE];

        for (int i = 0; i < POP_SIZE; i++) {
            int p1 = selectParent(population);
            int p2 = selectParent(population);

            int child = crossover(p1, p2);
            child = mutate(child);

            newPop[i] = child;
        }

        // Replace old population
        for (int i = 0; i < POP_SIZE; i++) {
            population[i] = newPop[i];
        }
    }

    // Find best solution
    int best = population[0];
    for (int i = 1; i < POP_SIZE; i++) {
        if (fitness(population[i]) > fitness(best)) {
            best = population[i];
        }
    }

    printf("\nBest solution: %d\n", best);
    printf("Best fitness: %d\n", fitness(best));

    return 0;
}