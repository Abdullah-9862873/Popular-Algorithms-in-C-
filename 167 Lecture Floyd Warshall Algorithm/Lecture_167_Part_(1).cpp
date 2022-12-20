/*
Problem----> Find the shortest path between u and v

                0----------1
                  \       /
                    \   /
                      \/
                    /    \ 
                 2----------3

                 Weights----> 
                            0---1 = 5
                            0---3 = 10
                            1---2 = 3
                            2---3 = 1
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    vector<vector<int>> graph = {   {0,5, INF, 10},
                                    {INF, 0, 3, INF},
                                    {INF, INF, 0, 1},
                                    {INF, INF, INF, 0},
    };

    vector<vector<int>> dist = graph;

    int n = graph.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j] == INF){
                cout<<"INF"<<" ";
            }else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    cout<<"The shortest distance between 1 and 3 is: "<<endl; 
    cout<<dist[1][3]<<endl;


    return 0;
}

/*
Output--->

0 5 8 9       
INF 0 3 4     
INF INF 0 1   
INF INF INF 0 

The shortest distance between 1 and 3 is: 
4
*/