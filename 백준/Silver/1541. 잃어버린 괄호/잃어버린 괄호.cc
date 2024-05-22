#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();
    int A, B, C; A = B = C = 0;
    string exp; cin >> exp;
    char str[50]; strcpy(str, exp.c_str());
    char *token = strtok(str, "+-");
    for (int i = 0; token; token = strtok(NULL, "+-")) {
        if (C) B += atoi(token);
        else A += atoi(token);
        for (; exp[i] != NULL && exp[i] != '+' && exp[i] != '-'; i++);
        if (exp[i++] == '-') C = 1;
    }
    cout << (A - B);
    return 0;
}