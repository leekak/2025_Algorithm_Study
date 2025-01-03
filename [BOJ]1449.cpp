#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> cracked(N);
    for(int i=0; i<N; i++) {
        cin >> cracked[i];
    }
    sort(cracked.begin(), cracked.end());
    int start = cracked[0];
    int diff = 0;
    int result = 1;
    for(int i=1; i<N; i++) {
        diff = cracked[i] - start;
        if((diff+1) > L) {
            result++;
            start = cracked[i];
        }
    }
    cout << result;
    return 0;
}
/*
 * 테이프는 차이+1 만큼의 길이가 되야함 (좌, 우 0.5씩 더해야하니까)
 * 그래서 차이+1 이 테이프의 길이보다 크게 되면 누수가 생김
 * 차이+1 > 테이프 => 추가 테이프 필요
 * 근데 이렇게 하면 안됨
 * 앞에서부터 차이를 구해 가면서 차이+1 이 L보다 커지는 순간 개수를 추가해야함 ㅇㅈ?
 * 그리고 거기서부터 시작점 갱신
*/
