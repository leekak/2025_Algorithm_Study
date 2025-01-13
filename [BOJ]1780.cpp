#include <iostream>
using namespace std;

int cnt_n=0;
int cnt_zero=0;
int cnt_p=0;
int paper[2200][2200]; //3^7이 2187이라서

void cut_paper(int x, int y, int N){
    bool flag=1;
    //다른게 나오면 분할(재귀 호출)
    for(int i=y; i<y+N; i++) {
        for(int j=x; j<x+N; j++) {
            if(paper[y][x] != paper[i][j]) {
                flag=0; //0이면 다름
                break;
            }
        }
        if(flag==0) break;
    }
    if(flag==0) {
        //여기 뭐 반복문으로 표현할 수 있을 거 같은데 귀찮음ㅎ
        cut_paper(x, y, N/3);
        cut_paper(x, y+N/3, N/3);
        cut_paper(x, y+N/3+N/3, N/3);
        cut_paper(x+N/3, y, N/3);
        cut_paper(x+N/3, y+N/3, N/3);
        cut_paper(x+N/3, y+N/3+N/3, N/3);
        cut_paper(x+N/3+N/3, y, N/3);
        cut_paper(x+N/3+N/3, y+N/3, N/3);
        cut_paper(x+N/3+N/3, y+N/3+N/3, N/3);

    } else {
        //모두 같다면 첫 번째 원소만 확인해서 카운트 추가해주기
        if(paper[y][x]==-1) cnt_n++;
        else if(paper[y][x]==0) cnt_zero++;
        else if(paper[y][x]==1) cnt_p++;
    }
}

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> paper[i][j];
        }
    }
    cut_paper(0,0, N);
    cout << cnt_n << "\n" << cnt_zero << "\n" << cnt_p;
    return 0;
}
