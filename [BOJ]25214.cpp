#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    //A[j]-A[i]가 음수일 수도 있지요라
    int max = -(int)pow(10, 9);

    vector<int> maxi(N);
    //제일 작은 값을 기억해뒀다가 (새로 들어오는 값 - 제일 작은 값)과 기존 차의 최댓값을 비교
    //제일 작은 값과 차의 최댓값은 필요하면 갱신
    int min_element=arr[0];
    for(int i=1; i<N; i++) {
        if(arr[i] < min_element) {
            min_element = arr[i];
        }
        if(max < (arr[i]-min_element)) {
            max = arr[i]-min_element;
        }
        maxi[i] = max;
    }
    for(int i=0; i<N; i++) {
        cout << maxi[i] << " ";
    }
    return 0;
}
