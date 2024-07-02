#include <iostream>
#include <vector>

std::vector<int> sieve_of_eratosthenes(int M, int N) {
    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= N; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= N; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int num = M; num <= N; ++num) {
        if (is_prime[num]) {
            primes.push_back(num);
        }
    }
    return primes;
}

int main() {
    int M, N;
    std::cin >> M >> N;

    std::vector<int> primes = sieve_of_eratosthenes(M, N);

    for (int prime : primes) {
        std::cout << prime << "\n";
    }

    return 0;
}