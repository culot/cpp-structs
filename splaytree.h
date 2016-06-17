#pragma once

#include <cstddef>
#include <stdexcept>
#include <queue>

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
      Node*  left_   {nullptr};
      Node*  right_  {nullptr};
      Node*  parent_ {nullptr};
      T      data_;

      Node() {}
      Node(const T& data, Node* parent)
        : parent_(parent), data_(data) {}

      void rotateLeft() {}

      /*
       *       y                      x
       *      / \                    / \
       *     x   c   ----------->   a   y
       *    / \      rotate right      / \
       *   a   b                      b   c
       *
       */
      void rotateRight()  {
        if (!parent_) {
          return;
        }
        if (right_) {
          parent_->left_ = right_;
          right_->parent_ = parent_;
        }
        parent_->parent_ = this;
        right_ = parent_;
        parent_ = nullptr;
      }

      void splay() {}
    };

//    static Node nullnode;

    std::size_t  size_ {0};

    void insert(const T& data, Node*& node, Node* parent = nullptr) {
      if (!node) {
        node = new Node(data, parent);
        ++size_;
      } else {
        if (data < node->data_) {
          insert(data, node->left_, node);
        } else {
          insert(data, node->right_, node);
        }
      }
    }

  public:
    struct Iterator {
      Iterator(const Node* node)
        : node_(node) {}

      bool operator!=(const Iterator& other) const {
        return node_ != other.node_;
      }

      const T& operator*() const {
        if (node_) {
          return node_->data_;
        } else {
          throw std::out_of_range("Invalid node");
        }
      }

      // Breadth-First Search used for tree traversal
      const Iterator& operator++() {
        if (!queue_.empty()) {
          node_ = queue_.pop();
        }
        if (node_->left_) {
          queue_.push(node_->left_);
        }
        if (node_->right_) {
          queue_.push(node_->right_);
        }
        return *this;
      }

      private:
        std::queue<const Node*>  queue_;
        const Node*              node_ {nullptr};
    };

    Node* root_ {nullptr};

    Iterator begin() const {return Iterator(root_);}
    Iterator end()   const {return Iterator(nullptr);}

    Splaytree& insert(const T& data) {
      insert(data, root_);
      return *this;
    }

    std::size_t size() const          {return size_;}
    void        remove(const T& data) {}
    Node*       find(const T& data)   {}
};

// template<class T>
// struct Splaytree<T>::Node Splaytree<T>::nullnode;
