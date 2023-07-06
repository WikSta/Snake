#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    TileMap(const Board& board, const std::string& tilesetFileName, sf::Vector2u tileSize);
    TileMap(const Board& board, const unsigned char* tilesetArray, sf::Vector2u tilesetArraySize, sf::Vector2u tileSize);
    void updateQuads();
private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    const Board& m_tiles;
    sf::Vector2u m_tileSize;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void initializeQuadPositions();
};

#endif