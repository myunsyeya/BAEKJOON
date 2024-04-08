#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

map<string, int> dict;
map<int, string> dict_num;

int main()
{
    fio();
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string po;
        cin >> po;
        dict.insert({po, i});
        dict_num.emplace(i, po);
    }
    for (int i = 0; i < M; i++) {
        int stoi = 0;
        string prob;
        cin >> prob;
        if (prob[0] >= '0' && prob[0] <= '9')
        {
            for (int i = 0; i <prob.size(); i++, stoi *= 10) stoi += prob[i]-'0';
            stoi /= 10;
            cout << dict_num[stoi];
        } else cout << dict[prob];
        cout << '\n';
    }

    return 0;
}