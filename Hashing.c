#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // Size of the hash table

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert a key into the hash table using Linear Probing
void insert(int hashTable[], int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
    }

    hashTable[(index + i) % SIZE] = key;
}

// Search for a key in the hash table
int search(int hashTable[], int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % SIZE] != key) {
        if (hashTable[(index + i) % SIZE] == -1) {
            return -1; // Key not found
        }
        i++;
    }

    return (index + i) % SIZE; // Index where key was found
}

// Display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, hashTable[i]);
    }
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // Initialize hash table with -1
    }

    // Insert keys into the hash table
    insert(hashTable, 12);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 45);

    // Search for a key
    int keyToSearch = 35;
    int index = search(hashTable, keyToSearch);
    if (index != -1) {
        printf("Key %d found at index %d\n", keyToSearch, index);
    } else {
        printf("Key %d not found\n", keyToSearch);
    }

    // Display the hash table
    display(hashTable);

    return 0;
}
