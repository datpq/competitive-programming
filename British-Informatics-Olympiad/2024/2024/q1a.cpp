#include <bits/stdc++.h>
#define int long long
using namespace std;

char solve(int n, int idx){
    string cur = to_string(n);
    int nxt = pow(10, cur.size());
    //cout << n << ' ' << idx << "\n";
    if((nxt-n)*cur.size() <= idx){
        return solve(nxt, idx-((nxt-n)*cur.size()));
    }else{
        int step = idx/cur.size();
        n += step;
        idx -= step*cur.size();
        string ans = to_string(n);
        string other = to_string(n-1);
        //cout << n << ' ' << idx << "\n";
        if(idx != 0) return ans[idx-1];
        else return other[other.size()-1];
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, idx; cin >> n >> idx;
    string ans = to_string(n);
    if(idx > ans.size()) cout << solve(n, idx) << "\n";
    else cout << ans[idx-1] << "\n";
}
