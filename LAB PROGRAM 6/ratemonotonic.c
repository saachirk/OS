
#include <stdio.h>
#include <math.h>

#define MAX 10

// GCD function
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM function
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n, i, j, time;
    int C[MAX], T[MAX], id[MAX];
    int remaining[MAX], next_arrival[MAX];

    // Input
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        id[i] = i + 1;

        printf("Enter execution time C%d: ", i + 1);
        scanf("%d", &C[i]);

        printf("Enter period T%d: ", i + 1);
        scanf("%d", &T[i]);

        remaining[i] = 0;
        next_arrival[i] = 0;
    }

    // Step 1: CPU Utilization
    float U = 0;
    for (i = 0; i < n; i++) {
        U += (float)C[i] / T[i];
    }
    printf("\nCPU Utilization: %.3f\n", U);

    // Step 2: RMS Bound
    float bound = n * (pow(2, 1.0/n) - 1);
    printf("RMS Bound: %.3f\n", bound);

    // Step 3: Schedulability
    if (U <= bound)
        printf("Schedulable using RMS\n");
    else
        printf("Not guaranteed schedulable\n");

    // Step 4: Sort by period (priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (T[i] > T[j]) {
                int temp;

                temp = T[i]; T[i] = T[j]; T[j] = temp;
                temp = C[i]; C[i] = C[j]; C[j] = temp;
                temp = id[i]; id[i] = id[j]; id[j] = temp;
            }
        }
    }

    printf("\nPriority Order (High → Low): ");
    for (i = 0; i < n; i++) {
        printf("T%d ", id[i]);
    }

    // Compute Hyperperiod (LCM of all T)
    int hyperperiod = T[0];
    for (i = 1; i < n; i++) {
        hyperperiod = lcm(hyperperiod, T[i]);
    }

    printf("\nHyperperiod (LCM): %d\n", hyperperiod);

    // Step 5: Scheduling Loop
    printf("\nScheduling Timeline:\n");

    for (time = 0; time < hyperperiod; time++) {

        // Check arrivals
        for (i = 0; i < n; i++) {
            if (time == next_arrival[i]) {
                remaining[i] = C[i];
                next_arrival[i] += T[i];
            }
        }

        // Select highest priority READY task
        int selected = -1;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                selected = i;
                break; // highest priority
            }
        }

        // Execute
        if (selected != -1) {
            printf("Time %d: T%d\n", time, id[selected]);
            remaining[selected]--;
        } else {
            printf("Time %d: Idle\n", time);
        }
    }

    return 0;
}
