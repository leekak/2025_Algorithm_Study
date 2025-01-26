#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    int dp[10][1001] =  {0,};

    vector<vector<int>> dial(10);
    dial[0] = {7};
    dial[1] = {2, 4};
    dial[2] = {1, 3, 5};
    dial[3] = {2, 6};
    dial[4] = {1, 5, 7};
    dial[5] = {2, 4, 6, 8};
    dial[6] = {3, 5, 9};
    dial[7] = {4, 8, 0};
    dial[8] = {5, 7, 9};
    dial[9] = {6, 8};

    //길이가 1일 때는 모두 1
    for(int i=0; i<10; i++) {
        dp[i][1] = 1;
    }
    for(int i=2; i<1001; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<dial[j].size(); k++) {
                dp[j][i] += dp[dial[j][k]][i-1];
            }
            dp[j][i] = dp[j][i] % 1234567;
        }
    }

    while(T--) {
        int N;
        cin >> N;
        int cnt=0;
        for(int i=0; i<10; i++) {
            cnt = (cnt + dp[i][N]) % 1234567;
        }

        cout << cnt << "\n";
    }

    return 0;
}
/*
 * 처음에 바로 숫자 규칙을 찾아버려서 그렇게 풀랬는데 오버플로우 때문인지 규칙이 틀린건지 안돼서 DP로 하기로함
 *
 * 접근법
 * 특정 숫자 다음에 오는 숫자가 정해져있잖아
 * 반대로 생각하면 특정 숫자 앞에 오는 숫자도 정해져 있는 거임 ㅇㅋ?
 * 봐바 N자리 비밀 번호고 a로 끝나는 비밀 번호의 개수는
 * N-1 자리 비밀 번호고 a옆에 올 수 있는 숫자들로 끝나는 비밀 번호의 개수를 모두 더하면 됨
 * 예를 들어가
 * N=2고 a=3이야
 * 그러면 N=1이고 3, 2, 6 으로 끝나는 이 세개가 답이 됨 ㅇㅋ?
 * 그걸 코드로 열심히 구현했음
 */
