#include <iostream>
using namespace std;

#define N 999  // Indicates no direct edge between vertices

class Graph {
private:
    int vertexcount;
    int matrix[20][20];

public:
    Graph() {
        vertexcount = 0;
    }

    void input();             // Input vertices and edges
    void displaymatrix();     // Display adjacency matrix
    void warshalls();         // Run Floyd-Warshall algorithm
};

// Combined input of vertices and edges
void Graph::input() {
    int edges;
    cout << "\nEnter the number of vertices: ";
    cin >> vertexcount;

    // Initialize matrix
    for (int i = 0; i < vertexcount; i++) {
        for (int j = 0; j < vertexcount; j++) {
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = N;
        }
    }

    cout << "\nEnter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int a, b, cost;
        cout << "\nEnter edge " << i + 1 << " (source destination weight): ";
        cin >> a >> b >> cost;

        if (a >= 0 && a < vertexcount && b >= 0 && b < vertexcount) {
            matrix[a][b] = cost;
        } else {
            cout << "!! Invalid vertices. Try again !!\n";
            i--; // Retry same edge
        }
    }

    cout << "\n!! Graph input complete !!\n";
}

void Graph::displaymatrix() {
    if (vertexcount == 0) {
        cout << "\n!! Add the vertices first !!\n";
        return;
    }

    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < vertexcount; i++) {
        cout << i << "  ";
    }
    cout << "\n";

    for (int i = 0; i < vertexcount; i++) {
        cout << i << "  ";
        for (int j = 0; j < vertexcount; j++) {
            if (matrix[i][j] == N)
                cout << "N  ";
            else
                cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
}

void Graph::warshalls() {
    if (vertexcount == 0) {
        cout << "\n!! Add the vertices first !!\n";
        return;
    }

    // Floyd-Warshall in-place
    for (int k = 0; k < vertexcount; k++) {
        for (int i = 0; i < vertexcount; i++) {
            for (int j = 0; j < vertexcount; j++) {
                if (matrix[i][k] != N && matrix[k][j] != N &&
                    matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    // Display result
    cout << "\nShortest Path Matrix:\n   ";
    for (int i = 0; i < vertexcount; i++) {
        cout << i << "  ";
    }
    cout << "\n";

    for (int i = 0; i < vertexcount; i++) {
        cout << i << "  ";
        for (int j = 0; j < vertexcount; j++) {
            if (matrix[i][j] == N)
                cout << "N  ";
            else
                cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }

    // Show pairwise paths
    cout << "\nShortest paths between all pairs:\n";
    for (int i = 0; i < vertexcount; i++) {
        for (int j = 0; j < vertexcount; j++) {
            cout << "From " << i << " to " << j << ": ";
            if (matrix[i][j] == N)
                cout << "Not reachable\n";
            else
                cout << matrix[i][j] << "\n";
        }
    }
}

int main() {
    Graph obj;
    int ch;

    do {
        cout << "\n*************** MENU ***************\n";
        cout << "1. Input Graph (Vertices and Edges)\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Run Floyd-Warshall Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: obj.input(); break;
            case 2: obj.displaymatrix(); break;
            case 3: obj.warshalls(); break;
            case 4: cout << "\n!! THANK YOU !!\n"; break;
            default: cout << "\n!! INVALID CHOICE !!\n";
        }
    } while (ch != 4);

    return 0;
}
