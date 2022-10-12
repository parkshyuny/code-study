#include <iostream>
#include <stack>
using namespace std;

int N;//히스토그램수
int H[100000+10];//히스토그램 높이

struct INFO {
	int height;
	int index;
};

bool InputData() {
    cin >> N;
    if (N == 0) return false;
    
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    return true;
}
long long Solve() {
	stack<INFO> s = {};
	long long sol = -1;
	int i, nidx;

	s.push({H[0], 0});
	for (i = 0; i < N; i++) {
		nidx = i;
		while (!s.empty() && s.top().height > H[i]) {
			INFO htop = s.top();
			nidx = htop.index;
			long long res = (long long) htop.height * (i-htop.index);
			if (res > sol) sol = res;
			s.pop();
		}
		s.push({H[i], nidx});
	}

	while (!s.empty()) {
		INFO htop = s.top();
		long long res = (long long)htop.height * (i-htop.index);
		if (res > sol) sol = res;
		s.pop();
	}
	return sol;
}

int main() {
    long long ans = -1;
    while(InputData()){//입력받는 부분

        //여기서부터 작성
        ans = Solve();
        cout << ans << endl;//출력하는 부분
    }
    return 0;
}
