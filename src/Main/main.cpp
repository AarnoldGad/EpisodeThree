#include <iostream>
#include <EpisodeThree/Outatime.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>
#include <EpisodeThree/State/PlayState.hpp>

// TODO Better resources init management
void initResources();

int main()
{
   initResources();
   Outatime::Instance().run<PlayState>();

   return 0;
}

void initResources()
{
   ResourcesManager::Instance().loadFromFile<sf::Texture>("sfml", "assets/sprites/sfml.png", sf::IntRect());
   ResourcesManager::Instance().loadFromFile<sf::Texture>("box2D", "assets/sprites/box2d.png", sf::IntRect());

   ResourcesManager::Instance().loadFromFile<sf::Texture>("ekgFlat", "assets/sprites/ekg_flat.png", sf::IntRect());
   ResourcesManager::Instance().loadFromFile<sf::Texture>("ekgStress", "assets/sprites/ekg_stress.png", sf::IntRect());

   ResourcesManager::Instance().loadFromFile<sf::Font>("font", "assets/fonts/SourceCodePro.otf");

   ResourcesManager::Instance().loadFromFile<sf::SoundBuffer>("ekg", "assets/sounds/ekg.ogg");
}
