#include <EpisodeThree/Graphics/Renderer.hpp>
#include <EpisodeThree/Outatime.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>

Renderer::Renderer()
{
   m_fade.setShader("assets/shaders/renderer.fs");
}

void Renderer::triggerFade(Transition::FadeWay way, sf::Time duration)
{
   m_fade.reset(way, duration);
}

Transition const& Renderer::getFade() const
{
   return m_fade;
}

void Renderer::submit(sf::Drawable const& object)
{
   m_objects.push_back(&object);
}

void Renderer::update(sf::Time dt)
{
   m_fade.update(dt);
}

void Renderer::render()
{
   for (auto& object : m_objects)
      Outatime::Instance().getWindow().draw(*object, &m_fade.getShader());

   m_objects.clear();
}
