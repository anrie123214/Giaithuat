#include <iostream>
#include <iomanip>
#include <string>
int table[11];
int keyMod11(int key);
int keyMod11(int key) {
    return key % 11;
}
int linearProbe(int key) {
    int index = keyMod11(key);

    while (table[index] != -1) {
        index = (index + 1) % 11;
    }

    return index;
}
void initializeTable(int table[]) {
    for (int i = 0; i < 11; i++) {
        table[i] = -1;
    }
}
void insert(int table[], int key) {
    int index = linearProbe(key);
    table[index] = key;
}
int main() {
    initializeTable(table);
    insert(table, 23);
    insert(table, 65);
    insert(table, 78);
    insert(table, 37);
    insert(table, 29);
    insert(table, 15);
    for (int i = 0; i < 11; i++) {
        std::cout << table[i] << " ";
    }
}