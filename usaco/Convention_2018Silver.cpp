#include <bits/stdc++.h>
#include <fstream>
#define int long long
using namespace std;

vector<int> v;
int n, m, c;

bool check(int mid){
    int cnt=1, mn=v[0], bus=0;
    for(int i=1; i<n; i++){
        if(v[i]-mn > mid || cnt >= c){
            bus++; cnt=1; mn=v[i];
        }else cnt++;
    }
    if(bus+1 > m) return false;
    else return true;
}

int firstTrue(int lo, int hi){
    hi++;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

signed main(){
    ifstream ifs("convention.in");
    ofstream ofs("convention.out");
    ifs >> n >> m >> c;
    //cows, buses, max cows in bus
    v = vector<int>(n);
    for(int i=0; i<n; i++) ifs >> v[i];
    sort(v.begin(), v.end());
    ofs << firstTrue(0, 1e9) << "\n";
}