#include <stdio.h>

typedef struct {
    int pid, bt, wt, tt;
} process;

int main() {
    int n, tq, time = 0, total_wt = 0, total_tt = 0;
    float avg_wt, avg_tt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process p[n];
    int remBT[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter the burst time for process-%d: : ", i + 1);
        scanf("%d", &p[i].bt);

        remBT[i] = p[i].bt;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int flag = 0;

    while(flag == 0) {
        flag = 1;

        for(int i = 0; i < n; i++) {
            if (remBT[i] > 0) {
                flag = 0;

                if(remBT[i] > tq) {
                    time += tq;
                    remBT[i] -= tq;
                } else {
                    time += remBT[i];
                    remBT[i] = 0;
                    p[i].tt = time;
                    p[i].wt = p[i].tt - p[i].bt;
                }
            }
        }
    }

    printf("Round Robin Scheduling\nPID\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tt);

        total_wt += p[i].wt;
        total_tt += p[i].tt;
    }

    avg_wt = (float)total_wt / n;
    avg_tt = (float)total_tt / n;

    printf("\n\nTotal Waiting time: %dms\n", total_wt);
    printf("Average Waiting time: %.2fms\n", avg_wt);

    printf("\n\nTotal turn-arround time: %dms\n", total_tt);
    printf("Average turn-arround time: %.2fms\n", avg_tt);

    return 0;
}
