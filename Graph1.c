#include <stdio.h>

#define MAX_CITIES 200

void dfs(int city, int n, int isConnected[MAX_CITIES][MAX_CITIES], int visited[MAX_CITIES]) {
    visited[city] = 1;
    for (int neighbor = 0; neighbor < n; neighbor++) {
        if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
            dfs(neighbor, n, isConnected, visited);
        }
    }
}

int findCircleNum(int n, int isConnected[MAX_CITIES][MAX_CITIES]) {
    int provinces = 0;
    int visited[MAX_CITIES] = {0};

    for (int city = 0; city < n; city++) {
        if (!visited[city]) {
            provinces++;
            dfs(city, n, isConnected, visited);
        }
    }

    return provinces;
}

int main() {
    int n;
    scanf("%d", &n);

    int isConnected[MAX_CITIES][MAX_CITIES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int provinces = findCircleNum(n, isConnected);
    printf("Total number of provinces: %d\n", provinces);

    return 0;
}
