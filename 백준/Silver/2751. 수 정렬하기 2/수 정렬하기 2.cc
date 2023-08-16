#include <iostream>

using namespace std;

/*
* counting sort 사용.
* 절대값 1,000,000 이하이므로 1048576를 편향치(bias)로 잡고 배열 크기는 2097152로 사용.
* 아차차.. stack 내부는 보통 1mb 이하겠지..? 
*/
const int kInputArea = 2097152;
const int kBias = kInputArea / 2;
bool arr[kInputArea];

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int n, temp;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[temp + kBias] = true;
    }
    for (int i = 0; i < kInputArea; i++)
        if (arr[i]) cout << i - kBias << '\n';

    return 0;
}