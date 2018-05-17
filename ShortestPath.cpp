/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: den
 *
 * Created on May 16, 2018, 8:18 AM
 */

#include "ShortestPath.h"

using namespace std;


    bool Position::operator!=(const Position &other) const {
        return (this->x != other.x && this->y != other.y);
    }
    bool Position::operator==(const Position &other) const {
        return (this->x == other.x && this->y == other.y);
    }
    bool Position::operator<(const Position& pos) const {
        if (this->y != pos.y) return this->y < pos.y;
        return this->x < pos.x;
    }
    Position& Position::operator=(const Position& other) {this->x = other.x; this->y = other.y; return *this;}


void a_star(Position source, Position destination, map<Position, map<Position, double> >& graph, map<Position, double>& min_distance, map<Position, Position>& previous)
{
    map<Position, double> heuristic_distance;
    min_distance.clear();
    previous.clear();
    for (auto it : graph) {
        min_distance[it.first] = INF;
        heuristic_distance[it.first] = sqrt(pow(destination.x - it.first.x, 2) + pow(destination.y - it.first.y, 2));
    }    
    min_distance[source] = 0;
    
    set<pair<double, Position> > queue;
    queue.insert(make_pair(min_distance[source], source));
    while (!queue.empty())
    {
        Position u = queue.begin()->second;
        int distance = queue.begin()->first;
        queue.erase(queue.begin());
        
        for (auto it : graph[u])
        {
            Position v = it.first;
            int dist_through_u = distance + it.second + heuristic_distance[v];
            
            if (dist_through_u < min_distance[v])
            {
                queue.erase(make_pair(min_distance[v], v));
                previous[v] = u;
                min_distance[v] = dist_through_u;
                queue.insert(make_pair(min_distance[v], v));
                if (v == destination) return;
            }
        
        }
    
    }
    
}

void dijkstra(Position from, std::map<Position, std::map<Position,int> >& graph, std::map<Position, Position>& previous)
{
    map<Position, int> min_distance;
    previous.clear();
    
    for (auto it : graph) {
        min_distance[it.first] = INF;
    }
    
    min_distance[from] = 0;
    
    set<std::pair<int, Position> > queue; 
    queue.insert(std::make_pair(min_distance[from], from));
    
    while(!queue.empty()) {
        int dist = queue.begin()->first;
        Position u = queue.begin()->second;
        queue.erase(queue.begin());
        
        for (auto it : graph[u])
        {
            int dist_through_u = dist + it.second;
            Position v = it.first;
            if (dist_through_u < min_distance[v])
            {
                queue.erase(std::make_pair(min_distance[v], v));
                
                previous[v] = u;
                min_distance[v] = dist_through_u;
                queue.insert(std::make_pair(min_distance[v], v));            
            }
            
        }
    }
}



void addEdges(bool arr[6][6], map<Position, map<Position, double> >& graph) {

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (arr[i][j] == true) {
                for (int k = i - 1; k < i + 2; ++k) {
                    for (int l = j - 1; l < j + 2; ++l) {
                        if (k < 0 || k >= 6 || l < 0 || l >= 6 || (k == i && l == j)) continue;
                        if (arr[k][l] == true) graph[{j, i}][{l, k}] = 1;
                    }
                }
            }
        }
    }
}


bool getShortestPath(map<Position, Position>& previous, Position source, Position dest, vector<Position>& shortestPath) {
    
    if (previous.find(dest) == previous.end()) return false;
    
    shortestPath.push_back(dest);
    
    while (true) {
        shortestPath.push_back(previous[shortestPath[shortestPath.size() - 1]]);
        if (shortestPath[shortestPath.size() - 1] == source) break;
    } 
    std::reverse(shortestPath.begin(), shortestPath.end());
}


void someTestFunction()
{
    bool **arr = new bool*[6];
    for (int i = 0; i < 6; ++i)
    {
        arr[i] = new bool[6];
    
    }
    
    bool arr2[6][6]{
        {true, false, false, true, false, true},
        {true, true, false, false, true, false},
        {true, false, true, true, false, false},
        {false, true, true, false, true, false},
        {false, false, true, false, false, true},
        {true, true, false, true, true, false}
    };
    
    for(int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
        {
            arr[i][j] = arr2[i][j];
        }
    
    map<Position, double> min_distance;
    map<Position, Position> previous;

    //map<Position, set<Position> > graph;
    //addEdges(arr, graph);
    
    map<Position, map<Position, double> > graph2;
    //addEdges(arr, graph2);
   
    fillGraph<double>(arr, 6, 6, graph2);
    a_star({0,0}, {5,4}, graph2, min_distance, previous);

    /*
    for (auto it : graph2)
    {
        cout << it.first;
        for (auto it2 : it.second)
            cout << it2.first;
        cout << endl;
    } */
    
    vector<Position> shortestPath;
    getShortestPath(previous, {0,0}, {5,4}, shortestPath);
    
    for (auto it : shortestPath)
    {
        cout << it;
    }
    
    for (int i = 0; i < 6; ++i)
        delete[] arr[i];
    delete[] arr;

};