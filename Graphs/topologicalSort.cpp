#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int> > adj;

        void addEdge(int u, int v, bool direction){
            // direction ->0 undirected
            // direction -> 1 directed
            if(direction == 1){
                adj[u].push_back(v);
            }
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        void prtAdj(){
            for(auto i: adj){
                cout << i.first << ": { ";
                for(auto j: i.second){
                    cout << j << ",";
                }
                cout <<"}" << endl;
            }
        }

        void topoSortDfs(int src, map<int,bool> &visited, stack<int> &st){
            visited[src] = true;

            for(auto nbr: adj[src]){
                if(!visited[nbr]){
                    topoSortDfs(nbr,visited,st);
                }
            }
            st.push(src); 
        }

        void topoSortBfs(int n){
            queue<int> q;
            map<int,int> indegree;

            // Initialise kardi indegree sabki
            for(auto i: adj){
                for(auto nbr: i.second){
                    indegree[nbr]++;
                }
            }
            // print indegree
            // for(auto i: indegree){
            //     cout << i.first << "->" << i.second << endl;
            // }

            // push all zero indegree wali node into queue
            for(int node=0; node<n; node++){
                if(indegree[node] == 0){
                    q.push(node);
                }
            }

            // BFS chalate hai 
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                cout << frontNode << ", ";

                for(auto nbr: adj[frontNode]){
                    indegree[nbr]--;

                    // check for zero
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }

        void shortestPathBfs(int src, int dest){
            queue<int> q;
            map<int,bool> visited;
            map<int,int> parent;

            // initial state
            q.push(src);
            visited[src] = true;
            parent[src] = -1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                for(auto nbr: adj[frontNode]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        parent[nbr] = frontNode;
                        visited[nbr] = true;
                    }
                }
            }

            // parent array ready hoga
            vector<int> ans;
            while(dest != -1){
                ans.push_back(dest);
                dest = parent[dest];
            }

            reverse(ans.begin(), ans.end());
            // printing
            for(auto i:ans){
                cout << i << " ";
            }
        }
};


int main(){
    Graph g;

    g.addEdge(0,5,0);
    g.addEdge(5,4,0);
    g.addEdge(4,3,0);
    g.addEdge(0,6,0);
    g.addEdge(6,3,0);
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);

    // int n=8;f
    int src =0;
    int dest = 3;

    g.shortestPathBfs(src,dest);



    // g.prtAdj();

    // int n =8;
    // g.topoSortBfs(n);

    // int n=8;
    // map<int,bool> visited;
    // stack<int> st;

    // for(int node=0; node<n; node++){
    //     if(!visited[node]){
    //         g.topoSortDfs(node, visited, st);
    //     }
    // }
    // cout << "Printing ht topo oreder" << endl;
    // while(!st.empty()){
    //     cout << st.top();
    //     st.pop();
    // }
    
    return 0;
}