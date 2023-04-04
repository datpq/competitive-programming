#include <vector>
#include <cmath>
using namespace std;

// this functions returns the score of the best judge solution
double get_best(int S)
{
  if (S == 84) return 42;
  if (S == 95800) return 9564.453334019241;
  if (S == 552377) return 55237.69999809915;
  if (S == 506484) return 25324.1999731493;
  if (S == 509405) return 16980.161334096203;
  if (S == 555481) return 13886.860798648839;
  if (S == 504425) return 10086.367502580433;
  if (S == 504917) return 8392.505093895417;
  cerr << "warning: test not found" << endl;
  return 0;
}

// this function compute the percentage of points scored
double get_score(vector<vector<int> > solution) {
  double X = 1; // score of contestant
  int K = solution.size(); // number of buckets

  for (int k=0; k<K; k++) {
    int tmp = 0;
    for (int j=0; j<(int)solution[k].size(); j++) {
      tmp += solution[k][j];
    }
    X *= pow(tmp, 1./K);
  }

  return X;
}

double get_percentage(vector<vector<int> > solution) {
  int S = 0; // sum of values
  int K = solution.size(); // number of buckets

  for (int k=0; k<K; k++) {
    for (int j=0; j<(int)solution[k].size(); j++) {
      S += solution[k][j];
    }
  }
  
  double X = get_score(solution);
  double B = get_best(S); // score of judges
  return min(100*(10+S/(double)K-B)/(10+S/(double)K-X), 100.);
}
