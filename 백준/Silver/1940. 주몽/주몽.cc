#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, token = 0, arr[15000] = { 0 };
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(arr[i] + arr[j] == m)
                token++;
    cout << token;
    
    return 0;
}