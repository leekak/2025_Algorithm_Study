#include <iostream>
#include <cstring>
using namespace std;

bool is_squared(int num) {
    return (num & (num-1)) == 0;
}

int main() {
    int n;
    cin >> n;
    int result[n+1]; // 결과 저장할 배열
    memset(result, 0, sizeof(result));
    bool sn[n+1]; // 이미 썼는지 확인하려고
    memset(sn, false, sizeof(result));
    for(int i=n; i>0; i--) {
        for(int j=1; j<=n; j++) {
            if(!sn[i] && is_squared(i+j)) {
                result[i] = j;
                result[j] = i;
                sn[i] = true;
                sn[j] = true;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        cout << result[i] << "\n";
    }
    return 0;
}

/*
 * 큰 숫자부터 시작
 * 작은 수부터 선택해서 합이 2의 거듭제곱인지 확인한 후
 * 맞다면 결과배열에 둘 다 추가, sn배열도 true로 바꿈
 * sn배열을 통해 이미 사용되었다는 정보를 담지 않는다면
 * 한 숫자가 여러번 사용될 수도 있음
 */
