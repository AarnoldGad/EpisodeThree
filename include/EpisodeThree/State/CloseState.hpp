#ifndef CLOSESTATE_HPP
#define CLOSESTATE_HPP

#include <EpisodeThree/State/State.hpp>
#include <EpisodeThree/Graphics/Transition.hpp>

class CloseState : public State
{
public:

   explicit CloseState(Outatime& game);

   void update(sf::Time dt) override;
   void onEvent(const sf::Event & event) override;
   void render(RenderMaster & master) override;

private:


};

#endif // CLOSESTATE_HPP
