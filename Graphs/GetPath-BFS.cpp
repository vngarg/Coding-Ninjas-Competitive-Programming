#include<bits/stdc++.h>
using namespace std;

int BFS(int** edges, int n, bool* visited, int start, int end, map<int, int> &m) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int i=0;i<n;++i) {
            if(!visited[i] && edges[current][i] == 1) {
                m[i] = current;
                if(i == end)
                    return 0;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return -1;
}

int main() {
    int vertices, edgesNo;
    cin>>vertices>>edgesNo;

    int** edges = new int*[vertices];
    for(int i=0;i<vertices;++i) {
        edges[i] = new int[vertices];
        for(int j=0;j<vertices;++j)
            edges[i][j] = 0;
    }

    bool* visited = new bool[vertices];
    for(int i=0;i<vertices;++i)
        visited[i] = false;

    for(int i=0;i<edgesNo;++i) {
        int a, b;
        cin>>a>>b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }

    int start, end;
    cin>>start>>end;

    visited[start] = true;
    map<int, int> m;
    map<int, int>::iterator it;

    int value = BFS(edges, vertices, visited, start, end, m);
    int index = end;
    
    while(index != start && value != -1) {
        cout<<index<<" ";
        index = m[index];
    }

    if(value != -1)
        cout<<index;

    return 0;
}