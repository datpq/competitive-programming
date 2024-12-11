#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Node
{
    int data;
    struct Node *next = NULL;
    Node(int val) : data(val) {}
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
        freopen("../input.txt", "r", stdin); 
        freopen("../output.txt", "w", stdout); 
    #endif

    Node * root = NULL;
    Node * cur = NULL;
    int val;
    while(cin >> val) {
        Node *node = new Node(val);
        if (root == NULL) {
            root = cur = node;
        } else {
            cur->next = node;
            cur = node;
        }
    }
    const int N = 25;
    for(int i=0; i<N; i++) {
        cur = root;
        while(cur) {
            if (cur->data == 0) cur->data = 1;
            else {
                string str = to_string(cur->data);
                if (str.length() % 2 == 0) {
                    int left = stoll(str.substr(0, str.length()/2));
                    int right = stoll(str.substr(str.length()/2));
                    Node * node = new Node(right);
                    node->next = cur->next;
                    cur->next = node;
                    cur->data = left;
                    cur = node;
                } else {
                    cur->data *= 2024;
                }
            }
            cur = cur->next;
        }
    }
    int ans = 0;
    while (root) {
        ans++;
        root = root->next;
    }
    cout << ans;
    return 0;
}