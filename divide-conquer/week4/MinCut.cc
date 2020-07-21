//
// Created by Lei Chen on 2020/7/19.
//

#include <fstream>
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "Graph.h"
#include "WeightedUF.h"

using namespace std;

int kargerMinCut(Graph &graph) {
  WeightedUF uf(graph.getNumVert());

  while (uf.getCount() > 2) {
    int randEdge = rand() % graph.getNumEdges();
    int src = graph.getEdge(randEdge).src;
    int dest = graph.getEdge(randEdge).dest;
    int comp1 = uf.find(src);
    int comp2 = uf.find(dest);
    if (comp1 == comp2)
      continue;
    else {
      uf.wfUnion(src, dest);
    }
  }

  int cutedges = 0;
  for (int i = 0; i < graph.getNumEdges(); ++i) {
    int subset1 = uf.find(graph.getEdge(i).src);
    int subset2 = uf.find(graph.getEdge(i).dest);
    if (subset1 != subset2) ++cutedges;
  }
  return cutedges;
}

// random_device r;
// default_random_engine e(r());
// uniform_int_distribution<int> uniform_dist()

void LoadFile(const string &file_path, Graph &graph) {
  ifstream infile(file_path);
  string line;
  while (getline(infile, line)) {
    stringstream ss(line);
    int src, dest;
    ss >> src;
    vector<int> temp;
    while (ss >> dest) {
      if (dest > src) {
        graph.addEdge(src, dest);
      }
    }
  }
  infile.close();
}

int main() {
  srand(time(NULL));
  constexpr int SIZE = 200;
  constexpr int TIMES = 50;  // number of times to run Karger's
  int min = 200;
  Graph graph(SIZE);
  LoadFile("../divide-conquer/kargerMinCut.txt", graph);
  for (int i = 0; i < TIMES; ++i) {
    int ans = kargerMinCut(graph);
    if (ans < min) min = ans;
  }
  return 0;
}

