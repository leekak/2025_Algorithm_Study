#include <iostream>
#include <vector>
using namespace std;

int main() {
    int S, P;
    int result=0;
    cin >> S >> P;
    string dna;
    cin >> dna;
    vector<pair<char, int>> num_char;
    num_char.emplace_back('A', 0);
    num_char.emplace_back('C', 0);
    num_char.emplace_back('G', 0);
    num_char.emplace_back('T', 0);
    int tmp;
    for(int i=0; i<4; i++) {
        cin >> tmp;
        num_char[i].second = tmp;
    }

    vector<pair<char, int>> sub_num_char;
    sub_num_char.emplace_back('A', 0);
    sub_num_char.emplace_back('C', 0);
    sub_num_char.emplace_back('G', 0);
    sub_num_char.emplace_back('T', 0);

    //dna문자열의 제일 앞부터 P만큼의 부분문자열에 대한 정보를
    //sub_num_char에 저장할거임
    for(int i=0; i<P; i++) {
        if(dna[i] == 'A') {
            sub_num_char[0].second++;
        } else if(dna[i] == 'C') {
            sub_num_char[1].second++;
        } else if(dna[i] == 'G') {
            sub_num_char[2].second++;
        } else if(dna[i] == 'T') {
            sub_num_char[3].second++;
        }
    }
    // 조건보다 클 때만 result++
    for(int i=0; i<4; i++) {
        if(sub_num_char[i].second < num_char[i].second) {
            break;
        }
        if(i==3) {
            result++;
        }
    }
    //dna문자열의 길이에서 부분문자열의 길이를 뺀 만큼 반복함
    for(int i=1; i<S-P+1; i++) {
        if(dna[i-1] == 'A') {
            sub_num_char[0].second--;
        } else if(dna[i-1] == 'C') {
            sub_num_char[1].second--;
        } else if(dna[i-1] == 'G') {
            sub_num_char[2].second--;
        } else if(dna[i-1] == 'T') {
            sub_num_char[3].second--;
        }

        if(dna[i-1+P] == 'A') {
            sub_num_char[0].second++;
        } else if(dna[i-1+P] == 'C') {
            sub_num_char[1].second++;
        } else if(dna[i-1+P] == 'G') {
            sub_num_char[2].second++;
        } else if(dna[i-1+P] == 'T') {
            sub_num_char[3].second++;
        }
        for(int j=0; j<4; j++) {
            if(sub_num_char[j].second < num_char[j].second) {
                break;
            }
            if(j==3) {
                result++;
            }
        }
    }
    cout << result;

    return 0;
}
/*
 * push_back() vs emplace_back()
 * push_back()은 ()안에 객체가 들어가야하고
 * emplace_back()은 ()안에 인자를 내부에서 객체를 만듦
     * ex)
     * P=5
     * 0 1 2 3 4 5 6 7 8
     * C C T G G A T T G
     * o o o o o
     *   o o o o o
     *     o o o o o
     * i-1+P 인덱스를 확인해야함
*/
