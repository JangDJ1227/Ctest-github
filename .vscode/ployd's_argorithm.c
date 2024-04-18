#include <stdio.h>

#define INF 99999 // 무한대 값

// 그래프의 인접 행렬을 이용한 플로이드-워셜 알고리즘
void floydWarshall(int graph[][4], int n) {
    int dist[n][n];
    int i, j, k;

    // 초기화: 그래프의 가중치로 초기화
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // 경유지를 거치는 경우 최단 거리 갱신
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 결과 출력
    printf("모든 정점 쌍 사이의 최단 거리:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[4][4] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    int n = 4; // 그래프의 정점 수
    floydWarshall(graph, n);
    return 0;
}
