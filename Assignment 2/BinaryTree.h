#ifndef __BinaryTree_H
#define __BinaryTree_H

#include <sstream>
#include <queue>
#include <cmath>

#include "PDF.h" // for the PDF display

using namespace std;

/* A lightweight structure implementing a general binary tree node */
template <class T>
struct BTNode
{
  T elem;        // element contained in the node
  BTNode *left;  // pointer to the left child (can be NULL)
  BTNode *right; // pointer to the right child (can be NULL)

  // Constructors
  BTNode() { left = right = NULL; }
  BTNode(T elem, BTNode *left = NULL, BTNode *right = NULL)
  {
    this->elem = elem;
    this->left = left;
    this->right = right;
  }
  BTNode(const BTNode &src)
  {
    this->elem = src.elem;
    this->left = src.left;
    this->right = src.right;
  }

  // Simple tests
  bool is_leaf() const { return (left == NULL && right == NULL); }
};

/****************************************************************************
 *
 * CLASS:  BinaryTree
 *
 ****************************************************************************/

/* A 'BinaryTree' class implements a basic binary tree.  It serves
 * as a superclass for more specific types of binary trees, such as
 * a binary search tree.
 */

template <class T>
class BinaryTree
{
public:
  /* Construction */
  BinaryTree() { root = NULL; }
  BinaryTree(T *elements, int n_elements);
  BinaryTree(const BinaryTree &src);
  ~BinaryTree() { empty_this(); }

  /* Access and Tests */
  bool is_empty() const;
  int height() const { return height(root); }
  int node_count() const { return node_count(root); }
  int leaf_count() const { return leaf_count(root); }

  /* Mutators, and other Initialization */
  bool empty_this()
  {
    empty(root);
    root = NULL;
    return true;
  }
  void init_complete(T *elements, int n_elements);
  void init_complete_pre(T *elements, int n_elements)
  {
    int tree_height = complete_tree_height(n_elements);
    int extra = n_elements - pow(2, tree_height - 1) + 1;
    int index = 0;

    root = init_complete_pre(elements, n_elements, index, tree_height - 1, extra);
  }
  void init_complete_post(T *elements, int n_elements)
  {
    int tree_height = complete_tree_height(n_elements);
    int extra = n_elements - pow(2, tree_height - 1) + 1;
    int index = 0;

    root = init_complete_post(elements, n_elements, index, tree_height - 1, extra);
  }
  void init_complete_in(T *elements, int n_elements)
  {
    int tree_height = complete_tree_height(n_elements);
    int extra = n_elements - pow(2, tree_height - 1) + 1;
    int index = 0;

    root = init_complete_in(elements, n_elements, index, tree_height - 1, extra);
  }
  void shuffle()
  {
    queue<BTNode<T> *> q;
    root = shuffle(q, root);
  }
  int to_flat_array(T *elements, int max) const;
  void insert(T element) { root = insert(element, root); };
  void remove(T element)
  {
    root = remove(element, root);
    shuffle();
  };

  /* Traversal */
  void preorder(void (*f)(const T &)) const { return preorder(f, root); }
  void inorder(void (*f)(const T &)) const { return inorder(f, root); }
  void postorder(void (*f)(const T &)) const { return postorder(f, root); }

  /* Operators */
  // bool operator==(const BinaryTree &src) const;
  // bool operator!=(const BinaryTree &src) const;
  // BinaryTree &operator=(const BinaryTree &src) const;

  /* Input/Output */
  template <class S>
  friend ostream &operator<<(ostream &out, const BinaryTree<S> &src);

  /* Display */
  void display(PDF *pdf, const string &annotation = "") const;

protected:
  BTNode<T> *root; // Root node (NULL if the tree is empty)

  /* "Helper" functions for the basic operations */
  // BTNode<T> *clone(BTNode<T> *node);

  int height(BTNode<T> *node) const;
  // int balance_factor( BTNode<T>* node ) const;
  int node_count(BTNode<T> *node) const;
  int leaf_count(BTNode<T> *node) const;

  void preorder(void (*f)(const T &), BTNode<T> *node) const;
  void inorder(void (*f)(const T &), BTNode<T> *node) const;
  void postorder(void (*f)(const T &), BTNode<T> *node) const;

  void empty(BTNode<T> *node); // To empty the tree
  BTNode<T> *insert(T element, BTNode<T> *node);
  BTNode<T> *remove(T element, BTNode<T> *node);
  BTNode<T> *shuffle(queue<BTNode<T> *> &q, BTNode<T> *node);

  BTNode<T> *init_complete(T *elements, int n_elements, int index);
  BTNode<T> *init_complete_pre(T *elements, int n_elements, int &index, int max_height, int &extra);
  BTNode<T> *init_complete_post(T *elements, int n_elements, int &index, int max_height, int &extra);
  BTNode<T> *init_complete_in(T *elements, int n_elements, int &index, int max_height, int &extra);

  int complete_tree_height(int n_elements);

  int to_flat_array(T *elements, int max, BTNode<T> *node, int index,
                    int &max_index) const;
  void display(PDF *pdf, BTNode<T> *node, int leaf_dist,
               double x, double y, double scale) const;

  template <class S>
  friend ostream &operator<<(ostream &out, const BTNode<S> &src);
};

#include "BinaryTree.cpp"

#endif
