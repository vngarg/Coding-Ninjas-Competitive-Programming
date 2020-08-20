#include<bits/stdc++.h>
using namespace std;

vector<int> DFS(int** edges, int n, bool* visited, int start, int end) {
    vector<int> result;

    if(start == end) {
        result.push_back(end);
        return result;
    }

    for(int i=0;i<n;++i) {
        if(!visited[i] && edges[start][i] == 1) {
            visited[i] = true;
            result = DFS(edges, n, visited, i, end);
            if(result.size() != 0) {
                result.push_back(start);
                return result;
            }
        }
    }

    return result;
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

    vector<int> result;
    vector<int>:: iterator it;

    visited[start] = true;

    result = DFS(edges, vertices, visited, start, end);

    if(result.size() != 0) 
        for(int i=0;i<result.size();++i)
            cout<<result[i]<<" ";

    return 0;
}