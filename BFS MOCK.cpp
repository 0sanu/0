#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int vertexCount;
    int matrix[20][20];

public:
    Graph() {
        vertexCount = 0;
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                matrix[i][j] = 0;
    }

    void input() {
        int edges;
        cout << "Enter number of vertices: ";
        cin >> vertexCount;
        cout << "Enter number of edges: ";
        cin >> edges;

        for (int i = 0; i < edges; i++) {
            int a, b;
            cout << "Edge " << i + 1 << " (src dest): ";
            cin >> a >> b;
            if (a >= 0 && a < vertexCount && b >= 0 && b < vertexCount) {
                matrix[a][b] = 1;
                matrix[b][a] = 1;
            } else {
                cout << "Invalid edge. Try again.\n";
                i--;
            }
        }
    }

    void dfs(int start) {
        bool visited[20] = { false };
        stack<int> s;

        cout << "\nDFS (using stack): ";
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                // Push neighbors in reverse order for natural left-to-right traversal
                for (int i = vertexCount - 1; i >= 0; i--) {
                    if (matrix[current][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }

        cout << endl;
    }

    void bfs(int start) {
        bool visited[20] = { false };
        queue<int> q;
        cout << "\nBFS: ";
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < vertexCount; i++) {
                if (matrix[v][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.input();

    int start;
    cout << "Enter starting vertex for traversal: ";
    cin >> start;

    g.dfs(start);
    g.bfs(start);

    return 0;
}
