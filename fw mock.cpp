#include <iostream>
using namespace std;

#define INF 999  // Indicates no direct edge

class Graph {
private:
    int vertexcount;
    int matrix[20][20];

public:
    Graph() {
        vertexcount = 0;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                matrix[i][j] = INF;
    }

    void input();
    void displaymatrix();
    void warshalls();
};

// Input function: Add vertices and edges with weights
void Graph::input() {
    int edges, a, b, weight;
    cout << "Enter number of vertices: ";
    cin >> vertexcount;

    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter two vertices (0 to " << vertexcount - 1 << "): ";
        cin >> a >> b;
        cout << "Enter weight of the edge: ";
        cin >> weight;

        if (a >= 0 && a < vertexcount && b >= 0 && b < vertexcount) {
            matrix[a][b] = weight;
        } else {
            cout << "Invalid edge. Try again.\n";
            i--;  // Retry the same edge
        }
    }
}

// Display the adjacency matrix
void Graph::displaymatrix() {
    if (vertexcount == 0) {
        cout << "\n!! Add the vertices first !!\n";
        return;
    }

    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < vertexcount; i++)
        cout << i << "\t";
    cout << "\n";

    for (int i = 0; i < vertexcount; i++) {
        cout << i << "  ";
        for (int j = 0; j < vertexcount; j++) {
            if (matrix[i][j] == INF)
                cout << "0\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Run Floyd-Warshall algorithm
void Graph::warshalls() {
    if (vertexcount == 0) {
        cout << "\n!! Add the vertices first !!\n";
        return;
    }

    int dist[20][20];

    // Initialize distance matrix
    for (int i = 0; i < vertexcount; i++) {
        for (int j = 0; j < vertexcount; j++) {
            dist[i][j] = matrix[i][j];
            if (i == j) dist[i][j] = 0;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < vertexcount; k++) {
        for (int i = 0; i < vertexcount; i++) {
            for (int j = 0; j < vertexcount; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Display shortest path matrix
    cout << "\nShortest Path Matrix:\n   ";
    for (int i = 0; i < vertexcount; i++)
        cout << i << "\t";
    cout << "\n";

    for (int i = 0; i < vertexcount; i++) {
        cout << i << "  ";
        for (int j = 0; j < vertexcount; j++) {
            if (dist[i][j] == INF)
                cout << "N\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }

    // Optional: Show shortest path values
    cout << "\nShortest distances between all pairs:\n";
    for (int i = 0; i < vertexcount; i++) {
        for (int j = 0; j < vertexcount; j++) {
            cout << "From " << i << " to " << j << " : ";
            if (dist[i][j] == INF)
                cout << "Not reachable\n";
            else
                cout << dist[i][j] << "\n";
        }
    }
}

int main() {
    Graph obj;
    int ch;

    do {
        cout << "\n*************** MENU ***************\n";
        cout << "1. Add Vertices and Edges\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Run Floyd-Warshall Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: obj.input(); break;
            case 2: obj.displaymatrix(); break;
            case 3: obj.warshalls(); break;
            case 4: cout << "!! THANK YOU !!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (ch != 4);

    return 0;
}
