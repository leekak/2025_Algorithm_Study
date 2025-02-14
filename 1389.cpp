#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int adj[N+1][N+1];  // 인접행렬, i와 j가 친구이면 1 아니면 0
    fill(&adj[0][0], &adj[N][N], 1e9); // 플로이드
    for(int i=0; i<M; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        adj[tmp1][tmp2] = 1;
        adj[tmp2][tmp1] = 1;
    }
    for(int i=1; i<=N; i++) {
        adj[i][i] = 0;
    }
    // 플로이드 알고리즘
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int result;
    int sum=1e9;
    for(int i=1; i<=N; i++) {
        int tmp=0;
        for(int j=1; j<=N; j++) {
            tmp += adj[i][j];
        }
        if(sum > tmp) {
            sum = tmp;
            result = i;
        }
    }

    cout << result;

    return 0;
}

/*
 * 인접 행렬
 * 서로가 친구이면 1 아니면 0
 *
 * 플로이드 알고리즘으로 모든 정점간의 거리를 구한 후
 * 해당 행렬에서 최소의 합을 가지는 행을 구하면 끝
 */
