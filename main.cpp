#include "tree.hpp"

int main() {
    Tree tree;
    Node *node = tree.initialize();
    Node *temp = tree.initialize();
    Item item;

    char vector[][20] = {"Migalha", "Maquina", "Barco", "Bazuca", "Forno", "Areia",
    "Plantas", "Sueter", "Remexer", "Convexo", "Diplomata", "Tempo", "Desejo", "Pacote",
    "Judo", "Bandeja", "Pintor", "Isca", "Magro", "Procriar", "Tributacao", "Germe",
    "Mochila", "Irrigar", "Trancar", "Protesto", "Arco", "Antes", "Oito", "Aposentado"};
    int vectorSize = sizeof(vector) / sizeof(vector[0]);

    char toBeDeleted[][20] = {"Areia", "Maquina", "Arco", "Diplomata", "Nada"};
    int toBeDeletedSize = sizeof(toBeDeleted) / sizeof(toBeDeleted[0]);

    char toBeSearched[][20] = {"Diplomata", "Sozinho", "Desejo", "Pacote", "Judo", "Bandeira", "Pintor", "Isca", "Oito", "Aposentado"};
    int toBeSearchedSize = sizeof(toBeSearched) / sizeof(toBeSearched[0]);

    cout << "Original Array: ";
    for (int i = 0; i < vectorSize; i++) {
        item.value = vector[i];
        tree.insertValue(&node, item);
        cout << vector[i] << " ";
    }
    
    cout <<endl << endl << "==========================" << endl;
    cout << "Standard Tree:" << endl;
    tree.printAllTogether(node);

    cout << endl << endl << "==========================" << endl << "Searching for:" << endl;
    for (int i = 0; i < toBeSearchedSize; i++) {
        cout << toBeSearched[i] << " - ";
        item.value = toBeSearched[i];
        tree.search(&node, &temp, item);
    }

    int counter = 0;
    for (int i = 0; i < toBeSearchedSize; i++) {
        for (int j = 0; j < vectorSize; j++) {
            int compare = strcmp(toBeSearched[i], vector[j]);
            counter++;
            if (compare == 0)
                break;
        }
    }

    cout << endl << "==========================" << endl;
    for (int i = 0; i < toBeDeletedSize; i++) {
        item.value = toBeDeleted[i];
        cout << "Removing '" << item.value << "'... ";
        tree.removeValue(&node, item);
        tree.postOrderPrint(node);
        cout << endl;
    }

    cout << endl << "==========================" << endl << "Showing results:" << endl;
    cout << "Number of comparisons when using tree:  " << tree.counter << endl;
    cout << "Number of comparisons when using array: " << counter;

    return 0;
}