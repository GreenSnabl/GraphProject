/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphicalGraph.h
 * Author: den
 *
 * Created on May 17, 2018, 9:38 AM
 */

#ifndef GRAPHICALGRAPH_H
#define GRAPHICALGRAPH_H
#include <SFML/Graphics.hpp>
#include <map>
#include "ShortestPath.h"

/*
sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(10, 10)),
    sf::Vertex(sf::Vector2f(150, 150))
};

window.draw(line, 2, sf::Lines);
*/

class GraphicalGraph {
public:
    GraphicalGraph();
    GraphicalGraph(bool **arr, int height, int width) : m_height{height},  m_width{width}, m_tileSize{30}, m_circleOffset{15} 
    { 
        
        
        fillGraph<double>(arr, m_height, m_width, m_graph);
    }
    ~GraphicalGraph();
    void draw(sf::RenderWindow& window);
private:
    map<Position, map<Position, double> > m_graph;
    sf::CircleShape m_nodeShape;
    sf::Sprite m_backGround;
    
    int m_circleOffset;
    int m_tileSize;
    int m_height;
    int m_width;
    
    GraphicalGraph(const GraphicalGraph& orig);
};

#endif /* GRAPHICALGRAPH_H */

