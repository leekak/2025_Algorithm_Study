#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int N;
    int tang[200001];
    int S[10];
    memset(tang, 0, sizeof(tang));
    memset(S, 0, sizeof(S));
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> tang[i];
        //S[tang[i]]++;
    }
    int* left = &tang[1];
    int* right = &tang[2];
    S[*left]++; // 과일 사용했으면 개수 추가하기
    int len=1; // 현재 탕후루 길이
    int maxi=len; // 최대 탕후루 길이
    int num_type=1; //사용한 과일 종류의 수

    while(*right != 0) {
        // 이 과일을 사용한 적이 없다면!
        if(S[*right] == 0 ) {
            num_type++;
        }
        S[*right]++;
        len++;
        if(num_type<=2) {
            if(len>maxi) maxi=len;
        } else {
            S[*left]--;
            if(S[*left] == 0) num_type--;
            left++;
            len--;
        }
        right++;
    }
    cout << maxi;

    return 0;
}

/*
 * 과일의 개수 N개
 * 과일의 종류는 최대 9개, 정수형 (S1 ... S9)
 *
 * 남은 과일의 개수가 최대가 되어야 하니까
 * 일단 제일 개수가 많은 과일은 남겨야 할까?
 * 112321
 * 꼭 그렇지는 않을 것 같은데
 * 1214241
 * 그냥 max 값 저장해놓고 다 해보자
 * 뺄 때 마다 카운트해주면 답은 N-(a+b) 겠지
 * ㅇㅇㄴㅇ
 * --------------------------------------------
 *
 * 투 포인터 알고리즘
 * left right 정해주고 right를 뒤로 밀면서 max값 갱신
 * 과일의 종류가 세개가 되면 left도 뒤로 민다!
 * right가 끝을 넘을 때까지 (미리 0으로 초기화해 두었으므로 *right==0 이 참일 때이다.)
 *
 * 몇 가지 필요한 규칙
 *
 * num_type이 +1이 되는 경우는 S[index]가 0 즉 아직 그 과일을 사용하지 않았을 때 이다.
 * num_type이 -1이 되는 경우는 S[index]가 0이 되어야한다.
 * left를 뒤로 밀 때 해당 과일을 한 개 빼기 때문에 S[*left]--를 해주는데 이 때 S[index]가 0이되면
 * num_type을 -1 해주는 것이다!
 *
 * ㅁㄹ 나머진 니네 알아서 생각해
 */
