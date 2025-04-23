/*Represent a given graph using adjacency matrix to find length of shortest path between every pair
of vertices. Use Floyd Warshall algorithm to implement it.*/

#include <iostream>
using namespace std;

class Graph
{
    private:
        int vertexcount;
        int matrix[20][20];
        int N = 99999;
    public:
        Graph()
        {
            vertexcount = 0;
        }

        void addvertex();
        void addedge();
        void displaymatrix();
        void warshalls();
};

void Graph :: addvertex()
{
    cout<<"\nEnter the number of vertices: ";
    cin>>vertexcount;
    if(vertexcount > 0)
    {
        for(int i=0; i<vertexcount; i++)
        {
            for(int j=0; j<vertexcount; j++)
            {
                if(i == j)
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    matrix[i][j] = N;
                }
            }
        }
        cout<<"\n!! Vertex added successfully !!\n";
    }
    else
    {
        cout<<"\n!! Invalid number of vertices !!\n";
    }
}

void Graph :: addedge()
{
    if(vertexcount == 0)
    {
        cout<<"\n!! Add the vertes first !!\n";
    }
    else
    {
        int a,b,c;
        cout<<"\nEnter source: ";
        cin>>a;
        cout<<"\nEnter destination: ";
        cin>>b;
        cout<<"\nEnter distance: ";
        cin>>c;
        if(a>=0 && a<vertexcount && b>=0 && b<vertexcount)
        {
            matrix[a][b] = c;
            cout<<"\n!! Edge added successfully between vertices "<<a<<" to "<<b<<" of distance "<<c<<" !!\n";
        }
        else
        {
            cout<<"\n!! Invalid source and destination !!\n";
        }
    }
}

void Graph :: displaymatrix()
{
    if(vertexcount == 0)
    {
        cout<<"\n!! Add the vertices first !!\n";
    }
    else
    {
        cout<<"\nAdjacency Matrix: \n   ";
        for(int i=0; i<vertexcount; i++)
        {
            cout<<i<<"  ";
        }
        cout<<endl;
        for(int i=0; i<vertexcount; i++)
        {
            cout<<i<<"  ";
            for(int j=0; j<vertexcount; j++)
            {
                if(matrix[i][j] == N) 
                {
                    cout<<"N  ";
                } 
                else 
                {
                    cout<<matrix[i][j]<<"  ";
                }
            }
            cout<<endl;
        }
    }
}

void Graph :: warshalls()
{
    if(vertexcount == 0)
    {
        cout<<"\n!! Add the vertices first !!\n";
    }
    else
    {
        for(int i=0; i<vertexcount; i++)
        {
            for(int j=0; j<vertexcount; j++)
            {
                for(int k=0; k<vertexcount; k++)
                {
                    if(matrix[j][i]+matrix[i][k] < matrix[j][k])
                    {
                        matrix[j][k] = matrix[j][i]+matrix[i][k];
                    }
                }
            }
        }
        cout<<"\nShortest path matrix: \n   ";
        for(int i=0; i<vertexcount; i++)
        {
            cout<<i<<"  ";
        }
        cout<<endl;
        for(int i=0; i<vertexcount; i++)
        {
            cout<<i<<"  ";
            for(int j=0; j<vertexcount; j++)
            {
                if(matrix[i][j] == N) 
                {
                    cout<<"N  ";
                } 
                else 
                {
                    cout<<matrix[i][j]<<"  ";
                }
            }
            cout<<endl;
        }
        cout<<"\n\nShortest path between each pair: \n";
        for(int i=0; i<vertexcount; i++) 
        {
            for(int j=0; j<vertexcount; j++) 
            {
                if(matrix[i][j] == N) 
                {
                    cout<<"Path from "<<i<<" to "<<j<<" : ";
                    cout<<"Not exits!\n";
                } 
                else 
                {
                    cout<<"Path from "<<i<<" to "<<j<<" : ";
                    cout<<matrix[i][j]<<"\n";
                }
            }
        }
    }
}

int main()
{
    Graph obj;
    int ch;
    do 
    {
        cout<<"\n*****************MENU***************\n\n";
        cout<<"\n1.Add Vertices";
        cout<<"\n2.Add Edges";
        cout<<"\n3.Display Adjacency Matrix";
        cout<<"\n4.Run Floyd-Warshall Algorithm";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice: ";
        cin>> ch;
        switch (ch) {
            case 1:
                obj.addvertex();
                break;

            case 2:
                obj.addedge();
                break;

            case 3:
                obj.displaymatrix();
                break;

            case 4:
                obj.warshalls();
                break;

            case 5:
                cout<<"\n!! THANK YOU !!\n\n";
                break;

            default:
                cout<<"\n!! INVALID CHOICE !!\n";
        }
    }
    while(ch != 5);
    return 0;
}
