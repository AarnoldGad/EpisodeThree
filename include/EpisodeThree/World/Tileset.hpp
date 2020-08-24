#ifndef TILESET_HPP
#define TILESET_HPP

#include <tmxparser/Tmx.h>
#include <SFML/Graphics.hpp>

class Tileset
{
public:

   Tileset(Tmx::Tileset const& tileset);
   sf::Texture const& getTexture() const;
   sf::IntRect getTileRect(size_t index) const;

private:

   Tmx::Tileset m_tileset;
   sf::Texture m_tilesetTexture;
   // TODO Animation
};

#endif // TILESET_HPP
