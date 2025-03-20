#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> prefix;
    
    for (string p : phone_book)
        prefix[p]++;
    for (string p : phone_book)
    {
        for (int i = p.size(); i > 0; i--)
            if (prefix[p.substr(0, i)] && p.substr(0, i) != p)
                return false;
    }
    return true;
}