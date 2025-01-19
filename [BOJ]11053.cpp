#include <iostream>
#include <vector>
using namespace std;

int lis(int start, vector<int>& arr, vector<int>& cache) {
    int& ret = cache[start];
    if(ret != -1) return ret;
    ret = 1;
    //arr[start] 보다 큰 숫자들만 고른 부분수열
    for(int next = start+1; next < arr.size(); next++) {
        if(arr[start] < arr[next])
            //arr[start]도 세야하니까 +1
            ret = max(ret, lis(next, arr, cache) + 1);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> cache(N, -1);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    int maxi = 0;
    for(int i=0; i<N; i++) {
        maxi = max(maxi, lis(i, arr, cache));
    }
    cout << maxi;
    return 0;
}

/*
 * 제한시간은 1초
 * 수열의 최대 크기는 1,000
 * 시간복잡도 O(N^2)이므로 최대연산횟수 1,000,000 이니까 1초안에 가능할 것 같아서 O(nlgn)말고 이걸로 함
 * 절대 아직 O(nlgn) 공부안해서 그런 거 아님 암튼 아님
 */
