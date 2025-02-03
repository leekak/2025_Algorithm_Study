#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string L, R;
    cin >> L >> R;
    int result=0;
    //두 수의 자릿수가 다르면 걍 답이 0임
    if(L.size() != R.size()) {
        cout << result;
        return 0;
    }

    vector<char> reverse_L(L.size()), reverse_R(R.size());
    for(int i=0; i<L.size(); i++) {
        reverse_L[i] = L[L.size()-1-i];
        reverse_R[i] = R[R.size()-1-i]; // 자리수가 같다는 걸 알고 있는 상태니까 같이 해도 됨;
    }
    while(!reverse_L.empty()) {
        // 가장 앞자리 숫자가 같은지 확인해야함
        // 만약 다르다면 18 37 이런 경우처럼 8이 없어도 되는 수가 존재하기에
        // 바로 결과 출력하고 종료하면 됨.
        // 만약 같다면 8인지 아닌지 확인 해야함
        // 8로 같다면 결과에 추가해줘야하고
        // 다른 수로 같다면 그냥 pop만 해주고 다음 수로 넘어가면 됨
        if(*(reverse_L.end()-1) == *(reverse_R.end()-1)) {
            if(*(reverse_L.end()-1)== '8') {
                result++;
            }
            reverse_L.pop_back();
            reverse_R.pop_back();
        } else {
            cout << result;
            return 0;
        }
    }
    cout << result;

    return 0;
}
// 동적 배열은 뒤에서 삽입/삭제가 상수시간이기 때문에 거꾸로 저장했음
