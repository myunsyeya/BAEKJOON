#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N, M; cin >> N >> M;
    int inset = 0;
    set<string> S;
    for (int i = 0; i < N; i++) { 
        string s; cin >> s; 
        S.insert(s); 
    }
    for (int i = 0; i < M; i++) {
        string c; cin >> c;
        if (S.find(c) != S.end()) inset++;
    }
    cout << inset;
    return 0;
}