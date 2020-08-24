#include <EpisodeThree/World/TiledMap.hpp>
#include <iostream>

TiledMap::TiledMap(std::string const& filePath)
{
   load(filePath);
}

void TiledMap::load(std::string const& filePath)
{
   m_map.ParseFile(filePath);

   if (m_map.HasError())
   {
      // TODO Error handling
      std::cout << "tmx loading exception : code " << +m_map.GetErrorCode() << " - " << m_map.GetErrorText() << std::endl;
      exit(-1);
   }

   std::cout << "loading map " << filePath << std::endl;
   std::cout << "tmx version " << m_map.GetVersion() << std::endl;

   for (auto& it : m_map.GetTilesets())
      m_tilesets.push_back(Tileset(*it));


}

void TiledMap::render()
{

}


