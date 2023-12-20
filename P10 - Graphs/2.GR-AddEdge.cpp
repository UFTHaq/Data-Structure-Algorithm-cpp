#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Graph {
private:
    unordered_map<string, unordered_set<string>> adjList {};

public:
    void printGraph() {
        cout << "Graph:\n";
        unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
        while (kvPair != adjList.end()) {
            cout  << kvPair->first << ": [ ";  // this prints out the vertex
            unordered_set<string>::iterator edge = kvPair->second.begin();
            while (edge != kvPair->second.end()) {
                cout  << edge->data() << " ";  // this prints out edges
                edge++;
            }
            cout << "]" << endl;
            kvPair++;
        }
    }

    bool addVertex(string vertex) {
        if (adjList.count(vertex) == 0) {
        // if (adjList.find(vertex) == adjList.end()) {
            adjList[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(string vertex1, string vertex2) {
        // if (adjList.find(vertex1) != adjList.end() && adjList.find(vertex2) != adjList.end()) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList[vertex1].insert(vertex2);
            adjList[vertex2].insert(vertex1);
            return true;
        } else {
            return false;
        } 
    }


};



int main() {

    Graph* myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");

    myGraph->addEdge("A", "B");
    
    myGraph->printGraph();

    
       
}

