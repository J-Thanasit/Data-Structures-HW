#include<iostream>
#include "HW08.cpp"
using namespace std;

int main() {
    BST tree;

    tree.insert(2);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);
    tree.insert(3);
    tree.remove(1);
    tree.remove(2);
    tree.remove(3);
    tree.remove(4);
    tree.remove(5);
    cout << tree.get_depth(1) << endl;
    cout << tree.get_depth(2) << endl;
    cout << tree.get_depth(3) << endl;
    cout << tree.get_depth(4) << endl;
    cout << tree.get_depth(5) << endl;

    return 0;
}
