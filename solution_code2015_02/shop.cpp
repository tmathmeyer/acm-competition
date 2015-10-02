#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main() {
  long long N,M; cin >> N >> M;

  //  cout << "N:" << N <<" M:" << M << "\n";
  vector<int> costs;
  
  for(int i = 0; i < M; ++i) {
    int cost; cin >> cost;
    costs.push_back(cost);
  }

  sort(costs.begin(), costs.end());

  /*
  for(int i = 0; i < M; ++i) {
    cout << costs[i] << " ";
  }
  cout << "\n";
  */
  
  long long sum = 0;
  int count = 0;
  for(int i = 0; i < M; ++i) {
    if((sum + costs[i]) > N) {
      break;
    }
    sum += costs[i];
    ++count;
  }
  cout << count << '\n';
  return 0;
}
