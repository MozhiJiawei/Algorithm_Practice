#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;
class Vertex;

void Dijkstra(Vertex s) {
  for (;;/*each Vertex v*/) {
    v.dist = INFINITY;
    v.known = false;
  }

  s.dist = 0;
  for (;;) {
    Vertex v = min(/*unknown distance vertex*/);
    if (v == NOT_A_VERTEX) {
      break;
    }
    v.known = true;

    for (;;/*each Vertex w adjacent to v*/) {
      if (!w.known) {
        if (v.dist + cvw < w.dist) {
          //update w
          w.dist = v.dist + cvw;
          w.path = v;
        }
      }
    }
  }
}

map<string, string> findChain(const map<string, vector<string> > &adjacentWords,
  const string &first) {

  map<string, string> previousWord;
  queue<string> q;

  q.push(first);
  while (!q.empty()) {
    string current = q.front();
    q.pop();

    map<string, vector<string> >::const_iterator itr;
    itr = adjacentWords.find(current);
    const vector<string> &adj = itr->second;

    for (int i = 0; i < adj.size(); i++) {
      if (previousWord[adj[i]] == "") {
        previousWord[adj[i]] = current;
        q.push(adj[i]);
      }
    }
  }
  previousWord[first] = "";
  return previousWord;
}

vector<string> getChainFromPrevMap(const map<string, string> &previous,
    const string &second) {

  vector<string> result;
  map<string, string> &prev = const_cast<map<string, string> &>(previous);

  for (string current = second; current != ""; current = prev[current]) {
    result.push_back(current);
  }
  reverse(result.begin(), result.end());
  return result;
}
