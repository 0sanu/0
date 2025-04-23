#include <iostream>
using namespace std;

class MST {
    int matrix[10][10];
    int visited[10];
    int cities;
public:
    MST() {
        cities = 0;
        for (int i = 0; i < 10; i++) {
            visited[i] = 0;
            for (int j = 0; j < 10; j++) {
                matrix[i][j] = 999; // Represents no connection
            }
        }
    }

    void input();
    void displayMatrix();
    void findMinimumCost();
};

void MST::input() {
    int edges, a, b, cost;
    cout << "Enter number of cities: ";
    cin >> cities;

    cout << "Enter number of phone lines (edges): ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        cout << "Enter cities (0 to " << cities-1 << ") to connect: ";
        cin >> a >> b;
        cout << "Enter cost of phone line: ";
        cin >> cost;

        if (a >= 0 && a < cities && b >= 0 && b < cities) {
            matrix[a][b] = matrix[b][a] = cost;
        } else {
            cout << "Invalid cities. Try again.\n";
            i--; // Ask again for this edge
        }
    }
}

void MST::displayMatrix() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            if (matrix[i][j] == 999)
                cout << "0\t";
            else
                cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

void MST::findMinimumCost() {
    int total = 0;
    int x, y, min;

    visited[0] = 1;

    cout << "\nConnections for Minimum Cost:\n";

    for (int i = 0; i < cities - 1; i++) {
        min = 999;
        x = y = 0;

        for (int j = 0; j < cities; j++) {
            if (visited[j]) {
                for (int k = 0; k < cities; k++) {
                    if (!visited[k] && matrix[j][k] < min) {
                        min = matrix[j][k];
                        x = j;
                        y = k;
                    }
                }
            }
        }

        visited[y] = 1;
        total += min;
        cout << "City " << x << " - City " << y << " : Cost = " << min << endl;
    }

    cout << "Total Minimum Cost: " << total << endl;
}

int main() {
    MST obj;
    obj.input();
    obj.displayMatrix();
    obj.findMinimumCost();
    return 0;
}