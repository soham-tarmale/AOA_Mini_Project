/* University Campus Network Planner using Prim's Algorithm (simple version) */
#include <stdio.h>

#define MAX 20
#define INF 9999

char names[MAX][30];
int cost[MAX][MAX];   /* 0 means no direct connection */
int n = 0;

void addBuildings() {
    printf("How many buildings? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Name of building %d: ", i + 1);
        scanf("%s", names[i]);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = 0;
}

void addConnection() {
    int a, b, w;
    for (int i = 0; i < n; i++) printf("%d. %s\n", i + 1, names[i]);
    printf("Enter building 1, building 2 and cost: ");
    scanf("%d %d %d", &a, &b, &w);
    a--; b--;
    cost[a][b] = w;
    cost[b][a] = w;   /* undirected graph */
}
