#include <iostream>
#include <iomanip>
#include <string>
int table[11];
int keyMod11(int key);
int keyMod11(int key) {
    return key % 11;
}
int keyMod29(int key) {
    return key % 29;
}
int doubleHashing(int key) {
    int index = keyMod11(key);
    int index2 = keyMod29(key);
    int counter = 1;
    while (table[index] != -1) {
        index = (index + (counter)*(index2)) % 11;
        counter++;
    }

    return index;
}
void initializeTable(int table[]) {
    for (int i = 0; i < 11; i++) {
        table[i] = -1;
    }
}
void insert(int table[], int key) {
    int index = doubleHashing(key);
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