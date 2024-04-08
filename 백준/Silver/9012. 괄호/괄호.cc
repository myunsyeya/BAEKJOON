#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int main(void)
{
    int n;
    char PS[51];
    stack<bool> s;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", PS);
        for (size_t i = 0; i < strlen(PS); i++) {
            if (PS[i] == '(')
                s.push(true);
            else {
                if (!s.empty())
                    s.pop();
                else {
                    s.push(false);
                    break;
                }
            }
        }
        if (!s.empty())
            printf("NO\n");
        else
            printf("YES\n");
        while (!s.empty())
            s.pop();
    }
    return 0;
}