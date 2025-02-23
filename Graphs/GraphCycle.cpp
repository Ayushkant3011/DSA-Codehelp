#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
        unordered_map<int, list<int> > adjList;

        void addEdge(int u, int v, bool direction){
            // direction-> 0 -> undirected
            // direction -> 1 -> directed
            if(direction == 1){
                // u se v ki taraf ekk edge hai 
                // u -> v
                adjList[u].push_back(v);
            }
            else{
                // direction =0;
                // u -- v
                // u -> v
                adjList[u].push_back(v);
                // v -> u
                adjList[v].push_back(u);
            }
            cout << endl << "Printing adjList" << endl;
            prtAdjList();
            cout << endl;
        }

        void prtAdjList(){
            for(auto i: adjList){
                cout << i.first << "-> {";
                for(auto neighbour : i.second){
                    cout << neighbour << ", ";
                }
                cout << "}" << endl;
            } 
        }

        bool checkCycleUndirectedBFS(int src){
            queue<int> q;
            unordered_map<int, bool> visited;
            unordered_map<int,int> parent;

            // initial state
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                for(auto nbr : adjList[frontNode]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    else if(visited[nbr] == true && nbr != parent[frontNode]){ // MOST IMP CONDITION
                        // cycle present
                        return true;
                    }
                }
            }
            // cycle not present
            return false;
        }
};

// template<typename T>

// class Graph{
//     public:
//         unordered_map<T, list<pair<T,int> > > adjList;

//         void addEdge(T u, T v, int wt, bool direction){
//             // direction -0 - undirected
//             // direction -1 - directed
//             if(direction == 1){
//                 // u->v
//                 adjList[u].push_back(make_pair(v,wt));
//             }
//             else{
//                 // direction= 0 
//                 // u ---- v
//                 // u->v
//                 // v->u
//                 adjList[u].push_back({v,wt});
//                 adjList[v].push_back({u,wt});
//             }
//             prtAdjList();
//             cout << endl;
//         }

//         void prtAdjList(){
//             for(auto i: adjList){
//                 cout << i.first << ": { ";
//                 for(pair<T, int>p : i.second){
//                     cout << "{"<<p.first<< ", " << p.second << "}, ";
//                 }
//                 cout << "}" <<endl;
//             }
//         }

//         void bfsTraversal(T src,unordered_map<T, bool> &vis){
//             // adjList already data memeber me hai 
//             // visisted chaiye 
            
//             // queue chaiye 
//             queue<T> q;

//             // initial state
//             q.push(src);
//             vis[src] = true;

//             while(!q.empty()){
//                 T frontNode = q.front();
//                 cout << frontNode << " ";
//                 q.pop();

//                 // Go to neighbour
//                 for(auto nbr: adjList[frontNode]){
//                     T nbrData = nbr.first;

//                     if(!vis[nbrData]){
//                         q.push(nbrData);
//                         vis[nbrData] = true;
//                     }
//                 }
//             }
//         }

//         void dfs(T src, unordered_map<char, bool> &vis){
//             vis[src] = true;
//             cout << src << " ";

//             for(auto nbr: adjList[src]){
//                 T nbrData = nbr.first;
//                 if(!vis[nbrData]){
//                     dfs(nbrData, vis);
//                 }
//             }
//         }
// };

int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);
    g.addEdge(2,5,0);


    int src = 0;
    bool isCyclic = g.checkCycleUndirectedBFS(src);
    if(isCyclic){
        cout << "Cycle Present" << endl;
    }
    else{
        cout << "Cycle Absent" << endl;
    }




    // Graph<int> g; //<int> means we are giving generalised data type 
    // Graph<char> g; 
    // g.addEdge('a','b',5,0);
    // g.addEdge('b','c',10,0);

    // g.addEdge('d','e',20,0); // disconnected Component

    // g.addEdge('f','f',50,0);

    // Graph<char> g;
    // g.addEdge('a','b',5,0);
    // // g.addEdge('a','c',10,0);
    // g.addEdge('c','d',20,0);
    // g.addEdge('c','e',50,0);
    // g.addEdge('d','e',20,0);
    // g.addEdge('e','f',50,0);

    // unordered_map<char, bool> vis;
    // for(char node='a';node<='f'; node++){
    //     if(!vis[node]){
    //         g.dfs(node, vis);
    //     }
    // }

    

    // for(char node='a'; node<='f'; node++){
    //     if(!vis[node]){
    //         g.bfsTraversal(node,vis);
    //     }
    // }

    


    return 0;
}


// DFS Se cycle Detection question on GFG 
// class solution{
//     public:
//         bool checkCycle(int src,unordered_map<int,bool>& vis, int parent,vector<int> adj[]){
//             vis[src] = true;

//             for(auto nbr : adj[src]){
//                 if(nbr == parent){
//                     continue;
//                 }
//                 if(!vis[nbr]){
//                     bool ans = checkCycle(nbr, vis, src, adj);
//                     if(ans == true){
//                         return true;
//                     }
//                 }
//                 else if(vis[nbr == 1 && nbr != parent]){
//                     return true;
//                 }
//             }
//             return false;
//         }

//         bool isCycle(int V, vector<int> adj[]){
//             unordered_map<int,bool> vis;
//             for(int i=0; i<V; i++){
//                 if(!vis[i]){
//                     int parent =-1;
//                     bool isCyclic = checkCycle(i,vis, parent);
//                     if(isCyclic == true){
//                         return true;
//                     }
//                 }
//             }
//             return false;
//         }
// };

// DFS CYCLIC DIRECTED GRAPH GFG QUESTION

class solution{
    public:
        bool checkCyclic(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsTrack, vector<int> adj[]){
            vis[src] = true;
            dfsTrack[src] = true;

            for(auto nbr: adj[src]){
                if(!vis[nbr]){
                    bool ans = checkCyclic(nbr, vis, dfsTrack, adj);
                    if(ans == true){
                        return true;
                    }
                }
                if(vis[nbr] == 1 && dfsTrack[nbr] == 1){
                    return true;
                }
            }

            // backTrack -- [Yahi galti karta hu]
            dfsTrack[src] = false;
            return false;
        }

        bool isCyclic(int V, vector<int> adj[]){
            unordered_map<int, bool> vis;
            unordered_map<int, bool> dfsTrack;

            for(int node=0; node<V; node++){
                if(!vis[node]){
                    bool isCyclic = checkCyclic(node, vis,dfsTrack,adj);
                    if(isCyclic){
                        return true;
                    }
                }
            }
            return false;
        }
};
