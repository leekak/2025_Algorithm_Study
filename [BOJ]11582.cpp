#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right, int N, int k) {
    if(right-left+1 > N/k) return;
    vector<int> result(right-left+1);
    int a = left;
    int b = mid + 1;
    int c = 0;

    while(a<=mid && b<=right) {
        if(arr[a] <= arr[b]) {
            result[c] = arr[a];
            a++;
        } else {
            result[c] = arr[b];
            b++;
        }
        c++;
    }
    if(a>mid) {
        while(b<=right) {
            result[c]=arr[b];
            c++;
            b++;
        }
    } else {
        while(a<=mid) {
            result[c]=arr[a];
            a++;
            c++;
        }
    }
    for(int i=left, j=0; i<=right; i++, j++) {
        arr[i] = result[j];
    }
}

void merge_sort(vector<int>& arr, int left, int right, int N, int k) {
    if(left<right) {
        int mid = (left+right)/2;
        merge_sort(arr, left, mid, N, k);
        merge_sort(arr, mid+1, right, N, k);
        merge(arr, left, mid, right, N, k);
    }
}

int main() {
    int N, k;
    cin >> N;
    vector<int> score(N);
    for(int i=0; i<N; i++) {
        cin >> score[i];
    }
    cin >> k;
    merge_sort(score, 0, N-1 ,N, k);
    for(int i=0; i<N; i++) {
        cout << score[i] << " ";
    }

    return 0;
}

/*
 * 다시다시 완전 다시 풀자
 * 일단 merge sort 먼저 구현해보고
 * 문제에 맞게 바꾸자
 * 각 단계에서 병합의 횟수 (merge 함수 호출 횟수) 와 문제에서의 k가 같네
 * 그럼 k 값에 따라 총 수행해야할 병합의 횟수가 바뀌니까
 * merge함수 호출 횟수가 특정 횟수가 되면 모든 recursive를 종료하면 되겠다 ㅇㅈ?
 * 하 일케 했는데 도저히 계속 틀렸다고 해서
 * 길이로 접근을 바꿨음
 * k값이 4 -> 2 -> 1 이렇게 작아질수록
 * 병합할 길이가 1+1 -> 2+2 -> 4+4 이렇게 커지잖아?
 * 병합 후 길이는 (N/k)/2 이렇게 되니까 결과를 담을 컨테이너의 길이가 (N/k)/2 보다 커지지 않을 때 까지만 하면 됨!
 */
