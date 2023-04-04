#include <bits/stdc++.h>

using namespace std;

struct Node {
    char val;
    Node * left = nullptr;
    Node * right = nullptr;
};

void addToNode(Node * node, char val) {
    if (node->val < val) {
        if (node->right) addToNode(node->right, val);
        else {
            node->right = new Node();
            node->right->val = val;
        }
    }
    else if (node->val > val) {
        if (node->left) addToNode(node->left, val);
        else {
            node->left = new Node();
            node->left->val = val;
        }
    }
}

int level;
void dfs(Node *node, int dis) {
    if (dis == level) {
        cout << node->val << " ";
        return;
    }
    if (node->left) dfs(node->left, dis+1);
    if (node->right) dfs(node->right, dis+1);
}

signed main() {
    string s; cin >> s >> level;
    Node root; root.val = s[0];
    for(int i=1; i<s.size(); i++) addToNode(&root, s[i]);
    dfs(&root, 1);
	return 0;
}
