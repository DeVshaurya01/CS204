#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CITY_LEN 50
#define HASH_SIZE 1009  // Prime number for better distribution

// Hash set structure for storing city names
struct HashSet {
    char city[HASH_SIZE][MAX_CITY_LEN];
    bool used[HASH_SIZE];
};

// Simple string hash function
int hashFunc(const char *s) {
    unsigned long hash = 0;
    for (int i = 0; s[i]; i++) {
        hash = (hash * 31 + s[i]) % HASH_SIZE;
    }
    return hash;
}

// Insert city into hash set
void insertCity(HashSet &set, const char *city) {
    int index = hashFunc(city);
    while (set.used[index]) {
        if (strcmp(set.city[index], city) == 0)
            return; // Already present
        index = (index + 1) % HASH_SIZE; // linear probing
    }
    strcpy(set.city[index], city);
    set.used[index] = true;
}

// Check if city exists in hash set
bool existsCity(HashSet &set, const char *city) {
    int index = hashFunc(city);
    int start = index;
    while (set.used[index]) {
        if (strcmp(set.city[index], city) == 0)
            return true;
        index = (index + 1) % HASH_SIZE;
        if (index == start) break;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    char cityA[MAX_CITY_LEN], cityB[MAX_CITY_LEN];
    char destCandidates[100][MAX_CITY_LEN]; // store all cityB
    int destCount = 0;

    HashSet outgoing = {0}; // cities with outgoing paths

    // Read all paths
    for (int i = 0; i < n; i++) {
        cin >> cityA >> cityB;
        insertCity(outgoing, cityA);
        strcpy(destCandidates[destCount++], cityB);
    }

    // Find the destination city (not present in outgoing set)
    for (int i = 0; i < destCount; i++) {
        if (!existsCity(outgoing, destCandidates[i])) {
            cout << destCandidates[i] << endl;
            break;
        }
    }

    return 0;
}
