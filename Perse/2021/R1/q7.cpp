//2021 R1 Q7
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> names;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; names.push_back(s);
    }
    sort(names.begin(), names.end());

    while (names.size() > 2) {
        string eliminator = names[0];
        names.erase(names.begin());
        for (char c : eliminator) {
            for (int i = names.size() - 1; i >= 0; i--) {
                if (names[i].find(c) != string::npos) {
                    names.erase(names.begin() + i);
                }
            }
        }
    }
    if (names.size() == 2) { // eliminator is the first element
        cout << names[1];
    } else if (names.size() == 1) {
        cout << names[0];
    } else {
        cout << "NO RESULT";
    }

    return 0;
}