#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> wear;
    for (auto c : clothes)
        wear[c[1]]++;
    for (auto w : wear)
        answer *= (w.second + 1);
    return answer - 1;
}