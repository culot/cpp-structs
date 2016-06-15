#pragma once

/*
 * Splay tree - a self-Adjusting binary search tree,
 * as first described by Daniel Dominic Sleator and Robert Endre Tarjan.
 *
 * https://www.cs.cmu.edu/~sleator/papers/self-adjusting.pdf
 */
template<class T>
class Splaytree {
  private:
    struct Node {
      Node*  left;
      Node*  right;
      Node*  parent;
      T      data;

      void   rotateLeft()   {}
      void   rotateRight()  {}
      void   splay()        {}
    };

  public:
    void   insert(const T& data) {}
    void   remove(const T& data) {}
    Node*  find(const T& data)   {}
};
