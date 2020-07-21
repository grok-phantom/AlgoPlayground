//
// Created by Lei Chen on 2020/7/21.
//

#include "Graph.h"

#include <iostream>

Graph::Graph() : V(1), E(0) {}

Graph::Graph(int num_vert) : V(num_vert), E(0) {}

Graph::Graph(int num_vert, int num_edge) : V(num_vert), E(num_edge) {}

int Graph::getNumVert() const { return V; }

int Graph::getNumEdges() const { return E; }

void Graph::addEdge(int src, int dest) {
  edges.emplace_back(src, dest);
  ++E;
}

Graph::Edge Graph::getEdge(int index) { return edges[index]; }

void Graph::printEdges(int vertex) {
  for (const auto& edge : edges) {
    if (edge.src == vertex) {
      std::cout << edge.src << "->" << edge.dest << '\n';
    }
  }
}

Graph::Edge::Edge() : src(0), dest(0) {}
Graph::Edge::Edge(int src_, int dest_) : src(src_), dest(dest_) {}
