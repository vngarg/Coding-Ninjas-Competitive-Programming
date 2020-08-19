#include<bits/stdc++.h>
using namespace std;

bool hasPath(int** edges, int n, bool* visited, int start, int end) {
    visited[start] = true;
    if(edges[start][end] == 1)
        return true;

    if(start == end)
        return true;

    for(int i=0;i<n;++i) {
        if(!visited[i] && edges[start][i] == 1)
            return hasPath(edges, n, visited, i, end);
    }

    return false;
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
    
    int start, end;
    cout<<"ENTER TWO VERTICES TO FIND PATH: "<<endl;
    cin>>start>>end;
    if(hasPath(edges, vertices, visited, start, end))
        cout<<"PATH IS PRESENT";
    else 
        cout<<"PATH IS NOT PRESENT";

    delete[] visited;
    for(int i=0;i<vertices;++i)
        delete[] edges[i];
    delete[] edges;

    return 0;
}