#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main() {
    fio();
    int T; cin >> T;

    while (T--) {
        int k; cin >> k;
        priority_queue<int> max_heap;
        priority_queue<int> delete_max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int, vector<int>, greater<int>> delete_min_heap;

        for (int i = 0; i < k; i++) {
            char op; cin >> op;
            int n; cin >> n;

            if (op == 'I') {
                min_heap.push(n);
                max_heap.push(n);
            }
            else if (op == 'D') {
                if (n == 1) {
                    while (!max_heap.empty() && !delete_max_heap.empty() && delete_max_heap.top() == max_heap.top()) {
                        delete_max_heap.pop();
                        max_heap.pop();
                    }
                    if (!max_heap.empty()) {
                        delete_min_heap.push(max_heap.top());
                        max_heap.pop();
                    }
                }
                else if (n == -1) {
                    while (!min_heap.empty() && !delete_min_heap.empty() && delete_min_heap.top() == min_heap.top()) {
                        delete_min_heap.pop();
                        min_heap.pop();
                    }
                    if (!min_heap.empty()) {
                        delete_max_heap.push(min_heap.top());
                        min_heap.pop();
                    }
                }
            }
        }
        while (!max_heap.empty() && !delete_max_heap.empty() && delete_max_heap.top() == max_heap.top()) {
            delete_max_heap.pop();
            max_heap.pop();
        }
        while (!min_heap.empty() && !delete_min_heap.empty() && delete_min_heap.top() == min_heap.top()) {
            delete_min_heap.pop();
            min_heap.pop();
        }
        if (max_heap.empty()) cout << "EMPTY\n";
        else cout << max_heap.top() << ' ' << min_heap.top() << '\n';
    }
}