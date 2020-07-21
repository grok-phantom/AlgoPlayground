//
// Created by Lei Chen on 2020/7/21.
//

#ifndef ALGOPLAYGROUND_WEIGHTEDUF_H
#define ALGOPLAYGROUND_WEIGHTEDUF_H


#include <vector>

class WeightedUF {
  private:
    std::vector<int> id; // parent link (site indexed)
    std::vector<int> sz; // size of component for roots
    int count;           // number of components

  public:
    WeightedUF(int N);
    
    // return number of components
    int getCount();

    // true if p and q are int the same component, false otherwise
    bool connected(int p, int q);

    // find which component p is in
    int find(int p);

    // create union of components p and q
    void wfUnion(int p, int q);

    // get largest element in sz
    int getMax();
};


#endif //ALGOPLAYGROUND_WEIGHTEDUF_H
