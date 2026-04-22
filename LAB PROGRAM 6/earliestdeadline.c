#include <stdio.h>

#define MAX 10

// GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n, i, time;
    int C[MAX], D[MAX], T[MAX], id[MAX];
    int remaining[MAX], next_arrival[MAX], deadline[MAX];

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        id[i] = i + 1;

        printf("Enter execution time C%d: ", i + 1);
        scanf("%d", &C[i]);

        printf("Enter deadline D%d: ", i + 1);
        scanf("%d", &D[i]);

        printf("Enter period T%d: ", i + 1);
        scanf("%d", &T[i]);

        remaining[i] = 0;
        next_arrival[i] = 0;
        deadline[i] = 0;
    }

    // Step 1: CPU Utilization
    float U = 0;
    for (i = 0; i < n; i++) {
        U += (float)C[i] / D[i];
    }

    printf("\nCPU Utilization: %.3f\n", U);

    // Step 2: Feasibility Check
    if (U > 1)
        printf("Scheduling not feasible (deadlines may be missed)\n");
    else
        printf("Scheduling feasible\n");

    // Compute Hyperperiod (LCM of periods)
    int hyperperiod = T[0];
    for (i = 1; i < n; i++) {
        hyperperiod = lcm(hyperperiod, T[i]);
    }

    printf("Hyperperiod (LCM): %d\n", hyperperiod);

    // EDF Scheduling Loop
    printf("\nScheduling Timeline:\n");

    for (time = 0; time < hyperperiod; time++) {

        // Step: Process arrivals
        for (i = 0; i < n; i++) {
            if (time == next_arrival[i]) {
                remaining[i] = C[i];
                deadline[i] = time + D[i];   // absolute deadline
                next_arrival[i] += T[i];
            }
        }

        // Step: Find process with earliest deadline
        int selected = -1;
        int min_deadline = 100000;

        for (i = 0; i < n; i++) {
            if (remaining[i] > 0 && deadline[i] < min_deadline) {
                min_deadline = deadline[i];
                selected = i;
            }
        }

        // Execute
        if (selected != -1) {
            printf("Time %d: P%d\n", time, id[selected]);
            remaining[selected]--;

            if (remaining[selected] == 0) {
                // completed
            }
        } else {
            printf("Time %d: Idle\n", time);
        }
    }

    return 0;
}