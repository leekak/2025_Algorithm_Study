#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int map[N][3];
    int dp[N][3];   // 최소 비용을 담을 배열
    for(int i=0; i<N; i++) {
        for(int j=0; j<3; j++)
            cin >> map[i][j];
    }
    dp[0][0] = map[0][0], dp[0][1] = map[0][1], dp[0][2] = map[0][2];

    for(int i=0; i<N-1; i++) {
        dp[i+1][0] = min(dp[i][1], dp[i][2]) + map[i+1][0];
        dp[i+1][1] = min(dp[i][0], dp[i][2]) + map[i+1][1];
        dp[i+1][2] = min(dp[i][0], dp[i][1]) + map[i+1][2];
    }

    cout << min(dp[N-1][2], min(dp[N-1][0], dp[N-1][1]));

    return 0;
}
