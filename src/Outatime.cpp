#include <EpisodeThree/Outatime.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>
#include <EpisodeThree/Game/DataStore.hpp>

Outatime::Outatime()
: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "OUTATIME", sf::Style::Titlebar | sf::Style::Close), m_running(false), m_shouldPop(0)
{
   // Move window to the center of the screen
   #if defined(_DEBUG)
      // I have 2 monitors on a X server and SFML doesn't handle multiple monitors
      m_window.setPosition({2560 - (WINDOW_WIDTH / 2), 540 - (WINDOW_HEIGHT / 2)})
   #else
      sf::Vector2i desktopSize = {static_cast<int>(sf::VideoMode::getDesktopMode().width), static_cast<int>(sf::VideoMode::getDesktopMode().height)};
      m_window.setPosition({desktopSize.x - WINDOW_WIDTH) / 2, (desktopSize.y - WINDOW_HEIGHT) / 2});
   #endif

   m_window.setFramerateLimit(60);
}

void Outatime::mainGameLoop()
{
   sf::Event event;
   sf::Clock clock;

   while (m_running)
   {
      sf::Time deltaTime = clock.restart();

      ResourcesManager::Instance().update(deltaTime);
      updateStateStatus();
      auto& state = m_states.front();

      while (m_window.pollEvent(event))
      {
         if (event.type == sf::Event::Closed)
            stop();
         #if defined(_DEBUG)
            if (event.type == sf::Event::KeyPressed)
               if (event.key.code == sf::Keyboard::Escape)
                  stop();
         #endif

         state->onEvent(event);
      }

      state->update(deltaTime);

      m_window.clear();
      
      state->render(m_renderMaster);
      m_renderMaster.render();
      
      m_window.display();
   }
}

void Outatime::popState()

   if (++m_shouldPop >= m_states.size())
      m_shouldPop = m_states.size() ? m_states.size() - 1 : 0;
}

void Outatime::updateStateStatus()
{
   for (; m_shouldPop > 0; --m_shouldPop)
      m_states.pop();
}

void Outatime::stop()
{
   m_running = false;
}
