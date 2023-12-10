#include <algorithm>
#include <iostream>
#include <vector>


class City {
    private:
        int cityId;
        bool isVisited;
        std::vector<int> neighbors;

    public:
        City() = default;
        City(int);
        int getCityId() const;
        void visitCity();
        bool getVisitStatus() const;
        std::vector<int> getNeighbors() const;
        void addNeighbor(int);
        void printNode() const;
};


City::City(int _cityId) {
    cityId = _cityId;
    isVisited = false;
}


int City::getCityId() const {
    return cityId;
}


void City::visitCity() {
    isVisited = true;
}


bool City::getVisitStatus() const {
    return isVisited;
}


std::vector<int> City::getNeighbors() const {
    return neighbors;
}


void City::addNeighbor(int neighborId) {
    neighbors.push_back(neighborId);
}


void City::printNode() const {
    for(auto const& iterator : neighbors) {
        std::cout << iterator << " ";
    }
}


void DFS(std::vector<City> &nodesVector, int rootId, int &componentVertices) {
    if(!nodesVector[rootId - 1].getVisitStatus()) {
        nodesVector[rootId - 1].visitCity();
        componentVertices++;
    } else {
        return;
    }

    for(auto const& iterator : nodesVector[rootId - 1].getNeighbors()) {
        DFS(nodesVector, iterator, componentVertices);
    }
}


int main() {
    int testCases, idCityA, idCityB;
    float cityCount, roadCount, libCost, roadCost;
    long long totalCost;
    std::vector<City> cities;

    int iterator, componentVertices;

    std::cin >> testCases;

    while(testCases > 0) {
        testCases--;
        componentVertices = 0;
        totalCost = 0;
        cities.clear();

        std::cin >> cityCount >> roadCount >> libCost >> roadCost;

        for(iterator = 1; iterator <= cityCount; iterator++) {
            cities.push_back(City(iterator));
        }

        for(int i = 1; i <= roadCount; i++) {
            std::cin >> idCityA >> idCityB;

            // Estradas são de duas vias
            cities[idCityA - 1].addNeighbor(idCityB);
            cities[idCityB - 1].addNeighbor(idCityA);
        }

        // Caso 1: biblioteca é mais barata que estrada. Então, constrói uma
        // biblioteca em cada cidade.
        if(libCost <= roadCost) {
            totalCost = cityCount * libCost;
        }

        // Caso 2: estrada é mais barata que bibliotaca. Então, constrói uma
        // biblioteca por compontente conexo, e constrói todas as estradas.
        else {
            for(iterator = 1; iterator <= cityCount; iterator++) {
                if(!cities[iterator - 1].getVisitStatus()) {
                    componentVertices = 0;
                    DFS(cities, iterator, componentVertices);

                    totalCost += libCost + ((componentVertices - 1) * roadCost);
                }
            }
        }

        std::cout << totalCost << std::endl;
    }

    return 0;
}