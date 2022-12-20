#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 +2;
const int INF = 1e9;

int n, m;
int cost = 0;

vector<vector<int>> g[N];
vector<bool> visited(N, false);
vector<int> dist(N);
vector<int> parent(N);

void primsMST(int source){
    for(int i=0; i<n; i++){
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0, source});          // Weight, vertex

    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        // x[0] ---> Weight         x[1] ---> Vertex
        visited[x[1]] = true;

        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost += x[0];


        // it[0] ---> Which element 
        // it[1] ---> Weight of edge of that element
        for(auto it: g[x[1]]){
            if(visited[it[0]]){
                continue;
            }
            if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main(){
    cout<<"Enter the number of vertex: "<<endl;
    cin>>n;

    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    for(int i=0; i<m; i++){
        int u, v, w;
        cout<<"Enter Starting vertex-----Ending vertex-----Weight: "<<endl;
        cin>>u>>v>>w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    primsMST(0);
    cout<<cost<<endl;

    return 0;
}