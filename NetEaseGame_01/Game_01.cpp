/*
3
1 00100110010
3 000011
2 11111
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int l = 0; l < N; l++) {
        int k;
        string s;
        cin >> k;
        getchar();
        getline(cin, s);
        
        int zero_before = 0, longgest_zero = 0;
        for (int i = 0; i < s.length()-k+1; i++) {
            int zero_before_cur = 0, zero_tail_cur = 0, zero_mid = 0;
            bool is_all_zero = true, count_before = true;
            for (int j = 0; j < k; j++) {
                if (s[i + j] == '0') {
                    is_all_zero = false;
                    count_before = false;
                }
                if (count_before && s[i + j] == '1') {
                    zero_before_cur++;
                }
                if (!count_before && s[i + j] == '1') {
                    zero_tail_cur++;
                }
                if (!count_before && s[i + j] == '0') {
                    zero_mid = zero_tail_cur > zero_mid ? zero_tail_cur : zero_mid;
                    zero_tail_cur = 0;
                }
            }
            zero_before_cur += zero_before;
            int zero_tail = 0;
            for (int j = i + k; j < s.length(); j++) {
                if (s[j] == '0') zero_tail++;
                else break;
            }
            if (is_all_zero) {
                zero_before_cur += zero_tail;
            }
            if (s[i + k - 1] == '1') {
                zero_tail_cur += zero_tail;
            }
            zero_before_cur = zero_tail_cur > zero_before_cur ? zero_tail_cur : zero_before_cur;
            longgest_zero = zero_before_cur > longgest_zero ? zero_before_cur : longgest_zero;
            longgest_zero = zero_mid > longgest_zero ? zero_mid : longgest_zero;
            if (s[i] == '0') zero_before++;
            else zero_before = 0;
        }
        cout << longgest_zero << endl;
    }
    return 0; 
}
