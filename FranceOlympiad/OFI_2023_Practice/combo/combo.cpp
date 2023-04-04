#include <bits/stdc++.h>
#include "combo.h"

using namespace std;

std::string guess_sequence(int N) {
  char a, b, x, y;

  //2 press to know a (first character)
  int coins = press("AB");
  if (coins) {
    coins = press("A");
    a = coins ? 'A' : 'B';
  } else {
    coins = press("X");
    a = coins ? 'X' : 'Y';
  }

  //determine a, b, x, y
  string S(1, a);
  string CH = "ABXY";
  string CH_a;
  for(int i=0; i<4; i++) {
    if (CH[i] != a) CH_a.push_back(CH[i]);
  }
  b = CH_a[0]; x = CH_a[1]; y = CH_a[2];
  cerr << "a=" << a <<", b=" << b << ", x=" << x << ", y=" << y << "\n";

  while(S.length() < N) {
    if (S.length() < N-1) {
      coins = press(S + b + b + S + b + x + S + b + y + S + x);
      if (coins == S.length() + 2) S+=b;
      else if (coins == S.length() + 1) S+=x;
      else S+= y;
    } else {
      coins = press(S + b);
      if (coins == S.length() + 1) S+=b;
      else {
        coins = press(S + x);
        if (coins == S.length() + 1) S+=x;
        else S += y;
      }
    }
  }
  return S;
}
