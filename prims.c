#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Maximum 1000
#define INF 1000000

int n, m;
int dist[Maximum];
bool visited[Maximum];
int graph[Maximum][Maximum];

void prim() {
    int i, j;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[0] = 0;

    for (i = 0; i < n; i++) {
        int min_dist = INF, min_index;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }

        visited[min_index] = true;
        for (j = 0; j < n; j++) {
            if (!visited[j] && graph[min_index][j] != INF && graph[min_index][j] < dist[j]) {
                dist[j] = graph[min_index][j];
            }
        }
    }
}

int main() {
    int i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
    for (i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a][b] = w;
    }
    prim();
    int total_weight = 0;
    for (i = 0; i < n; i++) {
        total_weight += dist[i];
    }
    printf("Total weight: %d\n", total_weight);
    return 0;
}
