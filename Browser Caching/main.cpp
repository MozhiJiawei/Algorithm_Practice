/*Input:
5 2
www.bing.com
www.microsoft.com
www.microsoft.com
windows.microsoft.com
www.bing.com
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main() {
    int N, M;
    list<string> cache;
    list<string>::iterator itr;
    string URL;
    bool cached = false;
    cin >> N >> M;
    getline(cin, URL);
    for (int i = 0; i < N; i++) {
        getline(cin, URL);
        for (itr = cache.begin(); itr != cache.end(); ++itr) {
            if (URL == *itr) {
                cached = true;
                cache.erase(itr);
                cache.push_back(URL);
                break;
            }
        }
        if (cached) {
            cout << "Cache" << endl;
        }
        else {
            cout << "Internet" << endl;
            if (cache.size() < M) {
                cache.push_back(URL);
            }
            else {
                cache.pop_front();
                cache.push_back(URL);
            }
        }
        cached = false;

    }
    return 0;
}
