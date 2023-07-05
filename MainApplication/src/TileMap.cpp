#include "TileMap.hpp"


TileMap::TileMap(const Board& board, const std::string& tilesetFileName, sf::Vector2u tileSize) : m_tiles(board), m_tileSize(tileSize)
{
    if (!m_tileset.loadFromFile(tilesetFileName))
        throw std::string("Couldn't read the file!");
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(size_t(m_tiles.getWidth()) * m_tiles.getHeight() * 4);
    initializeQuadPositions();
}

TileMap::TileMap(const Board& board, const unsigned char* tilesetArray, sf::Vector2u tilesetArraySize, sf::Vector2u tileSize) : m_tiles(board), m_tileSize(tileSize)
{
    sf::Image img;
    img.create(tilesetArraySize.x, tilesetArraySize.y, tilesetArray);
    if (!m_tileset.loadFromImage(img))
        throw std::string("Couldn't read the array!");
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(size_t(m_tiles.getWidth()) * m_tiles.getHeight() * 4);
    initializeQuadPositions();
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &m_tileset;
    target.draw(m_vertices, states);
}

void TileMap::updateQuads()
{
     sf::Vertex* quadPtr = nullptr;
     unsigned int tileNumber, tileNumberX, tileNumberY;

     for (unsigned int i = 0; i < m_tiles.getWidth(); ++i)
         for (unsigned int j = 0; j < m_tiles.getHeight(); ++j)
         {
             tileNumber = m_tiles[i + j * size_t(m_tiles.getWidth())]; // check which at givem position

             tileNumberX = tileNumber % (m_tileset.getSize().x / m_tileSize.x); 
             tileNumberY = tileNumber / (m_tileset.getSize().x / m_tileSize.x);

             quadPtr = &m_vertices[(i + j * size_t(m_tiles.getWidth())) * 4];

             quadPtr[0].texCoords = sf::Vector2f(float(tileNumberX) * m_tileSize.x, float(tileNumberY) * m_tileSize.y);
             quadPtr[1].texCoords = sf::Vector2f((float(tileNumberX) + 1) * m_tileSize.x, float(tileNumberY) * m_tileSize.y);
             quadPtr[2].texCoords = sf::Vector2f((float(tileNumberX) + 1) * m_tileSize.x, (float(tileNumberY) + 1) * m_tileSize.y);
             quadPtr[3].texCoords = sf::Vector2f(float(tileNumberX) * m_tileSize.x, (float(tileNumberY) + 1) * m_tileSize.y);
         }
}

void TileMap::initializeQuadPositions()
{
    sf::Vertex* quadPtr = nullptr;
    for (unsigned int i = 0; i < m_tiles.getWidth(); ++i)
        for (unsigned int j = 0; j < m_tiles.getHeight(); ++j)
        {
            quadPtr = &m_vertices[(i + j * size_t(m_tiles.getWidth())) * 4];
            
            quadPtr[0].position = sf::Vector2f(float(i) * m_tileSize.x, float(j) * m_tileSize.y);
            quadPtr[1].position = sf::Vector2f((float(i) + 1) * m_tileSize.x, float(j) * m_tileSize.y);
            quadPtr[2].position = sf::Vector2f((float(i) + 1) * m_tileSize.x, (float(j) + 1) * m_tileSize.y);
            quadPtr[3].position = sf::Vector2f(float(i) * m_tileSize.x, (float(j) + 1) * m_tileSize.y);
        }
}