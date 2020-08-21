#ifndef OPENSTATE_HPP
#define OPENSTATE_HPP

#include <SFML/Graphics.hpp>
#include <EpisodeThree/State/State.hpp>
#include <EpisodeThree/Graphics/Transition.hpp>

// TODO Refactor, improve and add things to the screen
class OpenState : public State
{
public:

   explicit OpenState(Outatime& game);

   void update(sf::Time dt) override;
   void onEvent(sf::Event const& event) override;
   void render(RenderMaster& master) override;

private:

   sf::Sprite m_sfmlLogo;
   sf::Sprite m_box2DLogo;
   sf::Text m_studioName;

   sf::Time m_accumElapsed;
   bool m_fadeOutFlag;

   Renderer m_renderer;
};

#endif // OPENSTATE_HPP
