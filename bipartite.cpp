#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isBipartite = true;
//cv=current vertex, cc=current color
void checkBipartite(vector<vector<int>>& graph, int cv, int cc, vector<int>& color) {
    if (color[cv] != -1) {
        if(color[cv] != cc){
            isBipartite = false;
        }
        return;
    }

    color[cv] = cc;

    for (int i = 0; i < graph.size(); i++) {
        if (graph[cv][i] == 1) {
            checkBipartite(graph, i, abs(1 - cc), color);
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    vector<int> color(v, -1);

    checkBipartite(graph, 0, 1, color);

    if (isBipartite) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is not Bipartite" << endl;
    }

    return 0;
}
