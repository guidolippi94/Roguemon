#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"

int main()
{
    enum direction{Down, Left, Right, Up};
    sf::Vector2i source(1,Down);
    sf::Vector2i screenDimension(800, 600);
    sf::RenderWindow window(sf::VideoMode(screenDimension.x, screenDimension.y), "Roguemon");
    
    while(window.isOpen()){
        window.clear();
        sf::Event event;
        while(window.pollEvent(event)){
            
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
            
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    source.y=Up;
                    break;
                case sf::Keyboard::Down:
                    source.y=Down;
                    break;
                case sf::Keyboard::Left:
                    source.y=Left;
                    break;
                case sf::Keyboard::Right:
                    source.y=Right;
                    break;
                    
                default:
                    break;
            }
        }//pollevent
        window.display();
        window.clear();
    } //game loop
    
}

