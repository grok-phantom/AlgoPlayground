//
// Created by Lei Chen on 2020/7/21.
//

#ifndef ALGOPLAYGROUND_GRAPH_H
#define ALGOPLAYGROUND_GRAPH_H

#include <vector>

class Graph {
 private:
  struct Edge {
    int src, dest;

    Edge();

    Edge(int src_, int dest_);
  };

  std::vector<Edge> edges;
  int V;  // number of vertices
  int E;  // number of edges
 public:
  Graph();

  Graph(int num_vert);

  Graph(int num_vert, int num_edge);

  int getNumVert() const;

  int getNumEdges() const;

  void addEdge(int src, int dest);

  Edge getEdge(int index);

  void printEdges(int vertex);
};

#endif  // ALGOPLAYGROUND_GRAPH_H
