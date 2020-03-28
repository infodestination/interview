#include <iostream>
#include <set>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    void toplogicalSortUtil(int v, bool visited[], stack<int>& stck);
    public:
    Graph(int v);
    void addEdge(int v, int w);
    void topologicalSort();
};
Graph::Graph(int v) {
    this->V = v;
    adj = new list<int>[v];
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}
void Graph::toplogicalSortUtil(int v, bool visited[], stack<int>& stck) {
    visited[v] = true;
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            if(!visited[*i])
                toplogicalSortUtil(*i, visited, stck);    
    }
    stck.push(v);
}
void Graph::topologicalSort() {  
    stack<int> stck;
    bool* visidted = new bool[this->V];
    for(int i =0 ; i<this->V; i++) {
        visidted[i] = false;
    }
    
    for(int i =0 ; i<this->V; i++) {
        if(visidted[i] == false)
          toplogicalSortUtil(i, visidted, stck);
    }
    
    while(stck.empty() == false) {
        cout<<stck.top()<< " ";
        stck.pop();
    }
    cout<<endl;
}
int main() {
    Graph g(8);
    g.addEdge(4, 5);
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(3, 5);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    cout << "Topological Sort of the given is "<<endl;
    g.topologicalSort(); 
    return 0;
}
