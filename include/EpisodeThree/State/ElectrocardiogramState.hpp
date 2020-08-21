#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP

#include <EpisodeThree/Graphics/Renderer.hpp>
#include <EpisodeThree/State/State.hpp>
#include <EpisodeThree/Outatime.hpp>

class ElectrocardiogramState : public State
{
public:

   explicit ElectrocardiogramState(Outatime& game, float hbpm);

   void update(sf::Time dt) override;
   void render(RenderMaster & master) override;

   void setHeartBeatPerMinute(float hbpm);
   inline float getHeartBeatPerMinute() const { return m_hbpm; }

private:

   sf::Sprite m_ecFlat;
   sf::Sprite m_ecStress;

   sf::Time m_accumTime;
   float m_hbpm;

   Renderer m_renderer;
};

#endif // INTROSTATE_HPP
