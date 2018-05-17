/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphicalGraph.cpp
 * Author: den
 * 
 * Created on May 17, 2018, 9:38 AM
 */

#include "GraphicalGraph.h"

GraphicalGraph::GraphicalGraph() {
}

GraphicalGraph::GraphicalGraph(const GraphicalGraph& orig) {
}

GraphicalGraph::~GraphicalGraph() {
}



void GraphicalGraph::draw(sf::RenderWindow& window) {
    m_nodeShape.setRadius(m_tileSize / 3);
    m_nodeShape.setFillColor(sf::Color::Cyan);


    for (auto it : m_graph) {
        m_nodeShape.setPosition(it.first.x * m_tileSize, it.first.y * m_tileSize);
        window.draw(m_nodeShape);
        for (auto it2 : it.second)
        {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(it.first.x * m_tileSize + 10, it.first.y * m_tileSize + 10)),
                           sf::Vertex(sf::Vector2f(it2.first.x * m_tileSize + 10, it2.first.y * m_tileSize +10))
                           };
            line->color = sf::Color::Red;
            window.draw(line, 2, sf::Lines);
        }
        
    }
}