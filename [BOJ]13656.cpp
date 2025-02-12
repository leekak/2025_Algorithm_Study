#include <iostream>
#include <string>
using namespace std;

char fiber[1000][1000];
bool visited[1000][1000];
int M, N;
bool result= false;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int y, int x) {
    visited[y][x] = true;
    if(y==M-1) {
        result = true;
        return;
    }
    int nx, ny;
    for(int i=0; i<4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if(ny<0 || nx<0 || nx>N-1) continue;
        if(fiber[ny][nx]=='0' && !visited[ny][nx]) dfs(ny, nx);
    }
}

int main() {
    cin >> M >> N;
    string tmp;
    for(int i=0; i<M; i++) {
        cin >> tmp;
        for(int j=0; j<N; j++) {
            fiber[i][j]= tmp[j];
        }
    }

    for(int i=0; i<N; i++) {
        if(fiber[0][i] == '0') {
            dfs(0, i);
        }
    }

    if(result) cout << "YES";
    else cout << "NO";

    return 0;
}
