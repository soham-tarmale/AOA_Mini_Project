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

/* Prim's algorithm from vertex 'start'. Returns total cost. */
int prim(int start, int show) {
    int key[MAX], parent[MAX], visited[MAX];
    int total = 0, count = 0;

    /* Step 2: initialize */
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }
    key[start] = 0;

    /* Step 3: repeat n times */
    for (int k = 0; k < n; k++) {
        int u = -1, min = INF;
        for (int i = 0; i < n; i++)
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }

        if (u == -1) break;   /* no more reachable buildings */

        visited[u] = 1;
        count++;
        total += key[u];
        if (show) printf("Selected: %s\n", names[u]);

        /* Step 4: update neighbours */
        for (int v = 0; v < n; v++)
            if (cost[u][v] != 0 && !visited[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
    }

    /* Step 5: print MST */
    if (show) {
        printf("\nMST connections:\n");
        for (int i = 0; i < n; i++)
            if (parent[i] != -1 && visited[i])
                printf("%s - %s : %d\n", names[parent[i]], names[i], cost[parent[i]][i]);
        printf("Total cost = %d\n", total);
    }

    /* Step 6: validate */
    if (count < n) {
        printf("WARNING: Graph is disconnected! Not all buildings are connected.\n");
    }
    return total;
}

void runPrim() {
    int s;
    for (int i = 0; i < n; i++) printf("%d. %s\n", i + 1, names[i]);
    printf("Start from building number: ");
    scanf("%d", &s);
    prim(s - 1, 1);
}
