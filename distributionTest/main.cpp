#include <iostream>
#include <vector>

using namespace std;

void distribute_recursive(int remaining_apples, int index, vector<int>& distribution, int n) {
    // Base case: if all apples are distributed, print the distribution
    if (remaining_apples == 0) {
        cout << "Distribution: ";
        for (int i = 0; i < n; ++i) {
            cout << distribution[i] << " ";
        }
        cout << endl;
        return;
    }

    // Iterate through possible number of apples for the current person
    for (int apples_for_person = 0; apples_for_person <= remaining_apples; ++apples_for_person) {
        // Assign apples to the current person
        distribution[index] = apples_for_person;
        // Recursive call for the next person
        distribute_recursive(remaining_apples - apples_for_person, index + 1, distribution, n);
    }
}

void distribute_apples(int n, int k) {
    // Initialize a vector to store the distribution of apples
    vector<int> distribution(n, 0);
    // Start distributing from the first person
    distribute_recursive(k, 0, distribution, n);
}

int main() {
    int n, k;
    cout << "Enter the number of people: ";
    cin >> n;
    cout << "Enter the number of apples: ";
    cin >> k;
    cout << "All possible distributions:" << endl;
    distribute_apples(n, k);
    return 0;
}