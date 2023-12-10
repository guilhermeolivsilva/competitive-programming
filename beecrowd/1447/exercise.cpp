#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

long long numCities, numRoutes, cityA, cityB, totalFriends, flightCost, seatsPerFlight;
long long flightCapacity[101][101], minimumDistancesToRoot[101], parents[101];
long long totalCost;
std::vector<std::pair<long long, long long>> flights[101];
std::priority_queue<
    std::pair<long long, long long>,
    std::vector<std::pair<long long, long long>>,
    std::greater<std::pair<long long, long long>> > priorityQueue;


void reset() {
    totalCost = 0;

    for(long long currentCity = 0; currentCity < 101; currentCity++) {
        flights[currentCity].clear();
        for(long long nextCity = 0; nextCity < 101; nextCity++) {
            flightCapacity[currentCity][nextCity] = 0;
        }
    }
}


void initSingleSource() {
    priorityQueue = std::priority_queue<
        std::pair<long long, long long>,
        std::vector<std::pair<long long, long long>>,
        std::greater<std::pair<long long, long long>> >();
    for(long long i = 0; i < 101; i++) {
        minimumDistancesToRoot[i] = LLONG_MAX;
        parents[i] = -1;
    }
    minimumDistancesToRoot[1] = 0;
}


void relax(long long currentDistance, long long currentFlightCost, long long neighborId, long long currentCityId) {
    bool flightHasCapacity = flightCapacity[currentCityId][neighborId] > 0;
    bool distanceIsShorter = currentDistance + currentFlightCost < minimumDistancesToRoot[neighborId];

    if(flightHasCapacity && distanceIsShorter) {
        parents[neighborId] = currentCityId;
        minimumDistancesToRoot[neighborId] = currentDistance + currentFlightCost;
        priorityQueue.push(std::make_pair(minimumDistancesToRoot[neighborId], neighborId));
    }
}


long long getMinimumFlow(std::vector<long long> shortestPath) {
    long long minimumFlow = totalFriends;
    for(long long currentCityDistanceToRoot = 0; currentCityDistanceToRoot < shortestPath.size() - 1; currentCityDistanceToRoot++) {
        long long _currentCityDistanceToRoot = shortestPath[currentCityDistanceToRoot];
        long long _nextCityDistanceToRoot = shortestPath[currentCityDistanceToRoot + 1];
        minimumFlow = std::min(minimumFlow, flightCapacity[_currentCityDistanceToRoot][_nextCityDistanceToRoot]);
    }

    return minimumFlow;
}


bool dijkstra() {
    long long currentDistance, currentCityId, neighbor, neighborId, currentFlightCost;
    long long friendsThatTraveled, currentCityDistanceToRoot;
    long long _idxShortestPath, _idxNextShortestPath;
    bool inverseRoute;
    std::pair<long long, long long> currentCity;
    std::vector<long long> shortestPath;

    initSingleSource();
    priorityQueue.push(std::make_pair(0, 1));
    currentCityId = -1;

    while(!priorityQueue.empty() && currentCityId != numCities) {
        currentCity = priorityQueue.top();
        priorityQueue.pop();

        currentDistance = currentCity.first;
        currentCityId = currentCity.second;

        if(currentDistance <= minimumDistancesToRoot[currentCityId]) {
            for(neighbor = 0; neighbor < flights[currentCityId].size(); neighbor++) {
                neighborId = flights[currentCityId][neighbor].first;
                currentFlightCost = flights[currentCityId][neighbor].second;

                inverseRoute = flightCapacity[neighborId][currentCityId] < seatsPerFlight;
                if(inverseRoute) currentFlightCost *= -1;

                relax(currentDistance, currentFlightCost, neighborId, currentCityId);
            }
        }
    }

    if(minimumDistancesToRoot[numCities] == LLONG_MAX) return false;

    shortestPath.push_back(numCities);
    currentCityId = numCities;
    while(currentCityId != 1) {
        shortestPath.push_back(parents[currentCityId]);
        currentCityId = parents[currentCityId];
    }
    reverse(shortestPath.begin(), shortestPath.end());
    
    friendsThatTraveled = getMinimumFlow(shortestPath);
    totalFriends -= friendsThatTraveled;

    for(currentCityDistanceToRoot = 0; currentCityDistanceToRoot < shortestPath.size() - 1; currentCityDistanceToRoot++) {
        _idxShortestPath = shortestPath[currentCityDistanceToRoot];
        _idxNextShortestPath = shortestPath[currentCityDistanceToRoot + 1];
        
        flightCapacity[_idxShortestPath][_idxNextShortestPath] -= friendsThatTraveled;
        flightCapacity[_idxNextShortestPath][_idxShortestPath] += friendsThatTraveled;
    }

    return true;
}


long long getTotalCost() {
    long long distanceToRoot;

    while(dijkstra()) {
        if(totalFriends <= 0) break;
    }
    for(long long currentCity = 1; currentCity <= numCities; currentCity++) {
        for(long long nextCity = 0; nextCity < flights[currentCity].size(); nextCity++) {
            long long currentCityId = flights[currentCity][nextCity].first;

            if(flightCapacity[currentCity][currentCityId] < seatsPerFlight) {
                distanceToRoot = flights[currentCity][nextCity].second;
                totalCost += (seatsPerFlight - flightCapacity[currentCity][currentCityId]) * distanceToRoot;
            }
        }
    }

    return totalCost;
}


int main() {
    long long currentTestCase = 1;

    while(std::cin >> numCities >> numRoutes) {
        reset();

        for(long long currentFlight = 0; currentFlight < numRoutes; currentFlight++) {
            std::cin >> cityA >> cityB >> flightCost;
            flights[cityA].push_back(std::make_pair(cityB, flightCost));
            flights[cityB].push_back(std::make_pair(cityA, flightCost));
        }

        std::cin >> totalFriends >> seatsPerFlight;
        for(long long currentCity = 1; currentCity <= numCities; currentCity++) {
            for(long long nextCity = 1; nextCity <= numCities; nextCity++) {
                flightCapacity[currentCity][nextCity] = seatsPerFlight;
            }
        }

        totalCost = getTotalCost();

        std::cout << "Instancia " << currentTestCase << std::endl;

        if(totalFriends == 0) {
            std::cout << totalCost << std::endl << std::endl;
        } else {
            std::cout << "impossivel" << std::endl << std::endl;
        }

        currentTestCase++;
    }
    return 0;
}