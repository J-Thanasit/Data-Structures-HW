#include "BSTNode.cpp"

class BST {

public:
  BSTNode* root;

  BST() {
    root = nullptr;
  }

  void insert(int value) {
    BSTNode* new_node = new BSTNode;
	  new_node->value = value;
	  new_node->left = nullptr;
	  new_node->right = nullptr;
    BSTNode* p, *previous;
    if(root==nullptr){
      root = new_node;
    }else{
      p = root;
      while(p!=nullptr){
        previous = p;
        if(p->value>new_node->value){
          p = p->left;
        }else{
          p = p->right;
        }
      }if(previous->value>new_node->value){
        previous->left = new_node;
      }else{
        previous->right = new_node;
      }
    }
  }

  void remove(int value) {
    BSTNode* node = root;
    BSTNode* temp;
    while(true){
      if(node==nullptr){
        break;
      }else if(value<node->value){
        node=node->left;
      }else if(value>node->value){
        node=node->right;
      }else{
        if(node->left==nullptr&&node->right==nullptr){
          node = nullptr;
        }else if(root->left==nullptr){
          node = node->right;
          temp = node;
          delete(temp);
          break;
        }else if(node->right==nullptr){
          node = node->left;
          temp = node;
          delete(temp);
          break;
        }else{
          BSTNode* temp = minValueNode(node->right);
          node->value = temp->value;
          node = node->right;
          temp = temp->left;
          delete(temp);
        }
      }
    }
  }

  int get_depth(int value) {
    BSTNode* node = root;
    int depth = 0;
    while(node!=nullptr){
      if(node->value>value){
        node = node->left;
        depth++;
      }else if(node->value<value){
        node = node->right;
        depth++;
      }else{
        return(depth);
      }
    }return -1;
  }

  BSTNode* minValueNode(BSTNode* min_node) {
    while(min_node&&min_node->left != nullptr){
      min_node = min_node->left;
    }return min_node;
  }
};