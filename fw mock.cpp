#include <iostream>
using namespace std;

// Define INF as a constant outside the class
const int INF = 99999;

class Graph {
private:
    int matrix[20][20];
    int vertexcount;

public:
    Graph() {
        vertexcount = 0;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                matrix[i][j] = INF; // Initialize all values to INF
            }
        }
    }

    void inputGraph();
    void displayMatrix();
    void floydWarshall();
};

void Graph::inputGraph() {
    int edges, a, b, cost;

    cout << "Enter number of vertices: ";
    cin >> vertexcount;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Initialize matrix: 0 for same vertex, INF for others
    for (int i = 0; i < vertexcount; i++) {
        for (int j = 0; j < vertexcount; j++) {
            if (i == j) {
                matrix[i][j] = 0; // Distance to itself is 0
            } else {
                matrix[i][j] = INF; // No direct connection initially
            }
        }
    }

    for (int i = 0; i < edges; i++) {
        cout << "\nEnter source and destination (0 to " << vertexcount - 1 << "): ";
        cin >> a >> b;
        cout << "Enter cost: ";
        cin >> cost;

        if (a >= 0 && a < vertexcount && b >= 0 && b < vertexcount) {
            matrix[a][b] = cost;
        } else {
            cout << "Invalid vertices. Try again.\n";
            i--; // repeat input for this edge
        }
    }
}

void Graph::displayMatrix() {
    cout << "\nAdjacency Matrix (Costs between vertices):\n\n\t";
    for (int i = 0; i < vertexcount; i++)
        cout << i << "\t";
    cout << "\n";

    for (int i = 0; i < vertexcount; i++) {
        cout << i << "\t";
        for (int j = 0; j < vertexcount; j++) {
            if (matrix[i][j] == INF)
                cout << "-\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void Graph::floydWarshall() {
    for (int k = 0; k < vertexcount; k++) {
        for (int i = 0; i < vertexcount; i++) {
            for (int j = 0; j < vertexcount; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    cout << "\nShortest Path Matrix (Minimum distances between vertices):\n\n\t";
    for (int i = 0; i < vertexcount; i++)
        cout << i << "\t";
    cout << "\n";

    for (int i = 0; i < vertexcount; i++) {
        cout << i << "\t";
        for (int j = 0; j < vertexcount; j++) {
            if (matrix[i][j] == INF)
                cout << "-\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nList of Shortest Paths:\n";
    for (int i = 0; i < vertexcount; i++) {
        for (int j = 0; j < vertexcount; j++) {
            cout << "From Vertex " << i << " to Vertex " << j << " : ";
            if (matrix[i][j] == INF)
                cout << "No path available.\n";
            else
                cout << matrix[i][j] << " units\n";
        }
    }
}

int main() {
    Graph g;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Graph\n";
        cout << "2. Display Adjacency Matrix\n";
        cout << "3. Run Floyd-Warshall Algorithm\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.inputGraph();
                break;
            case 2:
                g.displayMatrix();
                break;
            case 3:
                g.floydWarshall();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

