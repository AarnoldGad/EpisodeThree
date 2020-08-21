#include <iostream>
#include <EpisodeThree/Outatime.hpp>
#include <EpisodeThree/State/FirstSceneState.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>

// TODO Better resources init management
void initResources();

int main()
{
   initResources();
   Outatime::Instance().run<FirstSceneState>();

   // 20 Aout
   // Tiles
   // Tile Maps / Implementation
   // Système dialogue

   // 21 Aout
   // Sprites
   // Animation
   //

   return 0;
}

void initResources()
{
   ResourcesManager::Instance().loadFromFile<sf::Texture>("sfml", "assets/sprites/sfml.png", sf::IntRect());
   ResourcesManager::Instance().loadFromFile<sf::Texture>("box2D", "assets/sprites/box2d.png", sf::IntRect());
   ResourcesManager::Instance().loadFromFile<sf::Font>("font", "assets/fonts/SourceCodePro.otf");
}
