#include<bits/stdc++.h>
using namespace std;

void DFS(int** edges, int n, bool* visited, int start) {
    visited[start] = true;
    cout<<start<<" ";

    for(int i=0;i<n;++i) {
        if(i == start)
            continue;
        else if(!visited[i] && edges[start][i] == 1)
            DFS(edges, n, visited, i);
    }
}

int main() {
    cout<<"ENTER THE NUBER OF VERTICES: "<<endl;
    int vertices;
    cin>>vertices;
    cout<<"ENTER THE NUMBER OF EDGES: "<<endl;
    int edgesNo;
    cin>>edgesNo;

    int** edges = new int*[vertices];
    for(int i=0;i<vertices;++i) {
        edges[i] = new int[vertices];
        for(int j=0;j<vertices;++j)
            edges[i][j] = 0;
    }

    bool* visited = new bool[vertices];
    for(int i=0;i<vertices;++i)
        visited[i] = false;

    cout<<"ENTER THE EDGES: "<<endl;
    for(int i=0;i<edgesNo;++i) {
        int a, b;
        cin>>a>>b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    cout<<"THE GRAPH IS: ";
    DFS(edges, vertices, visited, 0);

    delete[] visited;
    for(int i=0;i<vertices;++i)
        delete[] edges[i];
    delete[] edges;

    return 0;
}