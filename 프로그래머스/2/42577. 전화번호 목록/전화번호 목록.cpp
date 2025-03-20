#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    map<string, int> prefix;
    
    for (string p : phone_book)
    {
        for (int i = p.size(); i > 0; i--)
            prefix[p.substr(0, i)]++;
    }
    for (string p : phone_book)
    {
        if (prefix[p] != 1)
            return false;
    }
    return true;
}