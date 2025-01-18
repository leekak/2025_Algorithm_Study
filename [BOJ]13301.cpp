#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long arr[N];
    arr[0] = 4;
    arr[1] = 6;
    for(int i=2; i<N; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[N-1];
    return 0;
}
// 뭐라 적을 게 없음
