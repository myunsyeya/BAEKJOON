#include <iostream>

int main()
{
    int X, N;
    std::cin >> X >> N;
    while (N--) {
        int a, b;
        std::cin >> a >> b;
        X -= a * b;
    }
    std::cout << (!X ? "Yes" : "No");
    return 0;
}