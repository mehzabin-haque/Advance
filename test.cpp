#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to calculate the maximum score using memoization
int calculate_score(const vector<int>& balloons, int left, int right, vector<vector<int>>& dp) {
    // Base case: no balloons left to burst
    if(left > right) return 0;
    
    // Check if the result is already computed
    if(dp[left][right] != -1)
        return dp[left][right];
    
    int max_score = INT_MIN;
    
    // Iterate through all possible balloons to burst last in the current interval
    for(int i = left; i <= right; i++) {
        // Calculate the current score based on the adjacent balloons
        int current_score = balloons[left - 1] * balloons[i] * balloons[right + 1];
        
        // Recursively calculate the score for left and right sub-intervals
        int total_score = current_score 
                          + calculate_score(balloons, left, i - 1, dp) 
                          + calculate_score(balloons, i + 1, right, dp);
                          
        // Update the maximum score
        max_score = max(max_score, total_score);
    }
    
    // Memoize and return the result
    return dp[left][right] = max_score;
}

int main()
{
    int n, t;
    cin >> n;
    
    // Initialize balloons with two dummy balloons (1 at start and end)
    vector<int> balloons;
    balloons.push_back(1); // Dummy balloon at index 0
    
    // Read the balloon values
    for(int i = 0; i < n; i++){
        cin >> t;
        balloons.push_back(t);
    }
    
    balloons.push_back(1); // Dummy balloon at index n+1
    
    // Initialize DP table with -1
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    
    // Calculate the maximum score
    int max_total_score = calculate_score(balloons, 1, n, dp);
    
    // Output the result
    cout << max_total_score;
    
    return 0;
}
