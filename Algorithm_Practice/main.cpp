/*Input
6 5 2 1
0 0 1 2 2
3 1 1 3 7
4 3 1 3 7
4 3 0 3 2
4 3 3 0 1
4 5 5 5 5
*/
#include <iostream>
#include <vector>
using namespace std;

int N_, M_, x_, y_;
vector<vector<int> > data_input_;
vector<vector<bool> > data_searched_;

int Search(int x, int y) {
    int side_length = 0;
    int surrounded = 0;
    data_searched_[x][y] = true;
    //up
    if (x != 0) {
        if(data_input_[x - 1][y] == data_input_[x][y]) {
            if (data_searched_[x - 1][y] == false) {
                side_length += Search(x - 1, y);
            }
            surrounded++;
        }
    }
    //down
    if (x != N_ - 1) {
        if( data_input_[x + 1][y] == data_input_[x][y]) {
            if (data_searched_[x + 1][y] == false) {
                side_length += Search(x + 1, y);
            }
            surrounded++;
        }
    }
    //left
    if (y != 0) {
        if( data_input_[x][y - 1] == data_input_[x][y]) {
            if (data_searched_[x][y - 1] == false) {
                side_length += Search(x, y - 1);
            }
            surrounded++;
        }
    }
    //right
    if (y != M_ - 1) {
        if(data_input_[x][y + 1] == data_input_[x][y]) {
            if (data_searched_[x][y + 1] == false) {
                side_length += Search(x, y + 1);

            }
            surrounded++;
        }
    }
    side_length += 4 - surrounded;
    return side_length;
}

int main() {
    vector<int> datas_in;
    vector<bool> searched_init;
    int data_in, R;
    cin >> N_ >> M_ >> x_ >> y_;
    for (int i = 0; i < N_; i++) {
        for (int j = 0; j < M_; j++) {
            cin >> data_in;
            datas_in.push_back(data_in);
            searched_init.push_back(false);
        }
        data_input_.push_back(datas_in);
        data_searched_.push_back(searched_init);
        datas_in.clear();
        searched_init.clear();
    }
    R = Search(x_, y_);
    cout << R << endl;
    return 0;
}