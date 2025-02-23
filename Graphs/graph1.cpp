#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// class Graph{
//     public:
//         unordered_map<int, list<int> > adjList;

//         void addEdge(int u, int v, bool direction){
//             // direction-> 0 -> undirected
//             // direction -> 1 -> directed
//             if(direction == 1){
//                 // u se v ki taraf ekk edge hai 
//                 // u -> v
//                 adjList[u].push_back(v);
//             }
//             else{
//                 // direction =0;
//                 // u -- v
//                 // u -> v
//                 adjList[u].push_back(v);
//                 // v -> u
//                 adjList[v].push_back(u);
//             }
//             cout << endl << "Printing adjList" << endl;
//             prtAdjList();
//             cout << endl;
//         }

//         void prtAdjList(){
//             for(auto i: adjList){
//                 cout << i.first << "-> {";
//                 for(auto neighbour : i.second){
//                     cout << neighbour << ", ";
//                 }
//                 cout << "}" << endl;
//             } 
//         }
// };

template<typename T>

class Graph{
    public:
        unordered_map<T, list<pair<T,int> > > adjList;

        void addEdge(T u, T v, int wt, bool direction){
            // direction -0 - undirected
            // direction -1 - directed
            if(direction == 1){
                // u->v
                adjList[u].push_back(make_pair(v,wt));
            }
            else{
                // direction= 0 
                // u ---- v
                // u->v
                // v->u
                adjList[u].push_back({v,wt});
                adjList[v].push_back({u,wt});
            }
            prtAdjList();
            cout << endl;
        }

        void prtAdjList(){
            for(auto i: adjList){
                cout << i.first << ": { ";
                for(pair<T, int>p : i.second){
                    cout << "{"<<p.first<< ", " << p.second << "}, ";
                }
                cout << "}" <<endl;
            }
        }

        void bfsTraversal(T src,unordered_map<T, bool> &vis){
            // adjList already data memeber me hai 
            // visisted chaiye 
            
            // queue chaiye 
            queue<T> q;

            // initial state
            q.push(src);
            vis[src] = true;

            while(!q.empty()){
                T frontNode = q.front();
                cout << frontNode << " ";
                q.pop();

                // Go to neighbour
                for(auto nbr: adjList[frontNode]){
                    T nbrData = nbr.first;

                    if(!vis[nbrData]){
                        q.push(nbrData);
                        vis[nbrData] = true;
                    }
                }
            }
        }

        void dfs(T src, unordered_map<char, bool> &vis){
            vis[src] = true;
            cout << src << " ";

            for(auto nbr: adjList[src]){
                T nbrData = nbr.first;
                if(!vis[nbrData]){
                    dfs(nbrData, vis);
                }
            }
        }
};

int main(){
    // Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0);
    // g.addEdge(2,3,0);

    // Graph<int> g; //<int> means we are giving generalised data type 
    // Graph<char> g; 
    // g.addEdge('a','b',5,0);
    // g.addEdge('b','c',10,0);

    // g.addEdge('d','e',20,0); // disconnected Component

    // g.addEdge('f','f',50,0);

    Graph<char> g;
    g.addEdge('a','b',5,0);
    // g.addEdge('a','c',10,0);
    g.addEdge('c','d',20,0);
    g.addEdge('c','e',50,0);
    g.addEdge('d','e',20,0);
    g.addEdge('e','f',50,0);

    unordered_map<char, bool> vis;
    for(char node='a';node<='f'; node++){
        if(!vis[node]){
            g.dfs(node, vis);
        }
    }

    

    // for(char node='a'; node<='f'; node++){
    //     if(!vis[node]){
    //         g.bfsTraversal(node,vis);
    //     }
    // }

    


    return 0;
}