//P1
#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << a << " squared plus " << b << " squared is ";
    if ((a * a) + (b * b) > (c * c))
        cout << "greater than " << c << " squared";
    else if ((a * a) + (b * b) < (c * c))
        cout << "less than " << c << " squared";
    else
        cout << "equal to " << c << " squared";
    return 0;
}

//P2
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
    double d; cin >> d;
    cout << std::fixed << std::setprecision(1) << (double)ceil(d/50)*50 - d;
    return 0;
}

//P3
#include <iostream>
using namespace std;
int main() {
    int n, m; char a, b;
    cin >> n >> m >> a >> b;
    cout << string(n, a) << endl;
    for(int i=1; i<(n-m)/2; i++) cout << a << string(n-2, ' ') << a << endl;
    for(int i=0; i<m; i++) cout << a << string((n-2-m)/2, ' ') << string(m, b) << string((n-2-m)/2, ' ') << a << endl;
    for(int i=1; i<(n-m)/2; i++) cout << a << string(n-2, ' ') << a << endl;
    cout << string(n, a) << endl;
    return 0;
}

//P4
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
    while(true) {
        string s; getline(cin, s);
        stringstream ss(s);
        string firstWord; ss >> firstWord;
        if (s[s.size()-1] == '?') cout << "not sure really\n";
        else if (firstWord == "how" || firstWord == "what" || firstWord == "why" || firstWord == "who" || firstWord == "when" || firstWord == "where")
            cout << "not sure really\n";
        else if (s == "goodbye") {
            cout << "see you!\n";
            break;
        } else cout << "but why?\n";
    }
    return 0;
}

//P5
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int po, pe; cin >> po >> pe;
    int money1 = po * 100 + pe;
    int money2 = po + pe * 100;
    if (money1 <= money2 && money1 <= 2000) {
        cout << "£" << std::fixed << std::setprecision(2) << (double)money1/100 << endl;
        if (money2 <= 2000) cout << "£" << std::fixed << std::setprecision(2) << (double)money2/100 << endl;
    } else if (money2 <= money1 && money2 <= 2000) {
        cout << "£" << std::fixed << std::setprecision(2) << (double)money2/100 << endl;
        if (money1 <= 2000) cout << "£" << std::fixed << std::setprecision(2) << (double)money1/100 << endl;
    }
    return 0;
}

//P6
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int col, row; cin >> col >> row;
    vector<string> grid(row);
    for(int i=0; i<row; i++) cin >> grid[i];
    int ans = 0;
    for(int i=0; i<row/2; i++) {
        for(int j=0; j<col/2; j++) {
            if (grid[i][j] == '1' && grid[i+row/2][j] == '1' && grid[i][j+col/2] == '1' && grid[i+row/2][j+col/2] == '1') ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

//P7
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long r, t, a; cin >> r >> t >> a;
    long long ans = ceil((double)(r*t)/(a-r)) + t;
    cout << ans;
    return 0;
}

//P8
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    string s; getline(cin, s);
    map<string, int> votes;
    for(int i=0; i<n; i++) {
        getline(cin, s);
        string name = s.substr(0, s.find(':'));
        s = s.substr(s.find(':')+1);
        string choice = s.substr(0, s.find(' '));
        string name2 = s.substr(s.find(' ') + 1);
        votes[name2] = votes[name2] + (choice == "UP" ? 1 : -1);
        if (!votes.count(name)) votes[name] = 0;
    }
    vector<pair<int, string>> v;
    for(auto &x: votes) v.push_back({x.second, x.first});
    sort(v.begin(), v.end());
    cout << v[0].second << endl;
    for(int i=1; i<v.size(); i++) {
        if (v[i].first == v[0].first) cout << v[i].second << endl;
        else break;
    }
    return 0;
}
