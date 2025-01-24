#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str;
    vector<string> str_split;
    vector<int> term;
    cin >> str;

    int cnt_plus=0;
    size_t pos;
    while((pos = str.find('-')) != string::npos)  {
        str_split.push_back(str.substr(0, pos)); // 찾은 데까지 저장
        str.erase(0, pos + 1); // 찾은 만큼은 지워 주자
    }//npos는 find()가 검색에 실패했을 때 반환하는 값임
    str_split.push_back(str.substr(0, pos)); // 마지막에 남은 식

    for(int i=0; i<str_split.size(); i++) {
        while((pos = str_split[i].find('+')) != string::npos)  {
            //i==0일 때 이 부분이 수행된다는 것은 '+'가 먼저 나온다는 것
            if(i==0) {
                cnt_plus++;
            }
            term.push_back(stoi(str_split[i].substr(0, pos)));
            str_split[i].erase(0, pos + 1);
        }
        term.push_back(stoi(str_split[i].substr(0, pos)));

    }

    int result = term[0];

    // cnt==0 이면 '-'가 먼저 나온다는 것임
    for(int i=1; i<cnt_plus+1; i++) {
        result += term[i];
    }
    for(int i=cnt_plus+1; i<term.size(); i++) {
        result -= term[i];
    }

    cout << result;

    return 0;
}
/*
 * 접근법
 * '-'로 먼저 자른다.
 * 그러면 숫자와 '+'를 포함한 식이 남는다.
 * 그 식을 '+'로 자른다.
 * 자른 숫자들은 배열에 저장하고
 * 첫 번째 숫자에서 나머지 숫자를 모두 빼면 답.
 * 답이아니네;;;;;
 * 왜냐면 앞에 더하기가 연속으로 나올 수도 있어
 *
 *
 * 자자자 정리 해볼게
 * 일단 기본적인 생각은 이거야
 * '-' 부터 '-'까지 괄호로 묶어서 차례로 빼주면 최솟값이 돼
 * '-' 랑 '-' 사이는 더하기겠지
 *
 * 일단 먼저 '-'로 잘라서 string vector에 저장할거야
 * 그럼 vector 안에는 숫자와 '+'로 구성된 string들이 저장돼
 * 그 string들을 '+'로 잘라서 int vector에 저장할거야
 * 이 때 경우가 나뉘어
 * 1. 첫 '-'가 나오기 전에 '+'가 존재하는 경우 ('-'가 아예 없는 경우 포함)
 * 2. '-'가 먼저 나오는 경우
 *
 * 1번의 경우 '+'의 개수를 셀거야
 * 첫 '-'가 나오기 이전에 이 '+'를 포함한 값을 모두 계산해 놔야해
 * 2번의 경우는 첫 항에서 나머지를 모두 빼면 돼
 */
