#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX_WORDS 5000
#define WORD_SIZE 50
#define HASH_SIZE 10007  // A prime number for better distribution

struct Entry {
    char word[WORD_SIZE];
    int count;
};

Entry hashTable[HASH_SIZE];
bool bannedTable[HASH_SIZE];

// Simple hash function for strings
int hashFunc(const char *word) {
    unsigned long hash = 0;
    for (int i = 0; word[i]; i++)
        hash = (hash * 31 + word[i]) % HASH_SIZE;
    return hash % HASH_SIZE;
}

// Insert or update word count
void insertWord(const char *word) {
    int index = hashFunc(word);
    while (hashTable[index].word[0] != '\0' && strcmp(hashTable[index].word, word) != 0) {
        index = (index + 1) % HASH_SIZE; // linear probing
    }
    if (hashTable[index].word[0] == '\0') {
        strcpy(hashTable[index].word, word);
        hashTable[index].count = 1;
    } else {
        hashTable[index].count++;
    }
}

// Mark a word as banned
void markBanned(const char *word) {
    int index = hashFunc(word);
    while (hashTable[index].word[0] != '\0' && strcmp(hashTable[index].word, word) != 0) {
        index = (index + 1) % HASH_SIZE;
    }
    bannedTable[index] = true;
}

// Check if a word is banned
bool isBanned(const char *word) {
    int index = hashFunc(word);
    while (hashTable[index].word[0] != '\0') {
        if (strcmp(hashTable[index].word, word) == 0)
            return bannedTable[index];
        index = (index + 1) % HASH_SIZE;
    }
    return false;
}

int main() {
    char paragraph[10005];
    char bannedInput[1005];

    // Read paragraph until '#'
    cin.getline(paragraph, 10005, '#');
    cin.ignore();
    // Read banned words until '#'
    cin.getline(bannedInput, 1005, '#');

    // Convert paragraph to lowercase and replace punctuation with space
    for (int i = 0; paragraph[i]; i++) {
        if (isalpha(paragraph[i]))
            paragraph[i] = tolower(paragraph[i]);
        else
            paragraph[i] = ' ';
    }

    // Tokenize and insert words
    char *word = strtok(paragraph, " ");
    while (word != NULL) {
        if (strlen(word) > 0)
            insertWord(word);
        word = strtok(NULL, " ");
    }

    // Mark banned words
    char *bword = strtok(bannedInput, " ");
    while (bword != NULL) {
        if (strlen(bword) > 0) {
            // Convert banned word to lowercase (just in case)
            for (int i = 0; bword[i]; i++)
                bword[i] = tolower(bword[i]);
            markBanned(bword);
        }
        bword = strtok(NULL, " ");
    }

    // Find the most frequent non-banned word
    int maxCount = 0;
    char result[WORD_SIZE] = "";

    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i].word[0] != '\0' && !isBanned(hashTable[i].word)) {
            if (hashTable[i].count > maxCount) {
                maxCount = hashTable[i].count;
                strcpy(result, hashTable[i].word);
            }
        }
    }

    cout << result << endl;
    return 0;
}
