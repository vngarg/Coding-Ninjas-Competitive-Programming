#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges, int start, unordered_set<int> &visited, stack<int> &finsishStack) {
    visited.insert(start);
    for(int i = 0;i < edges[start].size(); ++i) {
        int adjacent = edges[start][i];
        if(visited.count(adjacent) == 0)
            dfs(edges, adjacent, visited, finsishStack);
    }
    finsishStack.push(start);
}

void dfs2(vector<int>* edges, int start, unordered_set<int>* component, unordered_set<int> &visited) {
    visited.insert(start);
    component->insert(start);
    for(int i = 0;i<edges[start].size();++i) {
        int adjacent = edges[start][i];
        if(visited.count(adjacent) == 0)
            dfs2(edges, adjacent, component, visited);
    }
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges, vector<int>* edgesT, int n) {
    unordered_set<int> visited;
    stack<int> finisedVertices;
    for(int i=0;i<n;++i) {
        if(visited.count(i) == 0)
            dfs(edges, i, visited, finisedVertices);
    }

    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    visited.clear();
    while(finisedVertices.size() != 0) {
        int element = finisedVertices.top();
        finisedVertices.pop();
        if(visited.count(element) != 0)
            continue;

        unordered_set<int>* component = new unordered_set<int>();
        dfs2(edgesT, element, component, visited);
        output->insert(component);
    }
    return output;
}

int main() {
    int n;
    cin>>n;
    vector<int>* edges = new vector<int>[n];
    vector<int>* edgesT = new vector<int>[n];

    int m;
    cin>>m;
    for(int i=0;i<m;++i) {
        int j, k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);
        edgesT[k-1].push_back(j-1);
    }
    unordered_set<unordered_set<int>*>* components = getSCC(edges, edgesT, n);
    unordered_set<unordered_set<int>*>::iterator it = components->begin();
    cout<<endl<<"STRONGLY CONNECTED COMPONENTS ARE"<<endl;
    while(it != components->end()) {
        unordered_set<int>* component = *it;
        unordered_set<int>::iterator it2 = component->begin();
        while(it2 != component->end()) {
            cout<< *it2 + 1 << " ";
            ++it2;
        }
        cout<<endl;
        ++it;
    }

    delete components;
    delete [] edges;
    delete [] edgesT;

    return 0;
}