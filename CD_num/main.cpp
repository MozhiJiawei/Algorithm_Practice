#include <iostream>
using namespace std;

int main() {
    int n, s, L;
    cin >> n >> s >> L;
    int num_per_CD;
    num_per_CD = L / (s + 1);
    if ((s + 1)*(num_per_CD + 1) == L + 1) num_per_CD++;
    if (num_per_CD % 13 == 0) num_per_CD--;
    int add = 0;
    if (n <= num_per_CD && n % 13 == 0) add = 1;
    int num_in_lastCD;
    num_in_lastCD = n % num_per_CD;
    if (num_in_lastCD != 0 && num_in_lastCD % 13 == 0 && num_in_lastCD == num_per_CD - 1) add = 1;
    if (n % num_per_CD == 0) cout << (n / num_per_CD) + add << flush;
    else cout << (n / num_per_CD) + 1 + add << flush;
    return 0;
}