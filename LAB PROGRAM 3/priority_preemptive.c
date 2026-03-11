#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];
    int remaining_bt[n];

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
                                                                                                                                                                                                                                                                                                        
        printf("Enter PID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time (AT): ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time (BT): ");
        scanf("%d", &bt[i]);

        printf("Enter Priority: ");
        scanf("%d", &pr[i]);

        remaining_bt[i] = bt[i];
        rt[i] = -1; // response time not assigned yet
    }

    int completed = 0, time = 0;

    while(completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && remaining_bt[i] > 0) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {

            if(rt[idx] == -1) {
                rt[idx] = time - at[idx]; // first execution
            }

            remaining_bt[idx]--;
            time++;

            if(remaining_bt[idx] == 0) {
                ct[idx] = time;
                completed++;

                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
            }

        } else {
            time++; // CPU idle
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}