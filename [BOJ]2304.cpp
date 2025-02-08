#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> warehouse;
    int max=-1, max_loc;
    for(int i=0; i<N; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        // 받아올 때부터 최고 높이를 기억하게 했음
        if(tmp2>max) {
            max=tmp2, max_loc=tmp1; // max_loc는 최고 높이의 위치임
        }
        warehouse.emplace_back(tmp1, tmp2);
    }
    int area=0;
    sort(warehouse.begin(), warehouse.end()); // 기둥의 위치를 기준으로 정렬
    int pre_loc=warehouse[0].first;
    int pre_max=warehouse[0].second;
    int index=0;
    while(warehouse[index].first<max_loc) {
        if(warehouse[index+1].second >= pre_max) {
            area += (warehouse[index+1].first-pre_loc)*(pre_max);
            pre_max = warehouse[index+1].second;
            pre_loc = warehouse[index+1].first;
        }
        index++;
    }
    int next_loc=warehouse[N-1].first;
    int next_max=warehouse[N-1].second;
    index=N-1;
    while(warehouse[index].first>max_loc) {
        if(warehouse[index-1].second >= next_max) {
            area += (next_loc-warehouse[index-1].first)*(next_max);
            next_max = warehouse[index-1].second;
            next_loc = warehouse[index-1].first;
        }
        index--;
    }
    // 제일 높은 기둥 처리해야함
    // 항상 기둥이 한 개가 남네
    area += max;
    cout << area;

    return 0;
}
/*
 * 크게 세 가지 경우
 * 기둥이 올라가는 경우
 * 기둥이 수평인 경우
 * 기둥이 내려가는 경우
 *
 * 이전보다 큰 높이가 있으면 기둥이 올라간다.
 * ->
 * 이때까지 가장 큰 높이를 기억해두고 그것보다 큰 높이를 만난다면
 * (이전 최고높이)x(위치 차이)를 area에 추가한다.
 * (pre_max)x(위치 차이)
 *
 * 내려가는 경우는 거꾸로 생각하면 된다.
 * 올라가는 경우에 왼쪽에서 오른쪽으로 생각했으니
 * 내려가는 경우는 오른쪽에서 왼쪽으로 진행한다고 생각하자
 * 그럼 마찬가지로 오른쪽에서 가장 큰 높이를 기억해두고 그것보다 큰 높이를 만난다면
 * (이전 최고높이)x(위치 차이)를 area에 추가한다.
 * (next_max)x(위치 차이)
 *
 * 왼쪽과 오른쪽을 나누기 위해서는 기준이 필요한데 그게 전체에서 가장 높이가 큰 기둥이다.
 * 그래서 입력받을 때부터 max값과 max_loc로 위치를 저장해뒀다.
 * 가장 높은 기둥이 여러 개가 있을 수 있지만 max_loc에는 한 개만 저장된다.(입력순서에따라 뭐가 저장될 지는 다름)
 * 위 알고리즘으로 쭉 동작하고 나면 max_loc에 있는 기둥 한 개만 남게 되므로 마지막에 area에 max*1만큼 저장하면 된다.
 *
 */
