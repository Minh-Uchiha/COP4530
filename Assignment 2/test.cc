#include "BinaryTree.h"
#include "PDF.h"
#include <iostream>
#include <string>

using namespace std;

void handle_insert(BinaryTree<char> &tree)
{
  cout << "Please enter the element you want to insert to the tree\n";
  char c;
  cin >> c;
  tree.insert(c);
}

void handle_delete(BinaryTree<char> &tree)
{
  cout << "Please enter the element you want to delete from the tree\n";
  char c;
  cin >> c;
  tree.remove(c);
}

void handle_print(BinaryTree<char> &tree)
{
  PDF *pdf = new PDF("trees.pdf");

  // Draw the tree
  ostringstream ostring;
  ostring << "Complete tree having " << tree.node_count() << " nodes";
  tree.display(pdf, ostring.str());

  // Finish the PDF object
  pdf->finish();
  delete pdf;

  cout << "A drawing of the tree is saved in the file trees.pdf\n";
}

void menu(BinaryTree<char> &tree, bool &resume)
{

  int option = 5;
  cout << "Please choose 1 of the following options: (Enter a number 1 -> 4)\n";
  cout << "\t1. Insert\n"
       << "\t2. Delete\n"
       << "\t3. Print\n"
       << "\t4. Quit\n";
  cin >> option;
  switch (option)
  {
  case 1:
    handle_insert(tree);
    break;
  case 2:
    handle_delete(tree);
    break;
  case 3:
    handle_print(tree);
    break;
  case 4:
    cout << "Goodbye!\n";
    resume = false;
    break;
  default:
    cerr << "Invalid option! Please choose again!\n";
    menu(tree, resume);
    break;
  }
}

/********/
/* Main */
/********/

int main(int argc, char *argv[])
{
  /**
   * Below is the code to interact with the user
   */

  BinaryTree<char> tree;       // Init the binary tree
  string tree_expression = ""; // This is the user-entered tree expression
  int expression_type = 0;     // Specifying whether the tree is preorder, inorder, or postorder

  cout << "Welcome to the program! Please enter a tree expression to continue!\n";
  cin >> tree_expression;
  cout << "Does the expresion represent tree in preorder, inorder, or postoder traversal? \n(Enter 0 for preorder, 1 for postorder, and 2 for inorder)\n";
  cin >> expression_type;

  switch (expression_type)
  {
  case 0:
    tree.init_complete_pre((&tree_expression[0]), tree_expression.size());
    break;
  case 1:
    tree.init_complete_post((&tree_expression[0]), tree_expression.size());
    break;
  case 2:
    tree.init_complete_in((&tree_expression[0]), tree_expression.size());
    break;
  default:
    cout << "Since the option is invalid, I will assume it is a preorder traversal\n";
    tree.init_complete_pre((&tree_expression[0]), tree_expression.size());
    break;
  }

  handle_print(tree); // Print out the tree for the first time

  bool resume = true; // The program is running as long as resume == true
  while (resume)
  {
    menu(tree, resume);
  }

  return 0;
}
