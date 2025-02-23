#include<iostream>
#include<unordered_map>
#include<list>
#include<limits.h>
#include<vector>
using namespace std;


class Graph{
    public:
        unordered_map<int, list<pair<int, int> > > adjList;

        void addEdge(int u, int v, int wt, bool direction){
            // direction -> 0 -- undirected
            // direction -> 1 -- directed
            if(direction == 0){
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }
            else{
                adjList[u].push_back({v,wt});
            }
        }

        void prtadjList(){
            for(auto i: adjList){
                cout << i.first << "-> ";
                for(auto j: i.second){
                    cout << "{" <<j.first<<", "<<j.second<<"}, ";
                }cout <<endl;
            }
        }

        // void bellmanFord(int n, char src){
        //     // initial state
        //     vector<int> dist(n,INT_MAX);
        //     dist[src-'A'] = 0;
        //     //N-1 times -- relaxation
        //     for(int i=1; i<n; i++){

        //         // traverse on entire edge list
        //         for(auto a: adjList){
        //             for(auto b: a.second){
        //                 char u= a.first;
        //                 char v = b.first;
        //                 int wt = b.second;
        //                 if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']){
        //                     dist[v-'A'] = dist[u-'A'] + wt;
        //                 }
        //             }
        //         }
        //     }
        //     // yaha tak shortest dist ready hai 
        //     // check for -ve cycle
        //     // 1 time relaxation
        //     bool anyUpdate = false;
        //     for(auto a: adjList){
        //         for(auto b: a.second){
        //             char u= a.first;
        //             char v = b.first;
        //             int wt = b.second;
        //             if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']){
        //                 anyUpdate = true;
        //                 break;
        //                 dist[v-'A'] = dist[u-'A'] + wt;
        //             }
        //         }
        //     }
        //     if(anyUpdate == true){
        //         cout << "Negative Cylce" << endl;
        //     }
        //     else{
        //         cout << "no negative cycle" << endl;
        //         cout << "Printing dist array: ";
        //         for(auto i: dist){
        //             cout<<i<<", ";
        //         }cout <<endl;
        //     }
        // }

        void floydWarshall(int n){
            // initial state 
            vector<vector<int> > dist(n, vector<int>(n,1e9));
            // diagonal pe 0
            for(int i=0; i<n; i++){
                dist[i][j] = 0;
            }

            // kuch weights graph ke andar bhi given hai 
            // update dist array accordingly 
            for(auto a: adjList){
                for(auto b: a.second){
                    int u = a.first;
                    int v = b.first;
                    int wt = b.second;
                    dist[u][v] = wt;
                }
            }

            // maihn logic -- helper 
            for(int helper=0; helper<n; helper++){
                for(int src=0; src<n; src++){
                    for(int dest=0; dest<n; dest++){
                        dist[src][dest] = min(dest[src][dest], dist[src][helper]+ dist[helper][dest]);
                    }
                }
            }

            //printing dist array 
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << dist[i][j] << " ";
                }
                cout <<endl;
            }
        }

};


int main(){
    Graph g;

    // g.addEdge('A','B',-1,1);
    // g.addEdge('B','E',2,1);
    // g.addEdge('E','D',-3,1);
    // g.addEdge('D','C',5,1);
    // g.addEdge('A','C',4,1);
    // g.addEdge('B','C',3,1);
    // g.addEdge('B','D',2,1);
    // g.addEdge('D','B',1,1);
    
    // // g.prtadjList();

    // g.bellmanFord(5, 'A');

    g.addEdge(0,1,3,1);
    g.addEdge(1,0,2,1);
    g.addEdge(0,3,5,1);
    g.addEdge(1,3,4,1);
    g.addEdge(3,2,2,1);
    g.addEdge(2,1,1,1);

    g.floydWarshall(4);

    return 0;
}