/*
Notes-->

Spanning Tree--->
        A connected subgraph 'S' of Graph G(V, E) is said to be spanning iff(if and only if):
            1---> 'S' should contain all the vertices of G
            2---> 'S' should contain (v-1) edges

        Here all the vertices are reachable and also as it is a tree so it does not contain a cycle

        If you have complete graph and you want to find the number of spanning trees then formula is:
                    n^(n-2) 

            where n---> No. of vertices

            
Cost of Spanning Tree--->
        Cost of spanning tree is the total weight of all the edges of spanning tree

MST (Minimum Spanning Tree)--->
        Minimum spanning tree is the spanning tree where the cost is minimum among all the spanning trees...
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
vector<int> parent(N);
vector<int> sz(N);      // Size

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);     // Path compression
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(sz[a] < sz[b]){
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    for(int i=0; i<N; i++){
        make_set(i);
    }

    int n;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int w, u, v;
        cout<<"Enter Starting vertice----Ending vertice---Weight of Edge"<<endl;
        cin>>u>>v>>w;

        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());
    int cost = 0;

    for(auto i : edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int x = find_set(u);
        int y = find_set(v);

        if(x == y){
            // Cycle is present so don't include the edges
            continue;
        }
        else{
            cout<<u<<" "<<v<<endl;
            cost += w;
            union_sets(u, v);
        }
    }

    cout<<"Total cost is: "<<endl;

    return 0;
}

/*
Input--->


Enter the number of vertices: 
8
Enter the number of edges: 
9
Enter Starting vertice----Ending vertice---Weight of Edge
1 2 5
Enter Starting vertice----Ending vertice---Weight of Edge
2 3 6
Enter Starting vertice----Ending vertice---Weight of Edge
4 3 2
Enter Starting vertice----Ending vertice---Weight of Edge
1 4 9
Enter Starting vertice----Ending vertice---Weight of Edge
3 5 5
Enter Starting vertice----Ending vertice---Weight of Edge
5 6 10
Enter Starting vertice----Ending vertice---Weight of Edge
6 7 7
Enter Starting vertice----Ending vertice---Weight of Edge
7 8 1
Enter Starting vertice----Ending vertice---Weight of Edge
8 5 1

Output--->

7 8
8 5
4 3
1 2
3 5
2 3
6 7

Total Cost is: 27
*/