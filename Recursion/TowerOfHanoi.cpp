#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi puzzle
void TowerOfHanoi(int n, char frompeg, char topeg, char auxpeg) {
    // If only 1 disk, make the move and return
    if(n==1) {
        cout << "Move disk 1 from peg " << frompeg << " to peg " << topeg << endl;
        return;
    }

    // Move top n-1 disks from A to B, using C as auxiliary
    TowerOfHanoi(n-1, frompeg, auxpeg, topeg);

    // Move remaining disk from A to C
    cout << "Move disk " << n << " from peg " << frompeg << " to peg " << topeg << endl;

    // Move n-1 disks from B to C using A as auxiliary
    TowerOfHanoi(n-1, auxpeg, topeg, frompeg);
}

int main() {
    int n; // Number of disks
    cout << "Enter number of disks: ";
    cin >> n;
    TowerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}