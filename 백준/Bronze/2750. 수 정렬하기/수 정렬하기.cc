#include <iostream>

using namespace std;

/*
* counting sort 사용. 
* 절대값 1000 이하이므로 1024를 편향치(bias)로 잡고 배열 크기는 2048로 사용.
*/
const int kInputArea = 2048;
const int kBias = kInputArea / 2;

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int n, temp;
    bool arr[kInputArea] = {false,};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[temp + kBias] = true;
    }
    for (int i = 0; i < 2048; i++)
        if (arr[i]) cout << i - kBias << endl;
    
    return 0;
}