#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void devide(vector<char>& str, int start, int length) {
    //base case
    //구간의 길이가 1이면 더 이상 공백으로 바꿀 수 없으니까 종료
    if(length == 1) return;
    //3등분 중에서 가운데를 공백으로 바꾸기
    for(int i=start+length/3; i<start+length/3+length/3; i++) {
        str[i] = ' ';
    }
    //3등분해서 재귀호출하기
    devide(str, start, length/3);
    devide(str, start + (length/3) *2, length/3);
}

int main() {
    int n;
    while(cin>>n) {

        vector<char> cantor((int) pow(3, n), '-');
        devide(cantor, 0, cantor.size());

        for(int i=0; i<cantor.size(); i++) {
            cout << cantor[i];
        }
        cout << '\n';
    }
    return 0;
}
