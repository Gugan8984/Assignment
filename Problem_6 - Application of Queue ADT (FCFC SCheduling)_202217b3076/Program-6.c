#include <stdio.h>

void main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Initialize arrays
    for(i = 0; i < 10; i++) {
        a[i] = 0;
        b[i] = 0;
        w[i] = 0;
        g[i] = 0;
    }

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter the burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Input arrival times
    printf("Enter the arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Calculate Gantt chart times
    g[0] = 0;
    for(i = 0; i < n; i++) {
        g[i + 1] = g[i] + b[i];
    }

    // Calculate waiting and turnaround times
    for(i = 0; i < n; i++) {
        w[i] = g[i] - a[i];
        t[i] = g[i + 1] - a[i];
        awt += w[i];
        att += t[i];
    }

    // Calculate averages
    awt = awt / n;
    att = att / n;

    // Output results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }

    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);
}
