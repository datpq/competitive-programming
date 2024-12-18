#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    string s;
    int A = 0, B = 0, C = 0;
    vector<int> opcodes, operands;
    while(getline(cin, s)) {
        stringstream ss(s);
        string part; ss >> part;
        if (part == "Register") {
            ss >> part;
            if (part == "A:") ss >> A;
            else if (part == "B:") ss >> B;
            else if (part == "C:") ss >> C;
        } else if (part == "Program:") {
            int code;
            while(ss >> code) {
                opcodes.push_back(code);
                char c; ss >> c >> code >> c;
                operands.push_back(code);
            }
            break;
        }
    }

    auto combo = [&](int comboOper) -> int {
        if (comboOper < 4) return comboOper;
        else if (comboOper == 4) return A;
        else if (comboOper == 5) return B;
        else if (comboOper == 6) return C;
        return 0;
    };

    vector<int> ans;
    for(int i=0; i<opcodes.size(); i++) {
        switch (opcodes[i]) {
            case 0:
                A /= pow(2, combo(operands[i]));
                break;
            case 1:
                B ^= operands[i];
                break;
            case 2:
                B = combo(operands[i]) % 8;
                break;
            case 3:
                if (A) i=operands[i]-1;
                break;
            case 4:
                B ^= C;
                break;
            case 6:
                B = A / pow(2, combo(operands[i]));
                break;
            case 7:
                C = A / pow(2, combo(operands[i]));
                break;
            case 5:
                int val = combo(operands[i]) % 8;
                ans.push_back(val);
                break;
        }
    }

    if (!ans.empty()) {
        cout << ans[0];
        for(int i=1; i<ans.size(); i++) cout << ',' << ans[i];
    }
    return 0;
}