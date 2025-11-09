#include <bits/stdc++.h>
using namespace std;

void moveDisk(char from, char to, int disk) {
    cout << disk << " " << from << " " << to << "\n";
}

// Function to perform iterative Tower of Hanoi
void hanoiIterative(int n) {
    char A = 'A', B = 'B', C = 'C';
    
    // If number of disks is even, swap destination and auxiliary
    if (n % 2 == 0) swap(B, C);

    int total_moves = (1 << n) - 1; // 2^n - 1

    // Initialize rods as stacks
    stack<int> src, aux, dest;
    for (int i = n; i >= 1; i--) src.push(i);

    for (int move = 1; move <= total_moves; move++) {
        // Determine which rods to move between based on move number
        stack<int> *fromRod, *toRod;
        char fromChar, toChar;

        if (move % 3 == 1) { fromRod = &src; toRod = &dest; fromChar = A; toChar = C; }
        else if (move % 3 == 2) { fromRod = &src; toRod = &aux; fromChar = A; toChar = B; }
        else { fromRod = &aux; toRod = &dest; fromChar = B; toChar = C; }

        // Perform legal move between fromRod and toRod
        int fromTop = fromRod->empty() ? INT_MAX : fromRod->top();
        int toTop = toRod->empty() ? INT_MAX : toRod->top();

        if (fromTop < toTop) {
            fromRod->pop();
            toRod->push(fromTop);
            moveDisk(fromChar, toChar, fromTop);
        } else {
            toRod->pop();
            fromRod->push(toTop);
            moveDisk(toChar, fromChar, toTop);
        }
    }
}

int main() {
    int n;
    cin >> n;
    hanoiIterative(n);
    return 0;
}
