#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>
#include <EpisodeThree/Graphics/RenderMaster.hpp>

class Outatime;

class State
{
public:

   explicit State(Outatime& game) : m_game(game) {}
   virtual ~State() {}

   virtual void update(sf::Time dt) = 0;
   virtual void onEvent(sf::Event const& event) = 0;
   virtual void render(RenderMaster& master) = 0;

protected:

   Outatime& m_game;
};

#endif // STATE_HPP
