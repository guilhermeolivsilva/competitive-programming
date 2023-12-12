#include <algorithm>
#include <iostream>
#include <vector>


class Node {
    private:
        int nodeId;
        bool isVisited;
        std::vector<int> neighbors;

    public:
        Node() = default;
        Node(int);
        int getNodeId() const;
        void visitNode();
        bool getVisitStatus() const;
        std::vector<int> getNeighbors() const;
        void addNeighbor(int);
};


Node::Node(int _nodeId) {
    nodeId = _nodeId;
    isVisited = false;
}


int Node::getNodeId() const {
    return nodeId;
}


void Node::visitNode() {
    isVisited = true;
}


bool Node::getVisitStatus() const {
    return isVisited;
}


std::vector<int> Node::getNeighbors() const {
    return neighbors;
}


void Node::addNeighbor(int neighborId) {
    neighbors.push_back(neighborId);
}


void DFS(std::vector<Node> &nodesVector, int rootId, int &componentVertices) {
    if(!nodesVector[rootId - 1].getVisitStatus()) {
        nodesVector[rootId - 1].visitNode();
        componentVertices++;
    } else {
        return;
    }

    for(auto const& iterator : nodesVector[rootId - 1].getNeighbors()) {
        DFS(nodesVector, iterator, componentVertices);
    }
}
