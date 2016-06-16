#include <cassert>
#include <iostream>

#include "splaytree.h"

int main(void) {
  Splaytree<int> tree;

  assert(tree.size() == 0);

  tree.insert(100);
  assert(tree.size() == 1);

  Splaytree<int>::Iterator it = tree.begin();
  assert(*it == 100);

  tree.insert(5).insert(71).insert(12028).insert(13);

  assert(tree.size() == 5);

  return 0;
}
