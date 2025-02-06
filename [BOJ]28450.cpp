#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int map[N][M];
    long long dp[N][M];
    memset(map, 0, sizeof(map));
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            cin >> map[i][j];
    }
    int H;
    cin >> H;

    dp[0][0] = map[0][0];
    for(int i=1; i<N; i++) {
        dp[i][0] = dp[i-1][0] + map[i][0];
    }
    for(int j=1; j<M; j++) {
        dp[0][j] = dp[0][j-1] + map[0][j];
    }

    for(int i=1; i<N; i++) {
        for(int j=1; j<M; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + map[i][j];
        }
    }
    /*
    cout<<"\n";
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
     */

    if(dp[N-1][M-1] > H) cout << "NO";
    else cout << "YES" << "\n" << dp[N-1][M-1];

    return 0;
}
/*
 * N, M 으로 가는 길에서 눈치력의 최소값 구해서 저장해놓고
 * 그 값이 은신력보다 크면 NO
 * 작으면 YES와 함께 값 출력
 *
 * 걍 dp네 오른쪽으로 가거나 아래로 가거나
 * 왼쪽 위에서 시작할 거라 1행일 때랑 1열일 때는 미리 계산해놓음
 * 헬창 행님들의 눈치력은 10^9이고
 * 지도 크기는 최대 1000 X 1000이니까 자료형이 int를 벗어남만 주의하면 될듯
 */
