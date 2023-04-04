#include <bits/stdc++.h>

using namespace std;
signed main() {
    string s; cin >> s;
    stack<char> st;
    for(auto c: s) {
        if (c==',') continue;
        if (c==']') {
            char right = st.top();
            char left = right;
            st.pop();
            while (st.top() != '[') {
                left = st.top();
                st.pop();
            }
            st.pop();
            cout << (char)((left + right)/2);
        } else st.push(c);
    }
	return 0;
}
