/*
4
MUC
LHR
JFK
MUC
SFO
SJC
LHR
SFO
*/
#include <iostream>

#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            graph_[tickets[i].first].insert(tickets[i].second);
        }
        visit("JFK");
        //for (int i = 0, j = result_.size() - 1; i < j; i++, j--) {
        //    swap(result_[i], result_[j]);
        //}
        reverse(result_.begin(), result_.end());
        return result_;
    }
    void visit(const string &from) {
        while(!graph_[from].empty()) {
            string to = *graph_[from].begin();
            graph_[from].erase(graph_[from].begin());
            visit(to);
        }
        result_.push_back(from);
    }
private:
    vector<string> result_;
    map<string, multiset<string> > graph_;
};

int main() {
    vector<pair<string, string> > tickets;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string from, to;
        getline(cin, from);
        if (from == "") {
            getline(cin, from);
        }
        getline(cin, to);
        pair<string, string> input(from, to);
        tickets.push_back(input);
    }
    Solution solution;
    solution.findItinerary(tickets);
    return 0;
}