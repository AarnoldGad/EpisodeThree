#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <deque>
#include <SFML/Graphics.hpp>
#include <EpisodeThree/Graphics/Transition.hpp>

class Renderer
{
public:

   Renderer();

   void triggerFade(Transition::FadeWay way, sf::Time duration);
   Transition const& getFade() const;

   void submit(sf::Drawable const& object);
   void update(sf::Time dt);
   void render();

protected:

   Transition m_fade;
   sf::RenderStates m_states;
   std::deque<sf::Drawable const*> m_objects;
};

#endif // RENDERER_HPP
