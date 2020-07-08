#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value = 0;
    Node *left_child = nullptr;
    Node *right_child = nullptr;
};

class Binary_tree {
private:
    Node *root = nullptr;
    string pre_order(Node*);
    string in_order(Node*);
    string post_order(Node*);
public:
    void insert(int value);
    string bt_pre_order();
    string bt_in_order();
    string bt_post_order();

};

void Binary_tree::insert(int value) {
    Node *ptr = new Node;
    ptr->value = (int)(value);
    if (this->root == nullptr) {
        this->root = ptr;
    } else {
        Node *child;
        Node *parent;
        child = root;
        while (child != nullptr) {
            if (child->value < value) {
                parent = child;
                child = child->right_child;
            } else {
                parent = child;
                child = child->left_child;
            }
        }
        if (parent->value < value) {
            parent->right_child = ptr;
        } else {
            parent->left_child = ptr;
        }
    }
}


string Binary_tree::in_order(Node *node) {
    if (node == nullptr) return ".";
    return in_order(node->left_child) + "  " + to_string(node->value) + "  " + in_order(node->right_child);
}

string Binary_tree::pre_order(Node *node) {
    if (node == nullptr) return ".";
    return to_string(node->value) + "  " + pre_order(node->left_child) + "  " + pre_order(node->right_child);
}

string Binary_tree::post_order(Node *node) {
    if (node == nullptr) return ".";
    return post_order(node->left_child) + "  " + post_order(node->right_child) + " " + to_string(node->value);
}

string Binary_tree::bt_pre_order() {
    return pre_order(this->root);
}

string Binary_tree::bt_in_order() {
//     return to_string(this->root->left_child->value) + " ~ " + to_string(this->root->value) + " ~ " + to_string(this->root->right_child->value);
    return in_order(this->root);
}

string Binary_tree::bt_post_order() {
    return post_order(this->root);
}

int main() {
    Binary_tree new_bt;
    new_bt.insert(15);
    new_bt.insert(10);
    new_bt.insert(20);
    new_bt.insert(1);
    new_bt.insert(5);
    new_bt.insert(30);
    new_bt.insert(14);
    new_bt.insert(7);
    new_bt.insert(16);
    cout << "Pre order: " << new_bt.bt_pre_order() << endl;
    cout << "In order: " << new_bt.bt_in_order() << endl;
    cout << "Post order :" << new_bt.bt_post_order() << endl;
}
