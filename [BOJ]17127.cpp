#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> flowers(N);
    for(int i=0; i<N; i++) {
        cin >> flowers[i];
    }

    vector<int> pmul(N); // partial multiplication
    pmul[0] = flowers[0];
    for(int i=1; i<N; i++) {
        pmul[i] = pmul[i-1] * flowers[i];
    }
    // 부분곱으로 표현한 이유
    // pmul[b] / pmul[a] 로 O(1)시간에 구간의 곱을 구할 수 있음 (부분합 쓰는 이유랑 같음)
    // 종만북 p.597 참고

    int max = -1;
    int result;
    int a, b, c;
    for(a=0;a<N-3; a++) {
        for(b=a+1;b<N-2; b++) {
            for(c=b+1;c<N-1; c++) {
                result = pmul[a]/1 + pmul[b]/pmul[a] + pmul[c]/pmul[b] + pmul[N-1]/pmul[c];
                if(result > max) max = result;
            }
        }
    }
    // a, b, c 인덱스 세개를 이용하면 구간 네개로 나눌 수 있고
    // a<b<c 순서가 지켜져야함
    // 시간복잡도가 O(N^3)이라서 안될 것 같지만
    // N의 범위가 4<=N<=10 이므로 된다!

    cout << max;
    return 0;
}
