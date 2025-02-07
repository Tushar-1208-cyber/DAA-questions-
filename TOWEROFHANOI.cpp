#include<iostream>
using namespace std;
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int &count) {
    count++;
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, count);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, count);
}
int main() 
{    int disks, count;
    cout << "Enter the number of disks in Tower of Hanoi: ";
    cin >> disks;
    towerOfHanoi(disks,3 'A', 'C', 'B', count);
    cout << "Number of moves: " << count << endl;

    return 0;
}
