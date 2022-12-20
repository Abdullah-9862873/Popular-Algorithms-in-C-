/*
Problem---> From a source vertex, find the shortest distance to all the vertixes of the graph

            Priority of Bleeman over Dijkstra----->
                    1---> It can work for negative weighted graph
                    2---> It can detect negative cycle by satisfying that if for some edge (u, v), dn-1(v) > dn-1(u) + w(u, v)

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

    vector<int> dist(n, INF);

    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int u, v, w;
        cout<<"Enter the starting vertex--- Ending vertex--- Weight"<<endl;
        cin>>u>>v>>w;

        edges.push_back({u,v,w});
    }
    int source;
    cout<<"Enter the source: "<<endl;
    cin>>source;

    dist[source] = 0;

    for(int i=0; i<n-1; i++){
        // Here n-1 is because the nodes start from 0 and not 1 so the nodes are (0 1 2 3 4) so we have to traverse til 3 which is <(n-1) that is <(4) that is 3
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[v] = min(dist[v], w + dist[u]);
        }
    }


        for(auto i: dist){
            cout<<i<<" ";
        }
        cout<<endl;


    return 0;
}
/*
Input--->

Enter the number of nodes: 
5
Enter the number of edges: 
8
Enter the starting vertex--- Ending vertex--- Weight
1 2 3
Enter the starting vertex--- Ending vertex--- Weight
3 2 5
Enter the starting vertex--- Ending vertex--- Weight
1 3 2
Enter the starting vertex--- Ending vertex--- Weight
3 1 1 
Enter the starting vertex--- Ending vertex--- Weight
1 4 2
Enter the starting vertex--- Ending vertex--- Weight
0 2 4
Enter the starting vertex--- Ending vertex--- Weight
4 3 -3
Enter the starting vertex--- Ending vertex--- Weight
0 1 -1
Enter the source: 
0

Output--->
0 -1 2 -2 1 
*/