#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;

    // Input variables
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));

    // Inputting the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    unordered_map<string, int> frequencyMap;

    // Storing frequency of each row configuration in the map
    for (int i = 0; i < n; i++) {
        string rowStr = "";
        for (int j = 0; j < m; j++) {
            rowStr += to_string(mat[i][j]);
        }
        frequencyMap[rowStr]++;
    }

    int maxRows = 0;

    // Iterate through the map
    for (const auto &entry : frequencyMap) {
        string rowStr = entry.first;
        int freq = entry.second;

        // Count number of zeros in the row string
        int num_zeros = count(rowStr.begin(), rowStr.end(), '0');

        // Check conditions: num_zeros <= k and (k - num_zeros) % 2 == 0
        if (num_zeros <= k && (k - num_zeros) % 2 == 0) {
            maxRows = max(maxRows, freq);
        }
    }

    // Output the result
    cout << maxRows << endl;

    return 0;
}
