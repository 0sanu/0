#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node {
    int vertex;
    node* next;
}* adj_list[10];

class Graph {
    int n;
    public:
    stack <int> s;
    queue <int> q;
    void read_graph(node* adj_list[10], int n);
    void create();
    void bfs();
    void dfs();
};

void Graph::read_graph(node* adj_list[10], int n) {
    int i, j;
    char ans;
    node* p, * c;
    for (i = 1; i <= n; i ++) {
        for (j = i + 1; j <= n; j ++)  {
            cout << "\nAre vertices " << i <<" & " << j << " adjacent? (Y/N): ";
            cin >> ans;
            if (ans == 'y' || ans == 'Y') {
                c = new node();
                c -> vertex = j;
                c -> next = nullptr;
                if (adj_list[i] == nullptr) {
                    adj_list[i] = c;
                }
                else {
                    p = adj_list[i];
                    while (p -> next != nullptr) {
                        p = p -> next;
                    }
                    p -> next = c;
                }
                c = new node();
                c -> vertex = i;
                c -> next = nullptr;
                if (adj_list[j] == nullptr) {
                    adj_list[j] = c;
                }
                else {
                    p = adj_list[j];
                    while (p -> next != nullptr) {
                        p = p -> next;
                    }
                    p -> next = c;
                }
            }
        }
    }
}

void Graph::create() {
    int n, i;
    cout << "\nNo. of vertices: ";
    cin >> n;
    for (i = 0; i < n; i ++) {
        adj_list[i] = nullptr;
    }
    read_graph(adj_list, n);
}

void Graph::dfs() {
    int sv, num;
    int visited[10] = {0};
    
    cout << "\nEnter starting vertex: ";
    cin >> sv;
    
    s.push(sv);
    
    while(!s.empty()) {
        num = s.top();
        s.pop();
        
        if (visited[num] == 0) {
            cout << num << " ";
            visited[num] = 1;
        }
        
        node* t = adj_list[num];
        while (t != NULL) {
            if (visited[t -> vertex] == 0) {
                s.push(t -> vertex);
            }
            t = t -> next;
        }
    }
}

void Graph::bfs() {
    int sv, num;
    int visited[10] = {0};
    
    cout << "\nEnter starting vertex: ";
    cin >> sv;
    
    q.push(sv);
    
    while(!q.empty()) {
        num = q.front();
        q.pop();
        
        if (visited[num] == 0) {
            cout << num << " ";
            visited[num] = 1;
        }
        node* t = adj_list[num];
        while(t != NULL) {
            if (visited[t -> vertex] == 0) {
                q.push(t -> vertex);
            }
            t = t -> next;
        }
    }
}

int main() {
    Graph g;
    g.create();
    g.dfs();
    g.bfs();
    return 0;
}
