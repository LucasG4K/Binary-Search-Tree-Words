#include "tree.hpp"

int Tree::counter = 0;

Node* Tree::initialize() {
    return NULL;
}

void Tree::insertValue(Node **node, Item requestedValue) {
    if (*node == NULL) {
        *node          = (Node*)malloc(sizeof(Node));
        (*node)->item  = requestedValue;
        (*node)->left  = NULL;
        (*node)->right = NULL;
    } else {
        int compare = memcmp((*node)->item.value, requestedValue.value, 20);
        if (compare > 0) {
            insertValue(&(*node)->left, requestedValue);
        } else if (compare < 0) {
            insertValue(&(*node)->right, requestedValue);
        }
    }
}

void Tree::removeValue(Node **node, Item requestedValue) {
    Node *temp;
    
    if (*node == NULL) {
        cout << "[ERROR]: REQUESTED VALUE NOT FOUND" << endl;
        return;
    }

    int compare = memcmp((*node)->item.value, requestedValue.value, 20);
    if (compare > 0) {
        removeValue(&(*node)->left, requestedValue);
        return;
    } else if (compare < 0) {
        removeValue(&(*node)->right, requestedValue);
        return;
    }

    if ((*node)->left != NULL) {
        nextChild(&(*node)->left, *node);
        return;
    }

    temp  = *node;
    *node = (*node)->right;
    free(temp);
}

void Tree::nextChild(Node **node, Node *temp) {
    if ((*node)->right != NULL) {
        nextChild(&(*node)->right, temp);
        return;
    }
    temp->item = (*node)->item;
    temp       = (*node);
    *node      = (*node)->left;
    free(temp);
}

void Tree::search(Node **node, Node **temp, Item requestedValue) {
    counter++;
    if (*node == NULL) {
        cout << "[ERROR]: NODE NOT FOUND" << endl;
        return;
    }
    int compare = memcmp((*node)->item.value, requestedValue.value, 20);
    if (compare < 0) {
        search(&(*node)->right, temp, requestedValue);
        return;
    }
    else if (compare > 0) { 
        search(&(*node)->left, temp, requestedValue);
        return;
    }
    
    cout << "NODE FOUND" << endl;
    *temp = *node;
}

void Tree::preOrderPrint(Node *node) {
    if (node != NULL) {
        preOrderPrint(node->left);
        preOrderPrint(node->right);
        cout << node->item.value << " ";
    }
}

void Tree::inOrderPrint(Node *node) {
    if (node != NULL) {
        inOrderPrint(node->left);
        cout << node->item.value << " ";
        inOrderPrint(node->right);
    }
}

void Tree::postOrderPrint(Node *node) {
    if (node != NULL) {
        cout << node->item.value << " ";
        postOrderPrint(node->left);
        postOrderPrint(node->right);
    }
}

void Tree::printAllTogether(Node *node) {
    cout << " * PreOrder:  ";
    preOrderPrint(node);
    cout << endl << " * InOrder:   ";
    inOrderPrint(node);
    cout << endl << " * PostOrder: ";
    postOrderPrint(node);
}