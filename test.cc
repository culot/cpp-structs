#include <cassert>
#include <iostream>

#include "splaytree.h"

int main(void) {
  Splaytree<int> tree;

  std::cout << "Check that tree is initially empty... ";
  assert(tree.size() == 0);
  std::cout << "OK" << std::endl;

  std::cout << "Insert a node and check that tree contains exactly 1 element... ";
  tree.insert(100);
  assert(tree.size() == 1);
  std::cout << "OK" << std::endl;

  std::cout << "Check that tree contains the previously inserted value... ";
  Splaytree<int>::Iterator it = tree.begin();
  assert(*it == 100);
  std::cout << "OK" << std::endl;

  tree.insert(5).insert(71).insert(12028).insert(13);

  assert(tree.size() == 5);

  return 0;
}
