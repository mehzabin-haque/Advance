#include <iostream>
#include <climits>
#include <cstring> // For memset
using namespace std;

// Constants
const int MAX_N = 11;    // Maximum number of fishing spots (1-based indexing)
const int MAX_P = 16;    // Maximum number of people per gate (assuming up to 15)

// Memoization table
// dp[index][p0][p1][p2] stores the minimal distance sum for the state
long long dp_table[MAX_N][MAX_P][MAX_P][MAX_P];

// Gates and people
int n;                  // Number of fishing spots
int gate[3];            // Positions of the 3 gates (0, 1, 2)
int people_initial[3];  // Initial number of people at each gate


// DP Function with Memoization
long long solve(int index, int p0, int p1, int p2){
    // Base Cases
    if(p0 == 0 && p1 == 0 && p2 == 0){
        // All fishermen have been placed
        return 0;
    }
    if(index > n){
        // Reached beyond the last spot but still have fishermen to place
        return LLONG_MAX / 2; // Use a large number to indicate invalid path
    }

    // Check if this state has already been computed
    if(dp_table[index][p0][p1][p2] != -1){
        return dp_table[index][p0][p1][p2];
    }

    // Initialize the minimum distance for this state to a large value
    long long min_dist = LLONG_MAX / 2;

    // Option 1: Place a fisherman from any gate (if available) at the current spot
    for(int i = 0; i < 3; i++){
        if((i == 0 && p0 > 0) || (i == 1 && p1 > 0) || (i == 2 && p2 > 0)){
            // Assign one fisherman from gate 'i' to this spot
            if(i == 0 && p0 > 0){
                // Calculate distance: |gate position - current spot| + 1
                long long distance = abs(gate[i] - index) + 1;
                // Recurse for the next spot with one less fisherman at gate 'i'
                long long temp = solve(index + 1, p0 - 1, p1, p2);
                if(temp != LLONG_MAX / 2){
                    min_dist = min(min_dist, distance + temp);
                }
            }
            if(i == 1 && p1 > 0){
                long long distance = abs(gate[i] - index) + 1;
                long long temp = solve(index + 1, p0, p1 - 1, p2);
                if(temp != LLONG_MAX / 2){
                    min_dist = min(min_dist, distance + temp);
                }
            }
            if(i == 2 && p2 > 0){
                long long distance = abs(gate[i] - index) + 1;
                long long temp = solve(index + 1, p0, p1, p2 - 1);
                if(temp != LLONG_MAX / 2){
                    min_dist = min(min_dist, distance + temp);
                }
            }
        }
    }

    // Option 2: Do not place any fisherman at the current spot
    long long skip = solve(index + 1, p0, p1, p2);
    min_dist = min(min_dist, skip);

    // Memoize the result
    dp_table[index][p0][p1][p2] = min_dist;

    return min_dist;
}

int main(){
    // Initialize the memoization table with -1 (uncomputed states)
    memset(dp_table, -1, sizeof(dp_table));

    // Input reading
    cin >> n; // Number of fishing spots

    for(int i = 0; i < 3; i++){
        cin >> gate[i]; // Positions of the 3 gates
    }

    int sum = 0; // Total number of fishermen
    for(int i = 0; i < 3; i++){
        cin >> people_initial[i]; // Number of fishermen at each gate
        sum += people_initial[i];
    }

    // Check if the total number of fishermen exceeds the number of spots
    if(sum > n){
        cout << -1 << endl; // Or handle as per problem constraints
        return 0;
    }

    // Start solving from the first fishing spot with all fishermen unplaced
    long long answer = solve(1, people_initial[0], people_initial[1], people_initial[2]);

    // If answer is still a large number, it means it's impossible to place all fishermen
    if(answer >= LLONG_MAX / 2){
        cout << -1 << endl; // Or handle as per problem constraints
    }
    else{
        cout << answer << endl;
    }

    return 0;
}
