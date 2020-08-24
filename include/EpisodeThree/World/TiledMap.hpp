#ifndef TILEDMAP_HPP
#define TILEDMAP_HPP

#include <tmxparser/Tmx.h>
#include <EpisodeThree/World/Tileset.hpp>

class TiledMap
{
public:

   TiledMap() = default;
   explicit TiledMap(std::string const& filePath);

   // TODO Use std::filesystem::path
   void load(std::string const& filePath);
   void render();
   inline Tmx::Map const& getMap() const { return m_map; }

private:

   Tmx::Map m_map;
   std::vector<Tileset> m_tilesets;
};

#endif // TILEDMAP_HPP
