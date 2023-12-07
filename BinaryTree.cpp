#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;
};

Node* createNode(int data, Node* parent) {
  Node* newnode = new Node();
  newnode->data = data;
  newnode->left = newnode->right = nullptr;
  newnode->parent = parent;
  return newnode;
}

// searching in a tree
Node* search_tree(Node* a, int x) {
  if (a == NULL) {
    return NULL;
  }
  else if (a->data == x) {
    return a;
  }
  else if (x < a->data) {
    return search_tree(a->left, x); // recursively search the left side of the tree
  } else {
    return search_tree(a->right, x); // recursively search the right side of the tree
  }
}

// traversing in a tree
void traverse_tree(Node* root) {
  if (root != NULL) {
    // the order of these 3 steps matters for different algorithms
    traverse_tree(root->left);
    //process_item(root->data);
    traverse_tree(root->right);
  }
}

// insertion in a tree
void insert_node(Node** root, int x, Node* parent) {
  Node* p; // temporary pointer

  if (*root == NULL) {
    p = createNode(x, parent);
    *root = p;
    return;
  } else if (x < (*root)->data) {
    insert_node(&((*root)->left), x, *root); // recursive search left
  } else {
    insert_node(&((*root)->right), x, *root); // recursive search right
  }
}

// deletion from a tree, implement the 3 cases
void delete_node(Node* root, int x) {
  Node* p = search_tree(root, x);
  if (p == NULL) {
    return;
  }

  // case 1: p has no children
  if (p->left == NULL && p->right == NULL) {
    if (p->parent->left == p) {
      p->parent->left = NULL;
    } else {
      p->parent->right = NULL;
    }
    delete p;
  }

  // case 2: p has 2 children
  else if (p->left != NULL && p->right != NULL) {
    Node* x = p->right;
    while (x->left != NULL) {
      x = x->left;
    }
    x->parent->left = NULL;
    p->data = x->data;
    delete x;
  }

  // case 3: p has 1 child
  else {
    if (p->left != NULL) {
      p->data = p->left->data;
      p->left = NULL;
      delete p->left;
    }
    else {
      p->data = p->right->data;
      p->right = NULL;
      delete p->right;
    }
  }
}

int main() {
  
  Node* root = createNode(4, NULL);
  // 2nd level
  root->left = createNode(2, root);
  root->right = createNode(7, root);
  // 3rd level
  root->left->left = createNode(1, root->left);
  root->left->right = createNode(3, root->left);
  root->right->left = createNode(5, root->right);

  return 0;
}