#include <EpisodeThree/Graphics/Transition.hpp>
#include <algorithm>
#include <iostream>

Transition::Transition(FadeWay way, sf::Time duration, std::string const& shaderPath)
   : m_way(way), m_duration(duration)
{
   setShader(shaderPath);
}

void Transition::update(sf::Time dt)
{
   m_elapsed += dt;

   if (m_elapsed > m_duration)
      m_elapsed = m_duration;

   m_fade.setUniform("way", m_way);
   m_fade.setUniform("elapsed", m_elapsed.asSeconds());
   m_fade.setUniform("duration", m_duration.asSeconds());
}

void Transition::reset(FadeWay way, sf::Time duration)
{
   m_way = way;
   m_elapsed = sf::Time::Zero;
   m_duration = duration;
}

void Transition::setShader(const std::string& shaderPath)
{
   if (!m_fade.loadFromFile(shaderPath, sf::Shader::Fragment))
   {
      std::cout << "fade shader load error : " << shaderPath << std::endl;
      exit(-1);
   }
}
