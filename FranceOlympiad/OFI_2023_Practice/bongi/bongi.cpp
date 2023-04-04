#include <bits/stdc++.h>
#include "helpers.hpp"
using namespace std;

bool merge(vector<int>&a, vector<int>&b) {
  int sum1=accumulate(a.begin(), a.end(), 0), sum2=accumulate(b.begin(), b.end(), 0);
  for(int k=0; k<a.size(); k++) for(int l=0; l<b.size(); l++) {
    int diff1=abs(sum1-sum2), diff2 = abs((sum1-a[k]+b[l])-(sum2+a[k]-b[l]));
    if(diff1 > diff2) {
      swap(a[k], b[l]);
      return true;
    }
  }
  for(int i=0; i<a.size(); i++) {
    int diff1=abs(sum1-sum2), diff2 = abs((sum1-a[i])-(sum2+a[i]));
    if(diff1 > diff2) {
      b.push_back(a[i]);
      a.erase(a.begin()+i);
      return true;
    }
  }
  for(int i=0; i<b.size(); i++) {
    int diff1=abs(sum1-sum2), diff2 = abs((sum1+b[i])-(sum2-b[i]));
    if(diff1 > diff2) {
      a.push_back(b[i]);
      b.erase(b.begin()+i);
      return true;
    }
  }
  return false;
}

int main()
{
  //////////////////////////////////////////////////
  // read the input
  
  int N, K;
  cin >> N >> K;
  
  vector<int> a(N);
  for (int i=0; i<N; i++)
    cin >> a[i];
  
  vector<vector<int> > solution(K);
  
  //////////////////////////////////////////////////
  // TODO: replace this by a smart algorithm
  
    for(int i=0; i<N; i++) solution[i % K].push_back(a[i]);
    bool found = true;
    while(found) {
      found = false;
      for(int i=0; i<K; i++) for(int j=i+1; j<K; j++) {
        if(merge(solution[i], solution[j])) {
          found = true;
        }
      }
    }
  
  //////////////////////////////////////////////////
  // print the solution 
  
  // functions in bongi.hpp
  cerr << "score = " << get_score(solution) << endl;
  cerr << "percentage = " << get_percentage(solution) << "%" << endl;
  
  for (int k=0; k<(int)solution.size(); k++)
  {
    for (int j=0; j<(int)solution[k].size(); j++)
    {
      if (j) cout << " ";
      cout << solution[k][j];
    }
    cout << endl;
  }
}
