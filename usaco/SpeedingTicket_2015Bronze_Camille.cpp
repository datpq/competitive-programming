#include <bits/stdc++.h>
using namespace std;

signed main(){
    ifstream in("speeding.in");
    ofstream out("speeding.out");
    int n, m; in >> n >> m;
    vector<int> vn(100), vm(100);
    int dis=0;
    for(int i=0; i<n; i++){
        int a, b; in >> a >> b;
        for(int x=dis; x<a+dis; x++) vn[x]=b;
        dis+=a;
    }
    dis=0;
    for(int i=0; i<m; i++){
        int a, b; in >> a >> b;
        for(int x=dis; x<a+dis; x++) vm[x]=b;
        dis+=a;
    }
    int ans=0;
    for(int i=0; i<100; i++)ans=max(ans, vm[i]-vn[i]);
    out << ans;
    return 0;
}
