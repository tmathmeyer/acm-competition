#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define K 6

typedef struct{
  int pos1;
  int pos2;
  int pos3;
} hashstruct;

vector<int> nums;
vector<int> solutionArr;
map<long long, vector<hashstruct> > hashM;

bool hasNoDuplicates(const hashstruct& h1, const hashstruct& h2) {
  return (h1.pos1 != h2.pos1) && (h1.pos1 != h2.pos2) && (h1.pos1 != h2.pos3) &&
    (h1.pos2 != h2.pos1) && (h1.pos2 != h2.pos2) && (h1.pos2 != h2.pos3) &&
    (h1.pos3 != h2.pos1) && (h1.pos3 != h2.pos2) && (h1.pos3 != h2.pos3);
}

bool isSolution(const vector<hashstruct>& hashArr,
		const hashstruct& pos) {
  int len = hashArr.size();
  for(int i = 0; i < len; ++i) {
    if(hasNoDuplicates(hashArr[i], pos)) {
      solutionArr.push_back(pos.pos1);
      solutionArr.push_back(pos.pos2);
      solutionArr.push_back(pos.pos3);
      solutionArr.push_back(hashArr[i].pos1);
      solutionArr.push_back(hashArr[i].pos2);
      solutionArr.push_back(hashArr[i].pos3);

      sort(solutionArr.begin(), solutionArr.end());
      
      return true;
    }
  }
  return false;
}

void printBits(int x) {
  unsigned int uintx = (unsigned int) x;
  for(int i = 0; i < 32; ++i){
    if((x & 1) == 1) {
      cout << '1';
    }
    else {
      cout << '0';
    }
    x >>= 1;
  }
}

void printSolution() {
  for(int i = 0; i < K; ++i) {
    printBits(nums[solutionArr[i]]);
  }
  cout << '\n';
}

void printVector(const vector<hashstruct>& v) {
  cout << "vector-print:";
  for(int i = 0; i < v.size(); ++i) {
    cout << "i,j,k:" << v[i].pos1 << " " << v[i].pos2 << " " << v[i].pos3 << '\n';
  }
  cout << "uptohere\n";
}

int main() {
  int N; cin >> N;
    
  for(int i = 0; i < N; ++i) {
    int x; cin >> x;
    nums.push_back(x);
  }

  for(int i = 0; i < N-2; ++i) {
    for(int j = i + 1; j < N-1; ++j) {
      for(int k = j + 1; k < N; ++k) {
	long long sum = (long long) nums[i] + nums[j] + nums[k];
	hashstruct pos; pos.pos1 = i; pos.pos2 = j; pos.pos3 = k;
	if(hashM.find(sum) != hashM.end()) {
	  hashM[sum].push_back(pos);
	}
	else {
	  vector<hashstruct> posArr; posArr.push_back(pos);
	  hashM.insert(pair<long long, vector<hashstruct> >(sum, posArr));
	}
      }
    }
  }
  
  for(int i = 0; i < N-2; ++i) {
    for(int j = i + 1; j < N-1; ++j) {
      for(int k = j + 1; k < N; ++k) {
	long long sum = (long long) nums[i] + nums[j] + nums[k];
	hashstruct pos; pos.pos1 = i; pos.pos2 = j; pos.pos3 = k;
	if(hashM.find(-sum) != hashM.end()) {
	  if(isSolution(hashM[-sum], pos)) {	    
	    printSolution();	    
	    exit(0);
	  }
	}
      }
    }
  }

  return 0;
}
