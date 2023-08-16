#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int num, sum = 0;
    string numbers;
    
    cin >> num >> numbers;
    for (char num : numbers)
        sum += num - '0';
    cout << sum << endl;
    return 0;
}