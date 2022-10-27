#include <iostream>
#include <cmath>
using namespace std;

int low, high;
int sol; // 정답

void InputData()
{
        cin >> low;
        cin >> high;
}
void OutputData()
{
        cout << sol << "\n";
}
void Solve() {
        int divs[high + 10];
        for (int i = 1; i <= high; i++) divs[i] = 0;

        for (int i = 2; i <= sqrt(high); i++) {
                int base = pow(i, 2);
                int prod = 1;

                while (base * prod <= high) {
                        divs[base * prod] = 1;
                        prod++;
                }
        }

        for (int i = low; i <= high; i++) {
                if (!divs[i]) ++sol;
        }
}
int main()
{

        InputData(); // 입력

        // 코드를 작성하세요
        Solve();

        OutputData(); // 출력
        return 0;
}
