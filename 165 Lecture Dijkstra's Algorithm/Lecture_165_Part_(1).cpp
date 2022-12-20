/*
------Dijkstra's Algorithm------

Problem---> Given a weighted graph. Find a single source shortest path from vertex u to all the vertex in the given
            graph. If node is unreachable then print -1...

        Dijkstra work for undirected and directed graph.
        Graph containing -ve weighted edges cannot be solved using dijkstra's algorithm


Approach--->
            1---> Initilaize distance value to all vertice in the given graph... Initialize the distance with Infinity
            2---> Assign distance value as 0 for source graph
            3--->While set is not empty
                    Pick a vertex u from set s that has minimum distance value.
                    Update the distance value of all adjacent vertices

set is in the form -----> (weight, vertex)
iterator is the form-----> (vertex, weight)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e7;

int main(){
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    vector<int> dist(n+1, INF);

    vector<vector<pair<int,int>>> graph(n+1);

    for(int i=0; i<m; i++){
        cout<<"Enter the starting vertice-----Ending vertice-----Weight"<<endl;
        int u, v, w;
        cin>>u>>v>>w;

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int source;
    cout<<"Enter the source: "<<endl;
    cin>>source;

    dist[source] = 0;
    set<pair<int,int>> s;

    s.insert({0, source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);

        for(auto it: graph[x.second]){
            if(dist[it.first] > dist[x.second] + it.second){
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for(int i=0; i<=n; i++){
        if(dist[i] < INF){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<-1<<" "<<endl;
        }
    }


    return 0;
}

/*
Input--->

Enter the number of nodes: 
4
Enter the number of edges: 
4
Enter the starting vertice-----Ending vertice-----Weight
1 2 24
Enter the starting vertice-----Ending vertice-----Weight
1 4 20
Enter the starting vertice-----Ending vertice-----Weight
3 1 3
Enter the starting vertice-----Ending vertice-----Weight
4 3 12
Enter the source: 
1

Output--->
0 24 3 15
*/