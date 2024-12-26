#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<queue>
#include<algorithm>
using namespace std;

const int NUM_GATES = 3;
const int MAX_POSITION = 25;

int N; // Number of fishing spots
int gate[NUM_GATES + 1]; // Gate positions (1-based index)
int fishermen[NUM_GATES + 1]; // Fishermen at each gate (1-based index)

int spot_status[MAX_POSITION] = {}; // 0 means unoccupied, 1 means occupied
int gateOrder[NUM_GATES + 1]; // To store the current gate order
bool visited[NUM_GATES + 1] = {}; // To track which gates have been used in the order

int minTotalDistance = INT_MAX; // To store the minimum distance

// Function to assign fishermen to spots and calculate the total distance for the current gate order
void assignSpots(int spot_status[], int gateIndex) {
    int currentGate = gateOrder[gateIndex];
    int gatePosition = gate[currentGate];
    int numFishermen = fishermen[currentGate];

    int distance = 0;
    while (numFishermen > 0) {
        // Try the closest spot at the gate's position first
        if (distance == 0 && spot_status[gatePosition] == 0) {
            spot_status[gatePosition] = 1;
            numFishermen--;
            continue;
        }

        // Try both sides of the gate (left and right)
        int leftSpot = gatePosition - distance;
        int rightSpot = gatePosition + distance;

        // If only one fisherman is left, try both spots and choose the one that minimizes the distance
        if (leftSpot >= 1 && rightSpot <= N && spot_status[leftSpot] == 0 && spot_status[rightSpot] == 0 && numFishermen == 1) {
            // Try left spot
            spot_status[leftSpot] = 1;
            numFishermen--;
            continue;

            // Try right spot
            spot_status[rightSpot] = 1;
            numFishermen--;
            continue;
        }

        // Place fishermen in available spots
        if (leftSpot >= 1 && spot_status[leftSpot] == 0 && numFishermen > 0) {
            spot_status[leftSpot] = 1;
            numFishermen--;
        }

        if (rightSpot <= N && spot_status[rightSpot] == 0 && numFishermen > 0) {
            spot_status[rightSpot] = 1;
            numFishermen--;
        }

        distance++; // Increase distance for next attempt
    }

    // If all gates have been processed, calculate total distance
    if (gateIndex == NUM_GATES) {
        int totalDistance = 0;
        for (int i = 1; i <= N; i++) {
            if (spot_status[i] == 1) {
                totalDistance += abs(gate[spot_status[i]] - i);
            }
        }
        minTotalDistance = min(minTotalDistance, totalDistance);
    } else {
        assignSpots(spot_status, gateIndex + 1);
    }
}

// Function to generate all permutations of gate opening orders
void generateGateOrders(int index) {
    if (index > NUM_GATES) {
        fill(spot_status + 1, spot_status + N + 1, 0); // Reset the spot status
        assignSpots(spot_status, 1); // Start assigning spots from the first gate
        return;
    }

    for (int i = 1; i <= NUM_GATES; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            gateOrder[index] = i;
            generateGateOrders(index + 1); // Move to the next gate
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N; // Number of fishing spots
    for (int i = 1; i <= 3; i++) cin >> gate[i]; // Gate positions
    for (int i = 1; i <= 3; i++) cin >> fishermen[i]; // Fishermen at each gate

    generateGateOrders(1); // Start generating gate orders
    cout << minTotalDistance << endl; // Output the minimum total walking distance
}
