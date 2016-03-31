

#include "Map.hpp"





void Map::loadMap(){
    

    std::ifstream openfile(("Map.txt"));

    sf::Texture tileTexture;
    sf::Sprite tiles;

    sf::Vector2i map[100] [100];
    sf::Vector2i loadCounter = sf::Vector2i(0 , 0);



    if (openfile.is_open()) {
    
        std::string tileLocation;
        openfile >> tileLocation;
    
        tileTexture.loadFromFile(tileLocation);
        tiles.setTexture(tileTexture);
    
        while(!openfile.eof()){
        
            std::string str;
            openfile >> str;
            char x = str[0], y = str[2];
        
            if (!isdigit(x) || !isdigit(y) ) {  //isdigit controlla se in x,y c'è un numero decimale
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);  //se in uno dei due non cè ci mette -1,-1 per non dare noia
            }
            else{
                map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');   //altrimenti ci mette x - 0 cioè un int facendo la convers da char
            }
            if (openfile.peek() == '\n') { //peek checks for the next character, per andare a capo o scorrere le riga di maps.txt
                loadCounter.x = 0;
                loadCounter.y++;
            }
            else{
                loadCounter.x++;
            }
        
        }
        loadCounter.y++;
    }



    for (int i = 0; i < loadCounter.x; i++) {
        for (int j = 0; j<loadCounter.y; j++) {
        
            if (map[i][j].x != -1 && map[i][j].y != -1) {
                tiles.setPosition(i*35.5, j*35.5); //sarebbero 71*71 ma le riduco in scala di metà!!
            
                tiles.setTextureRect(sf::IntRect(map[i][j].x*71 , map[i][j].y*71, 71 , 71 ));
                tiles.setScale(0.5, 0.5); //scala
            
                window.draw(tiles);
            
            }
        }
    }
}
