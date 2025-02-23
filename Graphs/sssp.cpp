#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

// directed and weighted 
class Graph{
    public:
        unordered_map<int,list<pair<int,int> > > adj;

        void addEdge(int u, int v,int wt, bool direction){
            // direction - 0 undirected
            // direction - 1 - directed

            if(direction == 1){
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }

        void prtadjList(){
            for(auto i : adj){
                cout << i.first << " : { ";
                for(auto j: i.second){
                    cout << j.first << " , " << j.second << "), ";
                }
                cout << endl;
            }
        }

        void topoOrderDfs(int src, stack<int>& topo,unordered_map<int, bool> visited){
            visited[src] = true;

            for(auto nbrPair : adj[src]){
                int nbrNode = nbrPair.first;
                // int nbrDist = nbrPair.second;
                if(!visited[nbrNode]){
                    topoOrderDfs(nbrNode, topo, visited);
                }
            }

            topo.push(src);

        }
};


int main(){
    Graph g;

    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    g.prtadjList();

    int src =0;
    stack<int> topoOrder;
    unordered_map<int,bool> visited;
    g.topoOrderDfs(src, topoOrder, visited);

    cout << "Printing topo order" << endl;
    while(!topoOrder.empty()){
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }
    
    return 0;
}