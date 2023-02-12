#include <iostream>

template <class T>
struct tree{
    T value;
    tree *left;
    tree *right;
};

auto createNewTreeRoot(auto value){
    tree<auto> root = new tree<auto>;
    root->value = value;
    root->left = nullptr;
    root->right = nullptr;
}

int main(int argc, char *argv[]){
    tree<int> *head = new tree<int>;
    
}

