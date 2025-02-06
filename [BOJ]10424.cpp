#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> stu; // 중간, 기말 순서임
    int tmp;    // tmp는 중간 성적임
    for(int i=1; i<=N; i++) {
        cin >> tmp;
        stu.emplace_back(tmp, i);
    }
    // 중간 기준으로 정렬하자
    sort(stu.begin(), stu.end());

    for(int i=0; i<N; i++) {
        cout << stu[i].first - stu[i].second << "\n";
    }

    return 0;
}

/*
 * 입력이 기말고사 성적 순서대로
 * 중간고사 성적이 들어옴
 * 
 * 출력은 중간고사 기준으로 출력해야하기 때문에
 * 중간고사를 first로 넣어서 정렬함
 * 
 * 손으로 몇 번 써보면 답은 (중간등수 - 기말등수)인걸 알 수 있다.
 */
