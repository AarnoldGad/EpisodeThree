#include <EpisodeThree/Graphics/RenderMaster.hpp>

void RenderMaster::submit(unsigned int weight, Renderer& renderer)
{
   m_renderers.try_emplace(weight);
   m_renderers.at(weight).push_back(&renderer);
}

void RenderMaster::render()
{
   for (auto& it : m_renderers)
      for (auto& object : it.second)
         object->render();

   m_renderers.clear();
}
