#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int>& v) {
	int res = 0, sz = v.size();
	
	for(size_t i = 0; i < sz; ++i) {
		while(v.at(i) >= 1 and v.at(i) <= sz && v.at(i) != v[v.at(i)-1]) {
			swap(v.at(i), v[v.at(i)-1]);
		}
	}
	for(size_t i = 0; i < sz; ++i) {
		if (v.at(i) != i + 1) {
			return i + 1;
		}
	}
	
	return sz + 1;
}

int main() {	
	vector<int> vec{3, 4, 2, 5, 6, 8, 1};
	int res = findMissingNumber(vec);
	cout << res;
  
	return 0;
}
