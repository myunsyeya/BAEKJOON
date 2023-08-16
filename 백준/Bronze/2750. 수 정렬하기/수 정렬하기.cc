#include <iostream>
#include <algorithm>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int n, temp;
    int arr[1024] = {0,};
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return 0;
}