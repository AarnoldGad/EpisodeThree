#include <EpisodeThree/State/ElectrocardiogramState.hpp>
#include <EpisodeThree/Core/ResourcesManager.hpp>

ElectrocardiogramState::ElectrocardiogramState(Outatime& game, float hbpm)
   : State(game), m_hbpm(hbpm)
{
   m_ecFlat.setTexture(ResourcesManager::Instance().get<sf::Texture>("ekgFlat"));
   m_ecFlat.setPosition({0, 0});

   m_ecStress.setTexture(ResourcesManager::Instance().get<sf::Texture>("ekgStress"));
   m_ecStress.setPosition({0, 0});

   m_ekg.setBuffer(ResourcesManager::Instance().get<sf::SoundBuffer>("ekg"));
}

ElectrocardiogramState::~ElectrocardiogramState()
{
   m_ekg.stop();
}


void ElectrocardiogramState::update(sf::Time dt)
{
   m_accumTime += dt;

   if (m_accumTime.asSeconds() >= (60.f / m_hbpm))
   {
      m_accumTime = sf::Time::Zero;
      m_ekg.play();
   }

   sf::Color color = m_ecStress.getColor();
   float alphaFactor = 255.f * (1.f - (m_accumTime.asSeconds() / (60.f / m_hbpm)));
   m_ecStress.setColor({color.r, color.g, color.b, static_cast<sf::Uint8>(alphaFactor)});
}

void ElectrocardiogramState::render(RenderMaster& master)
{
   m_renderer.submit(m_ecStress);
   m_renderer.submit(m_ecFlat);
   master.submit(0, m_renderer);
}

void ElectrocardiogramState::setHeartBeatPerMinute(float hbpm)
{
   m_hbpm = hbpm;
}
