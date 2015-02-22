#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef struct {
  double X;
  double Y;
} Point;

double distanceSquared(const Point& p1, const Point& p2) {
  double distX = p1.X - p2.X;
  double distY = p1.Y - p2.Y;
  return distX * distX + distY * distY;
}

bool isRhombus(const vector<Point>& quadrilateral) {
  int len = quadrilateral.size();
  map<double, int> lengths;
  for(int i = 0; i < len - 1; ++i) {
    for(int j = i + 1; j < len; ++j) {
      double dist = distanceSquared(quadrilateral[i], quadrilateral[j]);
      if(lengths.find(dist) == lengths.end()) {
	lengths.insert(pair <double, int>(dist, 1));
      }
      else {
	++lengths[dist];
	if(lengths[dist] == 4) {
	  return true;
	}
      }
    }
  }
  return false;
}
   
int main() {
  int N; cin >> N;
  vector<Point> coordinates;
  for(int i = 0; i < N; ++i) {
    int x,y; cin >> x >> y;
    Point point; point.X = (double) x; point.Y = (double) y;
    coordinates.push_back(point);
  }

  long long count = 0;
  
  for(int i = 0; i < N - 3; ++i) {
    for(int j = i + 1; j < N - 2; ++j) {
      for(int k = j + 1; k < N - 1; ++k) {
	for(int p = k + 1; p < N; ++p ) {
	  vector<Point> quadrilateral;
	  quadrilateral.push_back(coordinates[i]);
	  quadrilateral.push_back(coordinates[j]);
	  quadrilateral.push_back(coordinates[k]);
	  quadrilateral.push_back(coordinates[p]);
	  if(isRhombus(quadrilateral)) {
	    ++count;
	  }
	}
      }
    }
  }
  cout << count << '\n';
  return 0;
}
