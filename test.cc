#include<bits/stdc++.h>
using namespace std;


 
int main(int argc, char** argv) {
  const int n = 4;
  vector<vector<int>> edges{{1,2,2},{2,3,2},{3,4,2},{4,1,2},{1,3,2},{2,4,2}};    
  vector<vector<int>> q; // (w, u, v)  
  for (const auto& e : edges)    
    q.push_back({e[2], e[0], e[1]});
  sort(begin(q), end(q));
 
  vector<int> p(n);
  iota(begin(p), end(p), 0);
 
  function<int(int)> find = [&](int x) {
    return x == p[x] ? x : p[x] = find(p[p[x]]);
  };
 
  int cost = 0;
  for (const auto& t : q) {    
    int w = t[0], u = t[1], v = t[2];      
    int ru = find(u), rv = find(v);      
    if (ru == rv) continue;
    p[ru] = rv; // merge (u, v)      
    cost += w;
  }  
  cout << cost << endl;
 
  return 0;
}