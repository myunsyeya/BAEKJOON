#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

bool compare(string a, string b)
{
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    string word;
    cin >> N;
    while (N--) {
        cin >> word;
        v.push_back(word);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));
    return 0;
}