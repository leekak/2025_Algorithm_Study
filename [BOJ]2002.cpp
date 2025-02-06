#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<string> in, out;
    vector<string> v;
    string tmp;
    for(int i=0; i<N; i++) {
        cin >> tmp;
        in.push(tmp);
    }
    for(int i=0; i<N; i++) {
        cin >> tmp;
        out.push(tmp);
    }

    int result=0;

    while(!out.empty() && !in.empty()) {
        string now = in.front();
        in.pop();
        while(!out.empty() && now != out.front()) {

            if(find(v.begin(), v.end(), now) == v.end()) {
                //out에서 pop하는 애들을 저장하고 있어야 해
                v.push_back(out.front());
                out.pop();
                result++;
            } else {
                break;
            }
            // vector에 있으면 넘어가
        }
        if(now == out.front()) out.pop();
    }

    cout << result;

    return 0;
}
