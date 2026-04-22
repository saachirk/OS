#include <stdio.h>

#define MAX 10
#define TIME_QUANTUM 10.0   // base quantum

typedef struct {
    int pid;
    float weight;
    float remaining_time;
    int completed;
} Process;

int main() {
    int n;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    float total_weight = 0;

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter weight for Process %d: ", p[i].pid);
        scanf("%f", &p[i].weight);

        printf("Enter burst time for Process %d: ", p[i].pid);
        scanf("%f", &p[i].remaining_time);

        p[i].completed = 0;
        total_weight += p[i].weight;
    }

    printf("\n--- Scheduling Start ---\n");

    // Scheduling loop
    while (1) {
        int all_done = 1;

        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].remaining_time > 0) {
                all_done = 0;

                // Calculate proportional time slice
                float time_slice = (p[i].weight / total_weight) * TIME_QUANTUM;

                // Avoid overshooting remaining time
                if (time_slice > p[i].remaining_time) {
                    time_slice = p[i].remaining_time;
                }

                printf("Process %d runs for %.2f units\n", p[i].pid, time_slice);

                p[i].remaining_time -= time_slice;

                // Check completion
                if (p[i].remaining_time <= 0) {
                    p[i].completed = 1;
                    total_weight -= p[i].weight;

                    printf("Process %d completed\n", p[i].pid);
                }
            }
        }

        if (all_done)
            break;
    }

    printf("\n--- All Processes Completed ---\n");

    return 0;
}