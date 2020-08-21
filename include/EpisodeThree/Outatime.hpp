#ifndef OUTATIME_HPP
#define OUTATIME_HPP

#include <memory>
#include <queue>
#include <SFML/Graphics.hpp>

#include <EpisodeThree/Core/Singleton.hpp>
#include <EpisodeThree/State/State.hpp>
#include <EpisodeThree/Graphics/RenderMaster.hpp>

class Outatime : public Singleton<Outatime>
{
   friend class Singleton<Outatime>;

public:

   template<typename StateType, typename... Args>
   void run(Args&&... args);
   void stop();

   template<typename StateType, typename... Args>
   void pushState(Args&&... args);
   void popState();

   template<typename StateType, typename... Args>
   void setState(Args&&... args); // Convenience, pushing new state and popping previous
   
   inline sf::RenderWindow& getWindow() { return m_window; }

private:

   Outatime();

   void mainGameLoop();
   void updateStateStatus();

   sf::RenderWindow m_window;
   bool m_running;

   std::queue<std::unique_ptr<State>> m_states;
   size_t m_shouldPop;

   RenderMaster m_renderMaster;
};

#include "Outatime.inl"

#endif // OUTATIME_HPP
