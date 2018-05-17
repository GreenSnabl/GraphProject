/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   A_star.h
 * Author: den
 *
 * Created on May 17, 2018, 8:14 AM
 */

#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <limits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int INF = std::numeric_limits<double>::max();

struct Position {
    bool operator!=(const Position &other) const;
    bool operator==(const Position &other) const;
    bool operator<(const Position& pos) const;

    friend ostream& operator<<(ostream& os, const Position& pos) {
        os << "{" << pos.x << "," << pos.y << "}";
    }
    
    Position& operator=(const Position& other);
    
    int x;
    int y;

};


template<typename T>
void fillGraph(bool** arr, int height, int width, std::map<Position, std::map<Position, T> >& graph) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (arr[i][j]) {

                for (int k = i - 1; k < i + 2; ++k) {
                    for (int l = j - 1; l < j + 2; ++l) {
                        if (k < 0 || k >= height || l < 0 || l >= width || (k == i && l == j)) continue;
                        if (arr[k][l]) graph[{j, i}][{l, k}] = 1;
                    }
                }
            }
        }
    }
}




void a_star(Position source, Position destination, map<Position, map<Position, double> >& graph, map<Position, double>& min_distance, map<Position, Position>& previous);
void dijkstra(Position from, std::map<Position, std::map<Position, int> >& graph, std::map<Position, Position>& previous);
void addEdges(bool arr[6][6], map<Position, map<Position, double> >& graph);
bool getShortestPath(map<Position, Position>& previous, Position source, Position dest, vector<Position>& shortestPath);

void someTestFunction();

#endif /* SHORTESTPATH_H */

