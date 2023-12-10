#include <algorithm>
#include <iostream>
#include <vector>


class Node {
    private:
        int nodeId;
        bool isVisited;

    public:
        std::vector<int> neighbors;

        Node();
        Node(int);
        ~Node() = default;
        int getNodeId() const;
        void addNeighbor(int);
        void visitNode();
        void resetVisitStatus();
        bool getVisitStatus() const;
        void printNode() const;
        bool operator==(const Node &_node) const;
};


Node::Node() {
    nodeId = -1;
    isVisited = false;
}


Node::Node(int _nodeId) {
    nodeId = _nodeId;
    isVisited = false;
}


int Node::getNodeId() const {
    return nodeId;
}


void Node::addNeighbor(int _neighbor) {
    neighbors.push_back(_neighbor);
}


void Node::visitNode() {
    isVisited = true;
}


void Node::resetVisitStatus() {
    isVisited = false;
}


bool Node::getVisitStatus() const {
    return isVisited;
}


bool Node::operator==(const Node &_node) const {
    return _node.getNodeId() == nodeId;
}


void addToVector(int idNodeA, int idNodeB, bool isTwoWay, std::vector<Node> &nodesVector) {
    nodesVector[idNodeA - 1].addNeighbor(idNodeB);

    if(isTwoWay) {
        addToVector(idNodeB, idNodeA, false, nodesVector);
    }
}


void DFS(std::vector<Node> &nodesVector, int rootId) {
    if(!nodesVector[rootId - 1].getVisitStatus()) {
        nodesVector[rootId - 1].visitNode();
    } else {
        return;
    }

    for(auto const& iterator : nodesVector[rootId - 1].neighbors) {
        DFS(nodesVector, iterator);
    }
}


bool checkConnectivity(std::vector<Node> nodesVector) {
    for(auto const& iterator : nodesVector) {
        if(!iterator.getVisitStatus()) { return false; }
    }

    return true;
}


int main() {
    int numNodes, numVertices;
    int idNodeA, idNodeB, unparsedIsTwoWay;
    int isConnected, nodeIterator;
    bool isTwoWay;
    std::vector<Node> nodesVector;
    std::vector<int> results;

    numNodes = -1;
    numVertices = -1;

    while (numNodes && numVertices) {
        isConnected = 1;

        std::cin >> numNodes >> numVertices;

        if(!numNodes || !numVertices)
            break;

        for(nodeIterator = 1; nodeIterator <= numNodes; nodeIterator++) {
            nodesVector.push_back(Node(nodeIterator));
        }

        for(nodeIterator = 0; nodeIterator < numVertices; nodeIterator++) {
            std::cin >> idNodeA >> idNodeB >> unparsedIsTwoWay;
            isTwoWay = unparsedIsTwoWay == 2;

            addToVector(idNodeA, idNodeB, isTwoWay, nodesVector);
        }

        for(nodeIterator = 1; nodeIterator <= numNodes; nodeIterator++) {
            DFS(nodesVector, nodeIterator);
            isConnected = checkConnectivity(nodesVector);

            if(!isConnected)
                break;

            for(int _nodeIterator = 0; _nodeIterator < numNodes; _nodeIterator++) {
                nodesVector[_nodeIterator].resetVisitStatus();
            }
        }

        results.push_back(isConnected);
        nodesVector.clear();
    }

    for(auto const& iterator : results) {
        std::cout << iterator << std::endl;
    }

    return 0;
}
