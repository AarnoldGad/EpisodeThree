#ifndef RENDERMASTER_HPP
#define RENDERMASTER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <EpisodeThree/Graphics/Renderer.hpp>

class RenderMaster
{
public:

   RenderMaster() = default;

   void submit(unsigned int weight, Renderer& renderer);
   void render();

private:

   std::map<unsigned int, std::vector<Renderer*> > m_renderers;
};

#endif // RENDERMASTER_HPP
