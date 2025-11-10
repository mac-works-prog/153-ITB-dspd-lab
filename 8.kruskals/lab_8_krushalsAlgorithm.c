// Pavan Bokare- IT - B - 153
/* AIM: Write a program to implement Kruskal’s Algorithm
   to find the Minimum Spanning Tree (MST) of a connected, weighted, and undirected graph. */

#include <stdio.h>

int parent[10];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int cost[10][10];
    int n, i, j, min, a, b, u, v, ne = 1, mincost = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // no edge
        }

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nMinimum Spanning Tree:\n");
    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("Edge %d: (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum Cost = %d\n", mincost);
    return 0;
}
