/* Bipartite Graphs are those whose nodes can be coloured in two different colors and no two adjacent nodes are of same color. */

#include<bits/stdc++.h>
using namespace std;

bool Bipartite(vector<int>* edges, int n) {
    if(n == 0)
        return true;

    unordered_set<int> sets[2];
    vector<int> pending;
    sets[0].insert(0);
    pending.push_back(0);
    while(pending.size() > 0) {
        int current = pending.back();
        pending.pop_back();
        int currentSet = sets[0].count(current) > 0 ? 0 : 1;
        for(int i=0;i<edges[current].size();++i) {
            int neighbour = edges[current][i];
            if(sets[0].count(neighbour) == 0 && sets[1].count(neighbour) == 0) {
                sets[1 - currentSet].insert(neighbour);
                pending.push_back(neighbour);
            } else if(sets[currentSet].count(neighbour) > 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    while(true) {
        int n;
        cin>>n;
        if(n == 0)
            break;
        vector<int>* edges = new vector<int>[n];
        int m;
        cin>>m;
        for(int i=0;i<m;++i) {
            int j, k;
            cin>>j>>k;
            edges[j].push_back(k);
            edges[k].push_back(j);
        }
        bool ans = Bipartite(edges, n);
        if(ans) {
            cout<<"Bipartite Graph"<<endl;
        } else {
            cout<<"Non Bipartite Graph"<<endl;
        }
    }
    return 0;
}