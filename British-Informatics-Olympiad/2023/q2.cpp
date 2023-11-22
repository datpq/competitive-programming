#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define f first
#define s second

using namespace std;

using Node = pair<int, int>;
using Shape = vector<Node>;
const int INF = 1e9;

const Shape F = {{0, 1}, {1, 0}, {1, 1}, {1, 2}, {2, 2}};
const Shape G = {{0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 1}};
const Shape I = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}};
const Shape L = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 0}};
const Shape J = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {-1, 0}};
const Shape N = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {1, 3}};
const Shape M = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {-1, 3}};
const Shape P = {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {1, 2}};
const Shape Q = {{0, 0}, {0, 1}, {0, 2}, {-1, 1}, {-1, 2}};
const Shape T = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {1, 2}};
const Shape U = {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {2, 1}};
const Shape V = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {2, 0}};
const Shape W = {{0, 1}, {0, 2}, {1, 1}, {1, 0}, {2, 0}};
const Shape X = {{0, 0}, {0, 1}, {0, 2}, {-1, 1}, {1, 1}};
const Shape Z = {{0, 0}, {0, 1}, {0, 2}, {-1, 2}, {1, 0}};
const Shape S = {{0, 0}, {0, 1}, {0, 2}, {-1, 0}, {1, 2}};
const Shape Y = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {-1, 2}};
const Shape A = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 2}};

Shape shapeFromLetter(char c) {
    switch (c) {
        case 'F': return F;
        case 'G': return G;
        case 'I': return I;
        case 'L': return L;
        case 'J': return J;
        case 'N': return N;
        case 'M': return M;
        case 'P': return P;
        case 'Q': return Q;
        case 'T': return T;
        case 'U': return U;
        case 'V': return V;
        case 'W': return W;
        case 'X': return X;
        case 'Z': return Z;
        case 'S': return S;
        case 'Y': return Y;
        case 'A': return A;
    }
}

const Shape adj={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool compSecond(Node a, Node b) { return (a.s < b.s); }
void shpNormalize(Shape &shape) {
    sort(shape.begin(), shape.end());
    for(int i=shape.size()-1; i>=0; i--) shape[i].f -= shape[0].f;
    sort(shape.begin(), shape.end(), compSecond);
    for(int i=shape.size()-1; i>=0; i--) shape[i].s -= shape[0].s;
}
Shape shpBorder(Shape &shape) {
    Shape ans;
    for(auto node: shape) {
        for(auto diff: adj) {
            Node borderNode = {node.f + diff.f, node.s + diff.s};
            if (find(shape.begin(), shape.end(), borderNode) != shape.end()) continue;
            if (find(ans.begin(), ans.end(), borderNode) != ans.end()) continue;
            ans.pb(borderNode);
        }
    }
    return ans;
}
bool sphAdd(Shape &shape, Node node) {
    if (find(shape.begin(), shape.end(), node) == shape.end()) {
        shape.pb(node);
        return true;
    }
    return false;
}
bool haveHoleInside(Shape &shape) {
    int mnX=INF, mnY=INF, mxX=-INF, mxY=-INF;
    for(auto node: shape) {
        mnX = min(mnX, node.f); mnY = min(mnY, node.s);
        mxX = max(mxX, node.f); mxY = max(mxY, node.s);
    }
    for(int x=mnX; x<=mxX; x++) {
        for(int y=mnY; y<=mxY; y++) {
            if (find(shape.begin(), shape.end(), make_pair(x, y)) == shape.end()) {
                //check small hole (1x1)
                bool fencing = true;
                for(auto diff: adj) {
                    if (find(shape.begin(), shape.end(), make_pair(x+diff.f, y+diff.s)) == shape.end()) {
                        fencing = false;
                        break;
                    }
                }
                if (fencing) return true;
                //check big hole (1x2)
                fencing = true;
                Shape bigAdj = {{-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {0, -1}, {0, 2}};
                for(auto diff: bigAdj) {
                    if (find(shape.begin(), shape.end(), make_pair(x+diff.f, y+diff.s)) == shape.end()) {
                        fencing = false;
                        break;
                    }
                }
                if (fencing) return true;
            }
        }
    }
    return false;
}
Shape shpTranslate(Shape &shape, Node diff) {
    Shape ans = shape;
    for(auto &node: ans) node.f+=diff.f, node.s+=diff.s;
    return ans;
}
Shape sphJoin(Shape &x, Shape &y) {
    Shape ans = x;
    for(auto node: y) sphAdd(ans, node);
    return ans;
}
vector<Shape> sphTrunc(vector<Shape> &shapes) {
    sort(shapes.begin(), shapes.end());
    vector<Shape> ans = {shapes[0]};
    for(auto shape: shapes) {
        if (shape == ans.back()) continue;
        ans.pb(shape);
    }
    return ans;
}
vector<Shape> shpJoinOnBorder(Shape &x, Shape &y) {
    vector<Shape> ans;
    Shape borderY = shpBorder(y);
    for(auto nodeY: borderY) {
        for(auto nodeX: x) {
            Node diff = {nodeY.f-nodeX.f, nodeY.s-nodeX.s};
            Shape translatedShape = shpTranslate(x, diff);
            Shape shape = sphJoin(translatedShape, y);
            if (shape.size() != x.size() + y.size()) continue;
            shpNormalize(shape);
            ans.pb(shape);
        }
    }
    ans = sphTrunc(ans);
    return ans;
}
vector<Shape> sphJoinOnBorderMultiple(vector<Shape> &shapes, Shape x) {
    vector<Shape> ans;
    for(auto shape: shapes) {
        vector<Shape> arrShapes = shpJoinOnBorder(shape, x);
        ans.insert(ans.end(), arrShapes.begin(), arrShapes.end());
    }
    ans = sphTrunc(ans);
    return ans;
}

signed main() {
    bool subTask1 = true, subTask2 = true, subTask3 = true, subTask4 = true;
    if (subTask1) {
        // int t; cin >> t;
        // while(t--) {
            char c1, c2; cin >> c1 >> c2;
            Shape s1 = shapeFromLetter(c1);
            Shape s2 = shapeFromLetter(c2);
            cout << shpJoinOnBorder(s1, s2).size() << "\n";
        // }
    }
    vector<char> letters = {'F', 'G', 'I', 'L', 'J', 'N', 'M', 'P', 'Q', 'T', 'U', 'V', 'W', 'X', 'Z', 'S', 'Y', 'A'};
    if (subTask2) {
        Shape x = X, w = W;
        vector<Shape> xwShapes = shpJoinOnBorder(x, w);
        int ans = 0;
        for(auto shape: xwShapes) {
            bool found = false;
            for(auto c1: letters) {
                if (c1 == 'X' || c1 == 'W') continue;
                Shape s1 = shapeFromLetter(c1);
                for(auto c2: letters) {
                    if (c2 == 'X' || c2 == 'W') continue;
                    Shape s2 = shapeFromLetter(c2);
                    vector<Shape> otherShapes = shpJoinOnBorder(s1, s2);
                    if (find(otherShapes.begin(), otherShapes.end(), shape) != otherShapes.end()) {
                        ans++; //cout << c1 << c2 << " ";
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        cout << "B: " << ans << "\n";
    }
    if (subTask3) {
        Shape i1=I, i2=I, i3=I;
        vector<Shape> shapesI2 = shpJoinOnBorder(i1, i2);
        vector<Shape> shapesI3 = sphJoinOnBorderMultiple(shapesI2, i3);
        cout << "C: III = " << shapesI3.size() << "\n";
        Shape l=L, i=I, v=V;
        vector<Shape> shapesLI = shpJoinOnBorder(l, i);
        vector<Shape> shapesLIV = sphJoinOnBorderMultiple(shapesLI, v);
        vector<Shape> shapesIV = shpJoinOnBorder(i, v);
        vector<Shape> shapesIVL = sphJoinOnBorderMultiple(shapesIV, l);
        vector<Shape> shapesVL = shpJoinOnBorder(v, l);
        vector<Shape> shapesVLI = sphJoinOnBorderMultiple(shapesVL, i);
        shapesLIV.insert(shapesLIV.end(), shapesIVL.begin(), shapesIVL.end());
        shapesLIV.insert(shapesLIV.end(), shapesVLI.begin(), shapesVLI.end());
        shapesLIV = sphTrunc(shapesLIV);
        cout << "C: LIV = " << shapesLIV.size() << "\n";
    }
    if (subTask4) {
        int ans = 0;
        for(int i=0; i<letters.size(); i++) {
            Shape a = shapeFromLetter(letters[i]);
            for(int j=i; j<letters.size(); j++) {
                Shape b = shapeFromLetter(letters[j]);
                vector<Shape> arrShapes = shpJoinOnBorder(a, b);
                for (auto shape: arrShapes) {
                    if (haveHoleInside(shape)) {
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << "D: " << ans << "\n";
    }
    return 0;
}
