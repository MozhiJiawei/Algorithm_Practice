/*BB FF
HH FF EE*/
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {
    string input;
    map<string, bool> foods;
    //while (getline(cin, input)) {
    //    stringstream ss; 
    //    string food_type;
    //    ss.clear();
    //    ss.str(input);
    //    while (getline(ss, food_type, ' ')) { 
    //        foods[food_type] = true;
    //    }
    //}
    while (cin >> input) {
        foods[input] = true;
    }
    cout << foods.size() << flush;
    system("pause");
    return 0; 
}