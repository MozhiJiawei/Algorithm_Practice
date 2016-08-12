#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

char * myitoa(int n);
void fun(char *w, int m);

int main(){
    char s[] = "123456789";
    fun(s, 3);
    cout << s << endl;
    system("pause");
	return 0;
}

void fun(char *w, int m) {
    int i = 0, len = strlen(w);
    if (m > len) m = len;
    while (m > 0) { 
        if (len == m) {
            m = 0;
            break;
        }
        for (i = len; i > 0; i--) { 
            w[i] = w[i - 1];
        }
        w[0] = w[len];
        m--;
    }
    w[len - m] = '\0';
}

char * myitoa(int n) {
    char* a;
    a = new char[8];
    bool is_minus = n < 0 ? true : false;
    int i = 0;
    n = abs(n);
    do {
        int temp;
        temp = n % 10;
        n = n / 10;
        a[i] = temp + '0'; 
        i++;
    } while (n != 0);
    if (is_minus) {
        a[i] = '-';
        a[i + 1] = '\0';
    }
    else {
        a[i] = '\0';
    }
    int j = 0;
    while (j <= i-1) { 
        int temp;
        temp = a[i-1];
        a[i-1] = a[j];
        a[j] = temp;
        i--;
        j++;
    }
    cout << a << endl;
    return a;
}
