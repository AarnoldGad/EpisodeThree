#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include <SFML/Graphics.hpp>

// TODO Technical Debt on way to fade : Maybe get back to good ol' black rectangle getting over the screen
class Transition
{
public:

   enum FadeWay : unsigned char { FADE_IN = 0, FADE_OUT };

   Transition() = default;
   Transition(FadeWay way, sf::Time duration, std::string const& shaderPath);

   void update(sf::Time dt);
   void reset(FadeWay way, sf::Time duration);
   void setShader(std::string const& shaderPath);
   inline sf::Shader const& getShader() const { return m_fade; }
   inline bool isDone() const { return m_elapsed >= m_duration; }

protected:

   FadeWay m_way;
   sf::Time m_duration;
   sf::Time m_elapsed;
   sf::Shader m_fade;
};

#endif // TRANSITION_HPP
