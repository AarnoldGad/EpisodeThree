#ifndef PLAYSTATE_HPP
#define PLAYSTATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <EpisodeThree/State/State.hpp>
#include <EpisodeThree/World/TiledMap.hpp>

class PlayState : public State
{
public:

   PlayState(Outatime& game);

   void update(sf::Time dt) override;
   void onEvent(const sf::Event & event) override;
   void render(RenderMaster & master) override;

private:

};

#endif // PLAYSTATE_HPP
