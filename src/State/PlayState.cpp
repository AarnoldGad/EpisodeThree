#include <EpisodeThree/State/PlayState.hpp>
#include <EpisodeThree/Outatime.hpp>

PlayState::PlayState(Outatime& game)
   : State(game)
{
   TiledMap map("assets/maps/hospital_1.tmx");
}


void PlayState::update(sf::Time dt)
{

}

void PlayState::onEvent(const sf::Event& event)
{

}

void PlayState::render(RenderMaster& master)
{

}


