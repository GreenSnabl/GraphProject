/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "ShortestPath.h"
#include "GraphicalGraph.h"


using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {

    bool **arr = new bool*[8];
    for (int i = 0; i < 8; ++i)
    {
        arr[i] = new bool[8];
    
    }
    
    bool arr2[8][8]{
        {false, false, true, false, false, false, false, false},
        {false, true, false, true, false, false, false, false},
        {false, false, true, true, true, false, false, false},
        {false, true, true, false, true, false, false, false},
        {false, true, false, false, true, false, false, false},
        {false, true, true, false, true, false, false, false},
        {false, false, false, true, true, false, false, false},
        {false, false, false, false, true, false, false, false}
    };
    
    for(int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
        {
            arr[i][j] = arr2[i][j];
        }
    
    
    GraphicalGraph gr(arr, 8, 8);
    
    //map<Position, map<Position, double> > graph;
    //fillGraph<double>(arr, 6, 6, graph);
    
    /*
    sf::Vertex line[] =
{
    sf::Vertex(sf::Vector2f(10, 10)),
    sf::Vertex(sf::Vector2f(150, 150))
};
    
        window.draw(line, 2, sf::Lines);
    */
    
    sf::RenderWindow window(sf::VideoMode(600, 400), "Graph");
    
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
        
            if (event.type == sf::Event::Closed)
                window.close();
        
        }
           
        
        gr.draw(window);
        window.display();
    }
    
    
    
    
    return 0;
}