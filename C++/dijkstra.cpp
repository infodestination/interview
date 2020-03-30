#include <iostream>
#include <list>
#define MAX 999
using namespace std;

class Graph {
    int V; //number of vertices
    int Source;
    int cost[1024][1024];
    int *visited;
    int *parent;
    int *distance;
    public:
        Graph(int V, int source);
        void addEdge(int u, int v, int w);
        void display();
        int getNearest();
        void dijkstra();
};
Graph::Graph(int V, int source) {
    this->V = V;
    this->Source = source;
    for(int i =0;i<=V;i++) {
        for(int j=0;j<=V;j++) {
            cost[i][j] = MAX;
        }
    }
    this->visited = new int[V];
    this->parent = new int[V];
    this->distance = new int[V];
    for(int i=0; i<=V; i++) {
        visited[0] = false;
        distance[i] = MAX;
        parent[i] = i;
    }
    distance[source] = 0;
}
void Graph::addEdge(int u, int v, int weight) {
    cost[u][v] = weight;
}
void Graph::display() {
    cout<<"Node:\t\t Cost: \t\t\t Path"<<endl;
    for(int i=0;i<=V; i++) {
        cout<<i<<"\t\t"<<distance[i]<<"\t\t\t"<<" ";
        cout<<i<<" ";
        int parnode = parent[i];
        while(parnode != Source) {
            cout<<"<-"<<parnode<<" ";
            parnode = parent[parnode];
        }
        cout<<endl;
    }
}
int Graph::getNearest() {
    int minValue = MAX;
    int minNode = 0;
    for(int i=0;i<=V; i++) {
        if(!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minNode = i;
        }
    }
    return minNode;
}
void Graph::dijkstra() {
    for(int i=0; i<=V; i++) {
        int nearest = getNearest();
        visited[nearest] = true;
        for(int adj = 0; adj<=V; adj++) {
            if(cost[nearest][adj] != MAX && distance[adj]>distance[nearest]+cost[nearest][adj]) {
                distance[adj] = distance[nearest]+cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}
int main() {
    Graph g(5, 0);
    g.addEdge(0,1,5);
    g.addEdge(0,3,9);
    g.addEdge(0,4,2);
    g.addEdge(1,0,5);
    g.addEdge(1,2,2);
    g.addEdge(2,1,2);
    g.addEdge(2,3,3);
    g.addEdge(3,0,9);
    g.addEdge(3,2,3);
    g.addEdge(3,5,2);
    g.addEdge(4,0,2);
    g.addEdge(4,5,3);
    g.addEdge(5,3,2);
    g.addEdge(5,4,3);

    
    g.dijkstra();
    
    g.display();
    return 0;
}
